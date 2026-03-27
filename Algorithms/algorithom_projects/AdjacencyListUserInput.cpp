#include <iostream>
#include <vector>
#include <stdexcept>

class AdjacencyList {
public:
    explicit AdjacencyList(int vertices) : adjacencyList(vertices) {}

    void addEdge(int vertex1, int vertex2) {
        validateVertex(vertex1);
        validateVertex(vertex2);
        adjacencyList[vertex1].push_back(vertex2);
        adjacencyList[vertex2].push_back(vertex1);  // Assuming undirected graph
    }

    void printGraph() const {
        for (size_t i = 0; i < adjacencyList.size(); ++i) {
            std::cout << "Vertex " << i << " connects to:";
            for (const auto &vertex : adjacencyList[i]) {
                std::cout << " " << vertex;
            }
            std::cout << std::endl;
        }
    }

private:
    std::vector<std::vector<int>> adjacencyList;

    void validateVertex(int vertex) const {
        if (vertex < 0 || vertex >= adjacencyList.size()) {
            throw std::out_of_range("Vertex out of range");
        }
    }
};

int main() {
    int numberOfVertices;
    std::cout << "Enter the number of vertices: ";
    while (!(std::cin >> numberOfVertices) || numberOfVertices <= 0) {
        std::cin.clear(); // Clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the bad input
        std::cout << "Invalid input. Please enter a positive integer: ";
    }

    AdjacencyList graph(numberOfVertices);
    int vertex1, vertex2;

    std::cout << "Enter edges in the format 'vertex1 vertex2' (type -1 -1 to stop):\n";
    while (true) {
        std::cin >> vertex1 >> vertex2;
        if (vertex1 == -1 && vertex2 == -1) break;
        try {
            graph.addEdge(vertex1, vertex2);
        } catch (const std::out_of_range &e) {
            std::cout << e.what() << '\n';
        }
    }

    graph.printGraph();
    return 0;
}