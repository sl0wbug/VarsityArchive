#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int vertices, edges;

    cout << "Enter number of vertices: ";
    cin >> vertices;
    cout << "Enter number of edges: ";
    cin >> edges;

    vector<vector<int>> adjList(vertices);

    cout << "Enter edges (format: u v means edge from u to v):\n";
    for (int i = 0; i < edges; ++i)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);//dynamically add elements 
        adjList[v].push_back(u);//from u to v and v to u at once, 
    }
    cout << "\nAdjacency List:\n";
    for (int i = 0; i < vertices; ++i)
    {
        cout << i << ": ";
        for (int j = 0; j < adjList[i].size(); ++j)//similar to std::adjList funtion 
        {
            cout << adjList[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
