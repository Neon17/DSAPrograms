# 🚀 Striver DP Revision Guide

Curated solutions and pattern revisions based on the popular **Striver's DP Series** (TakeUforward). These problems cover foundational 1D, 2D Grid, and 3D Dynamic Programming patterns.

---

## 🧠 Patterns & How to Approach

### 1. 1D DP: Consecutive State Constraints (House Robber)
- **Mental Model:** At house $i$, choose whether to rob (gain `nums[i] + dp[i-2]`) or skip (`dp[i-1]`).
- **Circular Houses (House Robber II):** Since house $0$ and house $n-1$ are adjacent, compute $\max(\text{Rob}(0 \dots n-2), \text{Rob}(1 \dots n-1))$.
- **Space Optimization:** You only ever need `prev` and `prev2` $\implies O(1)$ space.

### 2. 2D Grid DP: Paths and Costs
- **Unique Paths / Min Sum Path / Max Falling Path Sum:**
  - Move choices define transitions (e.g., Down or Right: `dp[r][c] = grid[r][c] + min(dp[r+1][c], dp[r][c+1])`).
  - Base cases live on borders or the destination row/column.
  - Optimize 2D table to 1D rolling row (`vector<int> prev, curr`).
- **Triangle:** Bottom-up traversal avoids boundary checks on triangular edges.

### 3. Multi-Choice Transition: Ninja's Training
- **Mental Model:** Today's activity cannot match yesterday's activity.
- **State:** `dp[day][last_task] = max(points[day][task] + dp[day-1][task])` for all `task != last_task`.

### 4. 3D DP: Simultaneous Multi-Agent Paths (Cherry Pickup 3D)
- **Mental Model:** Two robots move synchronously from row $0$ down to row $r-1$.
- **State:** Because both robots move down simultaneously, both are always on the same row `r`.
  - State reduces from 4D $(r_1, c_1, r_2, c_2)$ to 3D: `dp[r][c1][c2]`.
  - If $c_1 == c_2$, add cherries once; otherwise add $grid[r][c_1] + grid[r][c_2]$.

---

## 📂 Folder Contents

| File | Problem | Pattern | Complexity |
| :--- | :--- | :--- | :--- |
| [`HouseRobberI.cpp`](file:///home/legendneon/Backup/DSAPrograms/striverDPRevise/HouseRobberI.cpp) | LC 198: House Robber | 1D DP (Pick / Non-pick) | $O(N)$ Time, $O(1)$ Space |
| [`HouseRobberII.cpp`](file:///home/legendneon/Backup/DSAPrograms/striverDPRevise/HouseRobberII.cpp) | LC 213: House Robber II | Circular 1D DP | $O(N)$ Time, $O(1)$ Space |
| [`GridUniquePath.cpp`](file:///home/legendneon/Backup/DSAPrograms/striverDPRevise/GridUniquePath.cpp) | LC 62: Unique Paths | 2D Grid Counting | $O(M \times N)$ |
| [`MInSumPath.cpp`](file:///home/legendneon/Backup/DSAPrograms/striverDPRevise/MInSumPath.cpp) | LC 64: Minimum Path Sum | 2D Grid Min Cost | $O(M \times N)$ |
| [`Triangle.cpp`](file:///home/legendneon/Backup/DSAPrograms/striverDPRevise/Triangle.cpp) | LC 120: Triangle | Bottom-up Grid DP | $O(N^2)$ |
| [`MaxFallingPathSum.cpp`](file:///home/legendneon/Backup/DSAPrograms/striverDPRevise/MaxFallingPathSum.cpp) | LC 931: Minimum Falling Path Sum | Variable Start/End Grid DP | $O(M \times N)$ |
| [`NinjaTraining.cpp`](file:///home/legendneon/Backup/DSAPrograms/striverDPRevise/NinjaTraining.cpp) | Ninja's Training (GeeksforGeeks / CodingNinjas) | State with forbidden choices | $O(N \times 4 \times 3)$ |
| [`SubsetSumTarget.cpp`](file:///home/legendneon/Backup/DSAPrograms/striverDPRevise/SubsetSumTarget.cpp) | Subset Sum to Target | 0/1 Knapsack Decision | $O(N \times \text{target})$ |
| [`CherryPick3D.cpp`](file:///home/legendneon/Backup/DSAPrograms/striverDPRevise/CherryPick3D.cpp) | LC 1463: Cherry Pickup II | 3D Simultaneous Traversal | $O(R \times C^2 \times 9)$ |
