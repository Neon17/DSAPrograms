# 🧩 Dynamic Programming (DP) Guide

Welcome to the **Dynamic Programming** module! Dynamic Programming is the art of solving complex problems by breaking them down into simpler, overlapping subproblems and storing intermediate results to avoid redundant computation.

---

## 🧭 The 5-Step DP Mental Model

Whenever you face a DP problem, follow this structured blueprint:

1. **Identify the Core State:**  
   Define what `dp[i]` or `dp[i][j]` represents in plain English (e.g., `dp[i]` = max profit up to day `i`, or `dp[i][w]` = max value using first `i` items with capacity `w`).
2. **Determine the Base Cases:**  
   What are the smallest trivial states? (`dp[0] = 0`, `dp[0][0] = 1`, out-of-bound defaults).
3. **Formulate the Transition Equation:**  
   How does `dp[i]` relate to smaller subproblems like `dp[i - 1]` or `dp[i - k]`? (e.g., choice between *take* vs *skip*).
4. **Determine Evaluation Order:**  
   Ensure dependencies are already solved before computing the current state (Left-to-Right, Bottom-to-Top, or topological order).
5. **Space Optimization:**  
   If `dp[i]` only depends on `dp[i - 1]`, reduce $O(N)$ or $O(N \times W)$ space to $O(1)$ variables or a 1D rolling array.

---

## 🎯 Major Patterns in this Directory

