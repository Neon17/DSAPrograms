# 📈 Longest Increasing Subsequence (LIS) Pattern Guide

Welcome to the **Longest Increasing Subsequence (LIS)** toolkit! LIS is one of the foundational dynamic programming patterns in competitive programming and technical interviews.

---

## 🧠 What is LIS?

Given an array of numbers, a **subsequence** is derived by deleting zero or more elements without changing the relative order of the remaining elements.
The **Longest Increasing Subsequence (LIS)** is the longest subsequence whose elements are in strictly increasing order.

> **Example:** `nums = [10, 9, 2, 5, 3, 7, 101, 18]`  
> One LIS is `[2, 3, 7, 101]` or `[2, 5, 7, 101]` or `[2, 3, 7, 18]`. Length = **4**.

---

## 🛠️ The Two Fundamental Approaches

### 1. Classical Dynamic Programming — $O(N^2)$ Time, $O(N)$ Space

Best when $N \le 2500$, or when you need to **reconstruct the actual sequence**, compute **sums** (e.g., Maximum Sum Increasing Subsequence), or count **number of ways**.

#### State Definition:
- `dp[i]` = length of the longest increasing subsequence that **ends at index `i`**.

#### Base Case & Recurrence:
- Base: `dp[i] = 1` (every element alone is an increasing subsequence of length 1).
- Transition:
  $$\text{dp}[i] = 1 + \max(\{ \text{dp}[j] \mid 0 \le j < i \text{ and } \text{nums}[j] < \text{nums}[i] \})$$
- Answer: $\max_{0 \le i < N} \text{dp}[i]$.

#### C++ Template:
```cpp
int lengthOfLIS(vector<int>& nums) {
    if (nums.empty()) return 0;
    int n = nums.size(), maxLen = 1;
    vector<int> dp(n, 1);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxLen = max(maxLen, dp[i]);
    }
    return maxLen;
}
```

#### Reconstructing the Sequence (Path Printing):
Keep a `parent[i]` array:
```cpp
vector<int> parent(n, -1);
// when dp[j] + 1 > dp[i]:
dp[i] = dp[j] + 1;
parent[i] = j;
```

---

### 2. Patience Sorting + Binary Search — $O(N \log N)$ Time, $O(N)$ Space

Essential when $N \le 10^5$. 

#### Intuition:
We maintain a dynamic array `tails`, where `tails[k]` stores the **smallest ending element** among all increasing subsequences of length `k + 1` seen so far.
A smaller ending element is always superior because it leaves more room for future elements to extend the subsequence.

#### Algorithm:
For each `x` in `nums`:
1. If `tails.empty()` or `x > tails.back()`, append `x` to `tails`.
2. Otherwise, find the smallest element in `tails` that is $\ge x$ using binary search (`std::lower_bound`) and replace it with `x`.

#### C++ Template:
```cpp
int lengthOfLIS(vector<int>& nums) {
    vector<int> tails;
    for (int x : nums) {
        auto it = lower_bound(tails.begin(), tails.end(), x);
        if (it == tails.end()) {
            tails.push_back(x);
        } else {
            *it = x; // replace with smaller tail
        }
    }
    return tails.size();
}
```

> ⚠️ **Note:** The `tails` array gives the **correct length** of the LIS, but its contents may **not** form the actual valid LIS elements (indices might be scrambled across different branches).

---

## 🎯 Common Variations & Problem Tricks

### 1. Counting the Number of LIS
- **Problem:** [LeetCode 673](https://leetcode.com/problems/number-of-longest-increasing-subsequence/)
- **Strategy:** Maintain two arrays:
  - `len[i]` = length of LIS ending at `i`.
  - `ways[i]` = count of LIS of length `len[i]` ending at `i`.
- When updating:
  - If `len[j] + 1 > len[i]`: new max length found! Set `len[i] = len[j] + 1`, `ways[i] = ways[j]`.
  - If `len[j] + 1 == len[i]`: alternative way found! Add `ways[i] += ways[j]`.

---

### 2. 2D Russian Doll Envelopes
- **Problem:** [LeetCode 354](https://leetcode.com/problems/russian-doll-envelopes/)
- **Envelope condition:** Envelope $A$ fits inside $B \iff w_A < w_B \text{ and } h_A < h_B$.
- **Sorting Trick:**
  - Sort width in **Ascending** order.
  - For envelopes with the **same width**, sort height in **Descending** order!
  - **Why height descending?** If heights were ascending, two envelopes with the same width could both be selected in a 1D LIS on heights. By sorting heights descending, at most one envelope of any given width can be chosen.
- Then run standard $O(N \log N)$ LIS on heights!

---

### 3. Maximum Sum Increasing Subsequence / Best Team
- **Problem:** [LeetCode 1626](https://leetcode.com/problems/best-team-with-no-conflicts/)
- **Strategy:** Sort players by age ascending (and score ascending for ties).
- Now the condition reduces to picking a subsequence of scores such that scores are non-decreasing.
- Instead of maximizing the number of elements, maximize the **sum of scores**:
  $$\text{dp}[i] = \text{score}[i] + \max(\{ \text{dp}[j] \mid j < i \text{ and } \text{score}[j] \le \text{score}[i] \})$$

---

## 📂 Files in this Folder

| File | LeetCode | Difficulty | Technique / Concept | Time Complexity |
| :--- | :--- | :--- | :--- | :--- |
| [`longestIncreasingSubsequence.cpp`](file:///home/legendneon/Backup/DSAPrograms/dynamic_programming/lis/longestIncreasingSubsequence.cpp) | LC 300 | Medium | $O(N^2)$ DP & $O(N \log N)$ Binary Search | $O(N \log N)$ |
| [`numberLongestIncreasingSubsequence.cpp`](file:///home/legendneon/Backup/DSAPrograms/dynamic_programming/lis/numberLongestIncreasingSubsequence.cpp) | LC 673 | Medium | DP with length + ways tracking | $O(N^2)$ |
| [`RussianDollEnvelope.cpp`](file:///home/legendneon/Backup/DSAPrograms/dynamic_programming/lis/RussianDollEnvelope.cpp) | LC 354 | Hard | Sort Width ASC / Height DESC + 1D LIS | $O(N \log N)$ |
| [`bestTeamNoConflict.cpp`](file:///home/legendneon/Backup/DSAPrograms/dynamic_programming/lis/bestTeamNoConflict.cpp) | LC 1626 | Medium | Sort by age + Max Sum Increasing Subsequence | $O(N^2)$ |

---

## ⚡ Quick Decision Matrix

| Constraint | Recommended Approach |
| :--- | :--- |
| $N \le 2500$ & need path reconstruction | $O(N^2)$ Classical DP with `parent` array |
| $N \le 10^5$ & only need length | $O(N \log N)$ Patience Sort (`lower_bound`) |
| Strictly Increasing | Use `lower_bound` on tails |
| Non-Decreasing ($\le$) | Use `upper_bound` on tails |
| 2D Dimensions $[w, h]$ | Sort dimension 1 ASC, dimension 2 DESC, then 1D LIS |
| Maximize values/sums | $O(N^2)$ DP or Coordinate Compression + Segment Tree / Fenwick Tree ($O(N \log N)$) |
