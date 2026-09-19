# 🤝 Disjoint Set Union (Union-Find) Guide

Disjoint Set Union (DSU) tracks elements partitioned into disjoint subsets. It supports two nearly $O(1)$ operations with **Path Compression** and **Union by Rank/Size**:
1. `find(i)`: Return representative/root of the set containing `i`.
2. `unite(i, j)`: Merge the sets containing `i` and `j`.

---

## 🧠 Mental Model & Standard DSU Template

```cpp
class DSU {
    vector<int> parent, rank;
public:
    DSU(int n) : parent(n), rank(n, 0) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]); // Path compression
    }
    bool unite(int i, int j) {
        int rootI = find(i), rootJ = find(j);
        if (rootI == rootJ) return false; // Cycle or already connected!
        if (rank[rootI] < rank[rootJ]) swap(rootI, rootJ);
        parent[rootJ] = rootI;
        if (rank[rootI] == rank[rootJ]) rank[rootI]++;
        return true;
    }
};
```

---

## 📂 Folder Contents

| File | Problem | Pattern | Complexity |
| :--- | :--- | :--- | :--- |
| [`NumberProvinces.cpp`](file:///home/legendneon/Backup/DSAPrograms/union-find/NumberProvinces.cpp) | LC 547: Number of Provinces | Count of unique roots in DSU | $O(N^2 \cdot \alpha(N))$ |
| [`RedundantConnections.cpp`](file:///home/legendneon/Backup/DSAPrograms/union-find/RedundantConnections.cpp) | LC 684: Redundant Connection | Cycle detection when `find(u) == find(v)` | $O(N \cdot \alpha(N))$ |
| [`EqualityEquations.cpp`](file:///home/legendneon/Backup/DSAPrograms/union-find/EqualityEquations.cpp) | LC 990: Satisfiability of Equality Equations | Union on `==`, check conflict on `!=` | $O(N \cdot \alpha(26))$ |
| [`AccountsMerge.cpp`](file:///home/legendneon/Backup/DSAPrograms/union-find/AccountsMerge.cpp) | LC 721: Accounts Merge | Map email $\to$ ID, unite sharing emails | $O(N \log N)$ |
| [`SmallestStringSwaps.cpp`](file:///home/legendneon/Backup/DSAPrograms/union-find/SmallestStringSwaps.cpp) | LC 1202: Smallest String With Swaps | Group connected indices & sort chars | $O(N \log N)$ |