### 1. 0/1 Knapsack & Subset Sum
- **Concept:** For each item, decide whether to **include** or **exclude** it under a capacity constraint.
- **Rule of Thumb:** When iterating backwards through capacities (`w = W down to weight[i]`), you can reduce 2D DP to 1D DP!
- **Programs:**
  - [`01KnapsackDynamic.cpp`](file:///home/legendneon/Backup/DSAPrograms/dynamic_programming/01KnapsackDynamic.cpp)
  - [`01NewKnapsackDynamic.cpp`](file:///home/legendneon/Backup/DSAPrograms/dynamic_programming/01NewKnapsackDynamic.cpp)
  - [`SubsetProblemDynamic.cpp`](file:///home/legendneon/Backup/DSAPrograms/dynamic_programming/SubsetProblemDynamic.cpp)

---

### 2. State Machine / Stock Trading DP
- **Concept:** Model systems where decisions transition between finite states (e.g., `Held`, `Sold`, `Cooldown`).
- **Recurrence Example (Stock with Cooldown):**
  - `buy[i] = max(buy[i - 1], cooldown[i - 1] - price[i])`
  - `sell[i] = max(sell[i - 1], buy[i - 1] + price[i])`
  - `cooldown[i] = max(cooldown[i - 1], sell[i - 1])`
- **Programs:**
  - [`BuySellStockCoolDown.cpp`](file:///home/legendneon/Backup/DSAPrograms/dynamic_programming/BuySellStockCoolDown.cpp)

---

### 3. String Partitioning & Word Break
- **Concept:** Splitting a sequence or string into valid dictionary tokens.
- **Recurrence:** `dp[i]` is true if there exists a valid split point `j < i` where `dp[j]` is true and substring `s[j...i-1]` exists in the dictionary.
- **Programs:**
  - [`WordBreak.cpp`](file:///home/legendneon/Backup/DSAPrograms/dynamic_programming/WordBreak.cpp)

---

### 4. Arithmetic & Subsequence DP
- **Concept:** Subsequences constrained by common differences rather than strict monotonicity.
- **Programs:**
  - [`longestArithmeticSub.cpp`](file:///home/legendneon/Backup/DSAPrograms/dynamic_programming/longestArithmeticSub.cpp) — LC 1027 ($O(N^2)$ with 2D hash/table for difference).
  - [`longestArithmeticSubDiff.cpp`](file:///home/legendneon/Backup/DSAPrograms/dynamic_programming/longestArithmeticSubDiff.cpp) — LC 1218 ($O(N)$ with hash map tracking `dp[x] = dp[x - diff] + 1`).

---

### 5. Multi-Sign Kadane / Subarray DP
- **Concept:** Tracking both `max_product` and `min_product` because multiplying a negative number by a negative minimum yields a large positive maximum.
- **Programs:**
  - [`maxProductSubarray.cpp`](file:///home/legendneon/Backup/DSAPrograms/dynamic_programming/maxProductSubarray.cpp)

---

### 6. Grid Path Counting
- **Concept:** Moving in grid cells where each state accumulates paths from previous reachable neighbors.
- **Programs:**
  - [`GridExactKPath.cpp`](file:///home/legendneon/Backup/DSAPrograms/dynamic_programming/GridExactKPath.cpp)

---

## 📁 Submodules

- **[`lis/`](file:///home/legendneon/Backup/DSAPrograms/dynamic_programming/lis/README.md)**: Dedicated directory for all **Longest Increasing Subsequence** variants, including $O(N \log N)$ patience sort, counting ways, 2D Russian Doll Envelopes, and Max Sum Increasing Subsequences.

---

## 📂 Files in this Folder

| File | Problem Description / Pattern | Time Complexity |
| :--- | :--- | :--- |
| [`fibonacciDP.cpp`](file:///home/legendneon/Backup/DSAPrograms/dynamic_programming/fibonacciDP.cpp) | Tabulation basics (Bottom-up) | $O(N)$ |
| [`fibonacciMemoization.cpp`](file:///home/legendneon/Backup/DSAPrograms/dynamic_programming/fibonacciMemoization.cpp) | Memoization basics (Top-down) | $O(N)$ |
| [`01KnapsackDynamic.cpp`](file:///home/legendneon/Backup/DSAPrograms/dynamic_programming/01KnapsackDynamic.cpp) | Classic 0/1 Knapsack 2D table | $O(N \times W)$ |
| [`01NewKnapsackDynamic.cpp`](file:///home/legendneon/Backup/DSAPrograms/dynamic_programming/01NewKnapsackDynamic.cpp) | Space-optimized 0/1 Knapsack | $O(N \times W)$ |
| [`SubsetProblemDynamic.cpp`](file:///home/legendneon/Backup/DSAPrograms/dynamic_programming/SubsetProblemDynamic.cpp) | Subset Sum Target decision DP | $O(N \times \text{target})$ |
| [`BuySellStockCoolDown.cpp`](file:///home/legendneon/Backup/DSAPrograms/dynamic_programming/BuySellStockCoolDown.cpp) | LC 309: Stock with Cooldown (State Machine DP) | $O(N)$ |
| [`WordBreak.cpp`](file:///home/legendneon/Backup/DSAPrograms/dynamic_programming/WordBreak.cpp) | LC 139: String segmentation with dictionary lookup | $O(N^2)$ |
| [`longestArithmeticSub.cpp`](file:///home/legendneon/Backup/DSAPrograms/dynamic_programming/longestArithmeticSub.cpp) | LC 1027: Longest Arithmetic Subsequence | $O(N^2)$ |
| [`longestArithmeticSubDiff.cpp`](file:///home/legendneon/Backup/DSAPrograms/dynamic_programming/longestArithmeticSubDiff.cpp) | LC 1218: Longest Arithmetic Subsequence with fixed difference | $O(N)$ |
| [`maxProductSubarray.cpp`](file:///home/legendneon/Backup/DSAPrograms/dynamic_programming/maxProductSubarray.cpp) | LC 152: Maximum Product Subarray (Min/Max Tracking) | $O(N)$ |
| [`GridExactKPath.cpp`](file:///home/legendneon/Backup/DSAPrograms/dynamic_programming/GridExactKPath.cpp) | Exact K-step grid paths | $O(R \times C \times K)$ |
| [`MinDaysScoreKPoints.cpp`](file:///home/legendneon/Backup/DSAPrograms/dynamic_programming/MinDaysScoreKPoints.cpp) | Minimum days to reach target score | Dynamic |
