# 💰 Greedy Algorithms Guide

Greedy algorithms make the locally optimal choice at each step with the hope that this leads to a globally optimal solution. They work when the problem exhibits the **Greedy Choice Property** and **Optimal Substructure**.

---

## 🧠 Core Mental Models

### 1. Fractional Knapsack vs 0/1 Knapsack
- In Fractional Knapsack, items can be broken down.
- **Strategy:** Sort items by **value-to-weight ratio** ($\frac{v_i}{w_i}$) in descending order and greedily consume highest value density first.

### 2. Job Sequencing with Deadlines
- **Strategy:** Sort jobs by profit descending.
- For each job, schedule it as late as possible before its deadline (using a timeline array or DSU) to leave earlier slots free for other jobs.

---

## 📂 Folder Contents

| File | Problem | Pattern | Complexity |
| :--- | :--- | :--- | :--- |
| [`KnapsackGreedy.cpp`](file:///home/legendneon/Backup/DSAPrograms/greedy/KnapsackGreedy.cpp) | Fractional Knapsack | Ratio sorting $\frac{\text{value}}{\text{weight}}$ | $O(N \log N)$ |
| [`JobSequencing.cpp`](file:///home/legendneon/Backup/DSAPrograms/greedy/JobSequencing.cpp) | Job Sequencing with Deadlines | Profit sorting + latest possible slot assignment | $O(N \log N + N \times \text{maxDeadline})$ |
