# 🔲 Matrix Algorithms Guide

2D Grids and Matrices represent spatial layouts where traversal choices are typically 4-directional (Up, Down, Left, Right) or 8-directional.

---

## 🧠 Mental Model: Key Traversal Paradigms

### 1. Multi-Source BFS (Rotting Oranges / 01 Matrix)
- When multiple nodes expand simultaneously at the same rate, push **all starting sources into the queue at $t = 0$** before starting the BFS!
- Guarantees $O(R \times C)$ shortest distance computation across all cells simultaneously.

### 2. Connected Component Flood-Fill (Number of Islands)
- DFS or BFS marks visited land cells (e.g., flipping `'1'` to `'0'`) to avoid extra visited sets.

### 3. State-Expanded BFS (Shortest Path with Obstacle Elimination / Sokoban)
- When your state includes resources (like remaining obstacles $K$ you can break, or player + box positions in Sokoban), expand your BFS visited array from `visited[r][c]` to `visited[r][c][k]`!

### 4. In-Place Matrix Rotation
- Rotate by 90° Clockwise: **Transpose** matrix across main diagonal, then **Reverse each row**.

---

## 📂 Folder Contents

| File | Problem | Technique | Complexity |
| :--- | :--- | :--- | :--- |
| [`rotateImage.cpp`](file:///home/legendneon/Backup/DSAPrograms/matrix/rotateImage.cpp) | LC 48: Rotate Image | Transpose + Row Reverse | $O(N^2)$ Time, $O(1)$ Space |
| [`numberislands.cpp`](file:///home/legendneon/Backup/DSAPrograms/matrix/numberislands.cpp) | LC 200: Number of Islands | 4-direction Flood Fill (DFS/BFS) | $O(R \times C)$ |
| [`rottingOranges.cpp`](file:///home/legendneon/Backup/DSAPrograms/matrix/rottingOranges.cpp) | LC 994: Rotting Oranges | Multi-Source BFS level-by-level | $O(R \times C)$ |
| [`01matrix.cpp`](file:///home/legendneon/Backup/DSAPrograms/matrix/01matrix.cpp) | LC 542: 01 Matrix | Multi-Source BFS from all 0s | $O(R \times C)$ |
| [`shortestPathElimination.cpp`](file:///home/legendneon/Backup/DSAPrograms/matrix/shortestPathElimination.cpp) | LC 1293: Shortest Path in a Grid with Obstacles Elimination | 3D BFS State `(r, c, k)` | $O(R \times C \times K)$ |
| [`MinMovesBoxTarget.cpp`](file:///home/legendneon/Backup/DSAPrograms/matrix/MinMovesBoxTarget.cpp) | LC 1263: Minimum Moves to Move a Box to Their Target Location | Dual BFS / A* (Player Reachability + Box Push) | Hard State BFS |
| [`TwoNonOverlapping.cpp`](file:///home/legendneon/Backup/DSAPrograms/matrix/TwoNonOverlapping.cpp) | Two Non-Overlapping Submatrices | 2D Prefix Sums + Boundary Min/Max | $O(R \times C)$ |
