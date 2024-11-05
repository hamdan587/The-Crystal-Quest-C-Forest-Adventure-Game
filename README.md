                                            # 🌟 The Quest for the Crystal Kingdom 🌟

The Quest for the Crystal Kingdom is an interactive project designed to showcase data structures and shortest-path algorithms within a game-like environment. Use different algorithms to find the best path on a grid full of unique nodes—each with its own properties and challenges—demonstrating practical applications of graph traversal and pathfinding in a visually engaging way.

---

## 📜 Table of Contents

1. [Introduction](#introduction)
2. [Map Symbols](#map-symbols)
3. [How to Play](#how-to-play)
4. [Algorithm Options](#algorithm-options)
5. [Learn and Explore](#learn-and-explore)

---

## 🎮 Introduction

This project uses a fantasy-themed map to demonstrate data structures and graph algorithms, focusing on shortest-path and minimum spanning tree algorithms. Each algorithm option shows how pathfinding handles different nodes with rewards, obstacles, and enemies. Select an algorithm to see its logic in action, taking you step-by-step from the starting point to the goal (the crystal) while calculating your score based on encounters along the path.

---

### 🗺️ Map Symbols

| Symbol | Entity       | Description                                       |
|--------|--------------|---------------------------------------------------|
| `C`    | Clear Path   | A safe node to travel through.                   |
| `J`    | Jewel        | Adds +50 to your score.                          |
| `P`    | Potion       | Adds +70 to your score.                          |
| `W`    | Weapon       | Adds +30 to your score.                          |
| `%`    | Death Point  | Ends the game instantly.                         |
| `#`    | Obstacle     | High-cost node; choose another route.            |
| `&`    | Dragon       | Removes a jewel from your score.                 |
| `$`    | Goblin       | Removes a potion from your score.                |
| `@`    | Werewolf     | Removes a weapon from your score.                |
| `*`    | Crystal      | The goal of the game.                            |

---

## 📖 How to Play

1. Select an Algorithm from the menu options upon starting the game.
2. The chosen algorithm will automatically compute the shortest path from the starting point to the crystal, factoring in node types, obstacles, and enemies along the way.
3. The program will display:
   - The steps taken by the algorithm
   - The calculated path to the crystal
   - The final score based on collected rewards and any penalties from enemy encounters

---

## 🧭 Algorithm Options

Select one of the following pathfinding algorithms to navigate the map:

- **Floyd's Algorithm**: Computes the shortest path from the starting point (0,0) to the crystal by evaluating all possible paths in the grid.
- **Floyd's Algorithm (Custom Start)**: Computes the shortest path from a user-specified starting point.
- **Dijkstra's Algorithm**: Finds the most efficient path from (0,0) to the crystal, considering path weights.
- **Dijkstra's Algorithm (Custom Start)**: Similar to Dijkstra's standard option, but allows for a custom starting position.
- **Prim's Algorithm**: Constructs a Minimum Spanning Tree (MST) of the map, highlighting connections but not necessarily the shortest path.
- **Kruskal's Algorithm**: Another MST approach, focusing on minimal edge weight connections across the map.

> **Note:** This project emphasizes understanding and observing how different algorithms handle pathfinding in a weighted grid. The automatic scoring and path display provide insight into each algorithm's efficiency.

---

## 🌌 Learn and Explore

Explore core concepts in data structures and algorithms through practical demonstration, including:

- **Shortest Path Algorithms**: Experience how Dijkstra’s and Floyd’s algorithms compute efficient routes.
- **Minimum Spanning Trees**: See how Prim’s and Kruskal’s algorithms optimize network connectivity.
- **Graph Theory**: Understand graph traversal and the importance of weighted paths, obstacles, and more.

---

🚀 Embark on this quest to deepen your understanding of data structures, shortest path algorithms, and graph theory!
