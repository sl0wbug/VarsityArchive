// Tabs
function showTab(tab) {
  document.querySelectorAll('.tab').forEach(t => t.classList.remove('active'));
  document.getElementById(tab).classList.add('active');
}

// TIMER
let time = 25 * 60;
let interval = null;

function updateDisplay() {
  let m = Math.floor(time / 60);
  let s = time % 60;
  document.getElementById("timer").innerText =
    `${m}:${s.toString().padStart(2, '0')}`;
}

function startTimer() {
  if (interval) return;
  interval = setInterval(() => {
    if (time > 0) {
      time--;
      updateDisplay();
    } else {
      clearInterval(interval);
      interval = null;
      alert("Session complete!");
    }
  }, 1000);
}

function resetTimer() {
  clearInterval(interval);
  interval = null;
  time = 25 * 60;
  updateDisplay();
}

updateDisplay();

// TASKS
function addTask() {
  const input = document.getElementById("taskInput");
  if (!input.value) return;

  const li = document.createElement("li");
  li.innerHTML = `${input.value} <button onclick="this.parentElement.remove()">❌</button>`;

  document.getElementById("taskList").appendChild(li);
  input.value = "";
}

// NOTES (auto-save)
const notes = document.getElementById("notes");

notes.value = localStorage.getItem("notes") || "";

notes.addEventListener("input", () => {
  localStorage.setItem("notes", notes.value);
});