# 🕸️ Graphs Pattern Guide

Graph algorithms model relationships and network flows. They range from connectivity and component traversal (BFS/DFS) to shortest paths and cycle detection.

---

## 🧠 Mental Model & Core Paradigms

### 1. Representation
- **Adjacency List:** `vector<vector<pair<int, int>>> adj` (optimal for sparse graphs, $O(V + E)$ memory).
- **Adjacency Matrix:** `matrix[u][v]` (optimal for dense graphs or rapid $O(1)$ edge queries).

### 2. Traversal Choice
- **BFS (Queue):** Shortest path in unweighted graphs, level-order expansion.
- **DFS (Recursion / Stack):** Cycle detection, topological sort, bipartite checking, connected components.

### 3. Weighted Shortest Paths
- **Dijkstra's Algorithm:** Non-negative weights ($O((V + E) \log V)$ with min-priority queue).
- **Bellman-Ford Algorithm:** Handles negative edge weights and detects negative weight cycles by relaxing all edges $V-1$ times ($O(V \times E)$).
- **Modified Bellman-Ford / BFS with Stop Constraint:** Cheapest Flights Within K Stops.

---

## 📂 Folder Contents

| File | Problem / Concept | Algorithm | Complexity |
| :--- | :--- | :--- | :--- |
| [`graphRepresentation.cpp`](file:///home/legendneon/Backup/DSAPrograms/graphs/graphRepresentation.cpp) | Adjacency list and matrix basics | Core Graph Foundations | $O(V + E)$ |
| [`BellmanFord.cpp`](file:///home/legendneon/Backup/DSAPrograms/graphs/BellmanFord.cpp) | Bellman-Ford Algorithm | $V-1$ Edge Relaxations & Cycle Detection | $O(V \times E)$ |
| [`cheapestFlight.cpp`](file:///home/legendneon/Backup/DSAPrograms/graphs/cheapestFlight.cpp) | LC 787: Cheapest Flights Within K Stops | BFS with queue or Bellman-Ford variant | $O(K \times E)$ |
| [`EvaluateDivison.cpp`](file:///home/legendneon/Backup/DSAPrograms/graphs/EvaluateDivison.cpp) | LC 399: Evaluate Division | Weighted directed graph BFS/DFS | $O(Q \times (V + E))$ |
| [`cycle_detection_undirected.cpp`](file:///home/legendneon/Backup/DSAPrograms/graphs/cycle_detection_undirected.cpp) | Detect cycle in undirected graph | DFS with Parent / BFS with Queue | $O(V + E)$ |
| [`cycle_detection_directed.cpp`](file:///home/legendneon/Backup/DSAPrograms/graphs/cycle_detection_directed.cpp) | Detect cycle in directed graph | DFS 3-State / BFS Kahn's In-Degree | $O(V + E)$ |
| [`topological_sort.cpp`](file:///home/legendneon/Backup/DSAPrograms/graphs/topological_sort.cpp) | Topological Sort (LC 210) | Kahn's Algorithm / DFS Stack | $O(V + E)$ |
| [`bipartite_graph.cpp`](file:///home/legendneon/Backup/DSAPrograms/graphs/bipartite_graph.cpp) | Is Graph Bipartite? (LC 785) | 2-Coloring BFS / DFS | $O(V + E)$ |
| [`dijkstra.cpp`](file:///home/legendneon/Backup/DSAPrograms/graphs/dijkstra.cpp) | Dijkstra's Shortest Path (LC 743) | Min-Priority Queue | $O((V + E) \log V)$ |
| [`disjoint_set_union.cpp`](file:///home/legendneon/Backup/DSAPrograms/graphs/disjoint_set_union.cpp) | DSU & Kruskal's MST (LC 684) | Path Compression & Union by Rank | $O(E \log E + V \alpha(V))$ |
| [`bridges_tarjan.cpp`](file:///home/legendneon/Backup/DSAPrograms/graphs/bridges_tarjan.cpp) | Critical Connections (LC 1192) | Tarjan's Bridge Algorithm (tin/low) | $O(V + E)$ |
