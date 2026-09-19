# ⚡ Shortest Path Algorithms Guide

Specialized algorithms for computing optimal travel times, latency, and routing across network topologies.

---

## 🧠 Mental Model: Dijkstra's Algorithm Template

Use Dijkstra whenever edge weights are **non-negative** and you need shortest paths from a single source:

```cpp
vector<int> dist(n + 1, INT_MAX);
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

dist[source] = 0;
pq.push({0, source});

while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();

    if (d > dist[u]) continue; // Skip stale entries

    for (auto& [v, weight] : adj[u]) {
        if (dist[u] + weight < dist[v]) {
            dist[v] = dist[u] + weight;
            pq.push({dist[v], v});
        }
    }
}
```

---

## 📂 Folder Contents

| File | Problem | Technique | Complexity |
| :--- | :--- | :--- | :--- |
| [`NetworkDelayTime.cpp`](file:///home/legendneon/Backup/DSAPrograms/shortestPath/NetworkDelayTime.cpp) | LC 743: Network Delay Time | Standard Dijkstra with min-priority queue | $O(E \log V)$ |
| [`NetworkIdleTime.cpp`](file:///home/legendneon/Backup/DSAPrograms/shortestPath/NetworkIdleTime.cpp) | LC 2039: The Time When the Network Becomes Idle | Unweighted BFS for round-trip distances + timing math | $O(V + E)$ |
