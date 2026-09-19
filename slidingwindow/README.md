# 🪟 Sliding Window Pattern Guide

The Sliding Window technique converts $O(N^2)$ brute-force nested loops over contiguous subarrays or substrings into linear $O(N)$ solutions by expanding and shrinking two pointers (`left` and `right`).

---

## 🧠 Mental Model: How to Approach

### 1. The Core Dynamic Window Template
```cpp
int left = 0, ans = 0;
for (int right = 0; right < n; right++) {
    // 1. Add nums[right] into current window state
    updateState(nums[right]);

    // 2. Shrink from left while window condition is invalid
    while (isInvalid()) {
        removeState(nums[left]);
        left++;
    }

    // 3. Update answer (e.g., max length: right - left + 1)
    ans = max(ans, right - left + 1);
}
```

### 2. The "Exact K" Reduction Pattern: $\text{AtMost}(K) - \text{AtMost}(K - 1)$
- **Problem Signals:** "Subarrays with exactly $K$ distinct integers" or "Subarrays with sum equal to $K$".
- **Insight:** Calculating "exactly $K$" directly with sliding window is difficult because shrinking left might increase or decrease the count irregularly.
- **The Golden Formula:**
  $$\text{Exact}(K) = \text{AtMost}(K) - \text{AtMost}(K - 1)$$
- Solving `atMost(K)` is standard sliding window: each valid window ending at `right` contributes `(right - left + 1)` subarrays!

---

## 📂 Folder Contents

| File | Problem | Pattern / Concept | Complexity |
| :--- | :--- | :--- | :--- |
| [`fruitsOnBaskets.cpp`](file:///home/legendneon/Backup/DSAPrograms/slidingwindow/fruitsOnBaskets.cpp) | LC 904: Fruit Into Baskets | Longest subarray with at most 2 distinct elements | $O(N)$ |
| [`maxConsecutiveOnesIII.cpp`](file:///home/legendneon/Backup/DSAPrograms/slidingwindow/maxConsecutiveOnesIII.cpp) | LC 1004: Max Consecutive Ones III | At most $K$ zero flips | $O(N)$ |
| [`getEqualSubstringsBudget.cpp`](file:///home/legendneon/Backup/DSAPrograms/slidingwindow/getEqualSubstringsBudget.cpp) | LC 1208: Equal Substrings Within Budget | Window cost $\le \text{maxCost}$ | $O(N)$ |
| [`minimumwindowsubstring.cpp`](file:///home/legendneon/Backup/DSAPrograms/slidingwindow/minimumwindowsubstring.cpp) | LC 76: Minimum Window Substring | Frequency map match & shrink to minimum | $O(N)$ |
| [`subarrayKDiffIntegers.cpp`](file:///home/legendneon/Backup/DSAPrograms/slidingwindow/subarrayKDiffIntegers.cpp) | LC 992: Subarrays with K Different Integers | $\text{AtMost}(K) - \text{AtMost}(K - 1)$ | $O(N)$ |
| [`binarySubarraySum.cpp`](file:///home/legendneon/Backup/DSAPrograms/slidingwindow/binarySubarraySum.cpp) | LC 930: Binary Subarrays With Sum | $\text{AtMost}(Goal) - \text{AtMost}(Goal - 1)$ | $O(N)$ |
| [`countNiceSubarrays.cpp`](file:///home/legendneon/Backup/DSAPrograms/slidingwindow/countNiceSubarrays.cpp) | LC 1248: Count Number of Nice Subarrays | Map odd $\to 1$, even $\to 0 \implies \text{AtMost}(K)$ | $O(N)$ |
| [`subarrayProductLessK.cpp`](file:///home/legendneon/Backup/DSAPrograms/slidingwindow/subarrayProductLessK.cpp) | LC 713: Subarray Product Less Than K | Running product shrink | $O(N)$ |
| [`subarraysBoundedMax.cpp`](file:///home/legendneon/Backup/DSAPrograms/slidingwindow/subarraysBoundedMax.cpp) | LC 795: Number of Subarrays with Bounded Maximum | Count with max $\le R$ minus max $< L$ | $O(N)$ |
