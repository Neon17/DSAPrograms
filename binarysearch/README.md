# 🎯 Binary Search Guide

Binary Search is more than searching in a sorted array—it is a meta-strategy for finding optimal boundaries across any monotonic search space.

---

## 🧠 Mental Model: When & How to Approach

### 1. Monotonic Predicate ($F \dots F \mid T \dots T$)
Binary search works whenever a function $P(x)$ is monotonic:
- If $P(x)$ is true, all values $> x$ (or $< x$) are also true.
- Identify the search boundaries: `low` (definitely invalid or minimal valid) and `high` (definitely valid or maximal valid).

### 2. Binary Search on Answer Space (Minimax / Maximin)
- **Problem Signals:** "Find the minimum maximum...", "Minimum speed to finish in time...", "Split array to minimize largest sum...".
- **Technique:**
  1. Determine minimum possible answer (`low`) and maximum possible answer (`high`).
  2. Implement a helper: `bool canAchieve(target)`.
  3. Binary search on the answer range:
     ```cpp
     while (low <= high) {
         int mid = low + (high - low) / 2;
         if (canAchieve(mid)) {
             ans = mid;
             high = mid - 1; // search for smaller valid value
         } else {
             low = mid + 1;
         }
     }
     ```

### 3. Rotated Sorted Array
- In a rotated sorted array, **at least one half is always strictly sorted**!
- Check if `nums[low] <= nums[mid]`:
  - If yes, the left half is sorted: check if target lies between `nums[low]` and `nums[mid]`.
  - If no, the right half is sorted: check if target lies between `nums[mid]` and `nums[high]`.

---

## 📂 Folder Contents

| File | Problem | Pattern | Complexity |
| :--- | :--- | :--- | :--- |
| [`KokoEatingBananas.cpp`](file:///home/legendneon/Backup/DSAPrograms/binarysearch/KokoEatingBananas.cpp) | LC 875: Koko Eating Bananas | Binary search on speed | $O(N \log(\max(\text{piles})))$ |
| [`SplitArrayLargestSum.cpp`](file:///home/legendneon/Backup/DSAPrograms/binarysearch/SplitArrayLargestSum.cpp) | LC 410: Split Array Largest Sum | Binary search on max subarray sum | $O(N \log(\sum \text{nums}))$ |
| [`searchRotatedArray.cpp`](file:///home/legendneon/Backup/DSAPrograms/binarysearch/searchRotatedArray.cpp) | LC 33: Search in Rotated Sorted Array | One-half sorted check | $O(\log N)$ |
