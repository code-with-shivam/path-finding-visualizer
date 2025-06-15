# Dijkstra Console Visualizer

This is a simple console-based visualizer for Dijkstra's shortest path algorithm written in C++. It simulates pathfinding on a 2D grid using ASCII characters.

### 🧠 Algorithm Used

- **Dijkstra's Algorithm**: Finds the shortest path from a start cell to an end cell in a grid, avoiding walls (obstacles).
- Uses a **priority queue** to ensure optimal traversal based on distance.

---

### 🖥️ Grid Representation

Each cell in the grid is represented by a character:

| Symbol | Meaning        |
|--------|----------------|
| `S`    | Start point     |
| `E`    | End/Goal point  |
| `.`    | Empty space     |
| `#`    | Wall/Obstacle   |
| `v`    | Visited cell    |
| `*`    | Shortest path   |

---

### 📌 Features
 - Visualizes the pathfinding process step-by-step.

- ASCII-based drawing for platform independence.

- Easy to modify walls, start, and end points manually.

### ⚙️ How to Run

1. Make sure you have `g++` installed.
2. Compile the program:

```bash
g++ main.cpp -o app
app.exe


# 🙋‍♂️ Author
Made by Shivam Shukla.
Inspired by classic pathfinding visualizations.
