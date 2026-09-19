# 🏆 LeetCode Hard Showcase

A curated collection of LeetCode Hard challenges covering advanced Dynamic Programming (Interval DP, Multi-State Stock DP), Priority Queues & Multiset data structures, Trapping Rain Water 1D & 2D, and Fenwick/Segment Trees.

---

## 🧠 Major Problem Paradigms

### 1. Interval DP (Think From Inside Out!)
- **Burst Balloons (LC 312) & Min Cost to Cut a Stick (LC 1547):**
  - **Trick:** Instead of deciding which balloon to burst *first* (which merges boundaries unpredictably), decide which balloon to burst **last** in range $[i, j]$!
  - Recurrence: $\text{dp}[i][j] = \max_{k} (\text{dp}[i][k-1] + \text{dp}[k+1][j] + \text{cost}(k))$

### 2. Trapping Rain Water: 1D vs 2D
- **1D (LC 42):** Two pointers converging inwards. The lower boundary dictates the trapped water level.
- **2D (LC 407):** Push all outer boundary cells into a min-heap. Pop the lowest boundary cell and explore inward neighbors. If a neighbor is lower than the current boundary height, it traps water!

### 3. Advanced Window Structures (Sliding Window Median & MK Average)
- Maintain balanced dual multisets or two heaps with lazy removal to retrieve medians in $O(\log K)$ or $O(1)$ time.

---

## 📂 Folder Contents

| File | Problem | Pattern / Concept | Complexity |
| :--- | :--- | :--- | :--- |
| [`BurstBalloons.cpp`](file:///home/legendneon/Backup/DSAPrograms/leetcodehard/BurstBalloons.cpp) | LC 312: Burst Balloons | Interval DP (last balloon burst) | $O(N^3)$ |
| [`MinCostCutStick.cpp`](file:///home/legendneon/Backup/DSAPrograms/leetcodehard/MinCostCutStick.cpp) | LC 1547: Minimum Cost to Cut a Stick | Interval DP | $O(M^3)$ |
| [`BuySellStockIII.cpp`](file:///home/legendneon/Backup/DSAPrograms/leetcodehard/BuySellStockIII.cpp) | LC 123: Best Time to Buy and Sell Stock III | State Machine DP (at most 2 transactions) | $O(N)$ Time, $O(1)$ Space |
| [`BuySellStockIV.cpp`](file:///home/legendneon/Backup/DSAPrograms/leetcodehard/BuySellStockIV.cpp) | LC 188: Best Time to Buy and Sell Stock IV | DP with $K$ transactions | $O(N \times K)$ |
| [`CherryPickup.cpp`](file:///home/legendneon/Backup/DSAPrograms/leetcodehard/CherryPickup.cpp) | LC 741: Cherry Pickup | Dual simultaneous path DP | $O(N^3)$ |
| [`LongestIncreasingPath.cpp`](file:///home/legendneon/Backup/DSAPrograms/leetcodehard/LongestIncreasingPath.cpp) | LC 329: Longest Increasing Path in a Matrix | Memoized DFS / DAG Topological DP | $O(R \times C)$ |
| [`FrogJump.cpp`](file:///home/legendneon/Backup/DSAPrograms/leetcodehard/FrogJump.cpp) | LC 403: Frog Jump | DP / Hash map of accessible jumps $(k-1, k, k+1)$ | $O(N^2)$ |
| [`ReducingDishes.cpp`](file:///home/legendneon/Backup/DSAPrograms/leetcodehard/ReducingDishes.cpp) | LC 1402: Reducing Dishes | Greedy sorting + running suffix sum | $O(N \log N)$ |
| [`traprainwater.cpp`](file:///home/legendneon/Backup/DSAPrograms/leetcodehard/traprainwater.cpp) | LC 42: Trapping Rain Water | Two Pointers inward convergence | $O(N)$ Time, $O(1)$ Space |
| [`traprainwater2.cpp`](file:///home/legendneon/Backup/DSAPrograms/leetcodehard/traprainwater2.cpp) | LC 407: Trapping Rain Water II | Min-Heap priority flood boundary BFS | $O(R \times C \log(RC))$ |
| [`reviseTrapRainWaterII.cpp`](file:///home/legendneon/Backup/DSAPrograms/leetcodehard/reviseTrapRainWaterII.cpp) | LC 407: Revision Notes & Code | Priority Queue 2D boundary infiltration | $O(R \times C \log(RC))$ |
| [`swimrisingwater.cpp`](file:///home/legendneon/Backup/DSAPrograms/leetcodehard/swimrisingwater.cpp) | LC 778: Swim in Rising Water | Dijkstra / Min-Heap or Binary Search + BFS | $O(N^2 \log N)$ |
| [`SlidingWindowMax.cpp`](file:///home/legendneon/Backup/DSAPrograms/leetcodehard/SlidingWindowMax.cpp) | LC 239: Sliding Window Maximum | Monotonic decreasing deque | $O(N)$ |
| [`SlidingWindowMedian.cpp`](file:///home/legendneon/Backup/DSAPrograms/leetcodehard/SlidingWindowMedian.cpp) | LC 480: Sliding Window Median | Dual multisets with balance maintenance | $O(N \log K)$ |
| [`FindMKAverage.cpp`](file:///home/legendneon/Backup/DSAPrograms/leetcodehard/FindMKAverage.cpp) | LC 1825: Finding MK Average | Three multisets (low, mid, high) + queue | $O(\log M)$ per add |
| [`IPO.cpp`](file:///home/legendneon/Backup/DSAPrograms/leetcodehard/IPO.cpp) | LC 502: IPO | Dual heaps (capital min-heap + profit max-heap) | $O(N \log N)$ |
| [`CourseScheduleIII.cpp`](file:///home/legendneon/Backup/DSAPrograms/leetcodehard/CourseScheduleIII.cpp) | LC 630: Course Schedule III | Greedy deadline sort + Max-heap duration pop | $O(N \log N)$ |
| [`Skyline.cpp`](file:///home/legendneon/Backup/DSAPrograms/leetcodehard/Skyline.cpp) | LC 218: The Skyline Problem | Line sweep with multiset / priority queue | $O(N \log N)$ |
| [`CountSmallerAfterSelf.cpp`](file:///home/legendneon/Backup/DSAPrograms/leetcodehard/CountSmallerAfterSelf.cpp) | LC 315: Count of Smaller Numbers After Self | Merge Sort with index tracking or Fenwick Tree | $O(N \log N)$ |
| [`24Game.cpp`](file:///home/legendneon/Backup/DSAPrograms/leetcodehard/24Game.cpp) | LC 679: 24 Game | Recursive backtracking with double precision | $O(1)$ bounded search |
| [`PeaksArrayII.cpp`](file:///home/legendneon/Backup/DSAPrograms/leetcodehard/PeaksArrayII.cpp) | Peak finding in 2D array / Segments | Binary Search / Segment Tree | $O(R \log C)$ |
