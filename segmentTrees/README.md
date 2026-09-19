# 🌴 Segment Trees Guide

Segment Trees allow range queries (sum, min, max, gcd) and range updates in logarithmic $O(\log N)$ time by maintaining values over power-of-two intervals.

---

## 🧠 Mental Model: Range Updates & Lazy Propagation

When updating a whole interval $[L, R]$:
- Instead of updating all leaf descendants immediately ($O(N)$), update the representative interval node and store the pending change in a `lazy` array.
- Push the lazy tag to children only when those children are accessed during later queries or updates.

---

## 📂 Folder Contents

| File | Problem | Pattern | Complexity |
| :--- | :--- | :--- | :--- |
| [`rangeUpdates.cpp`](file:///home/legendneon/Backup/DSAPrograms/segmentTrees/rangeUpdates.cpp) | Range Updates and Queries | Segment tree with point/range updates | $O(\log N)$ query & update |
