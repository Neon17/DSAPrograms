# ✌️ Two Pointers Pattern Guide

The Two Pointers technique leverages monotonic properties of arrays or cycle properties of linked structures to achieve linear $O(N)$ runtime with $O(1)$ auxiliary memory.

---

## 🧠 Mental Model: When & How to Approach

### 1. Inward Converging Pointers (`left` & `right`)
- **Use Case:** Sorted arrays, greedy pairing (e.g., lightest + heaviest person in boats).
- **Template:**
  ```cpp
  int left = 0, right = n - 1;
  while (left <= right) {
      if (conditionMet(nums[left], nums[right])) {
          // move both or process
          left++;
          right--;
      } else {
          // move one pointer greedily
          right--;
      }
  }
  ```

### 2. Dutch National Flag (3-Way Partitioning)
- **Problem:** [Sort Colors (LC 75)](https://leetcode.com/problems/sort-colors/)
- **Strategy:** Maintain 3 pointers: `low` (boundary for 0s), `mid` (current element), and `high` (boundary for 2s).
  - If `nums[mid] == 0`: `swap(nums[low++], nums[mid++])`
  - If `nums[mid] == 1`: `mid++`
  - If `nums[mid] == 2`: `swap(nums[mid], nums[high--])` (do not advance `mid` because swapped element is uninspected!)

### 3. Floyd's Tortoise and Hare (Cycle Detection)
- **Problem:** [Find the Duplicate Number (LC 287)](https://leetcode.com/problems/find-the-duplicate-number/)
- **Strategy:** Treat array indices and values as a linked list where $i \to \text{nums}[i]$.
  - Phase 1: `slow = nums[slow]`, `fast = nums[nums[fast]]` until `slow == fast`.
  - Phase 2: Reset `slow = 0`, step both by 1 until they meet at the cycle entry (the duplicate).

---

## 📂 Folder Contents

| File | Problem | Pattern | Complexity |
| :--- | :--- | :--- | :--- |
| [`boatSavePeople.cpp`](file:///home/legendneon/Backup/DSAPrograms/twopointers.cpp/boatSavePeople.cpp) | LC 881: Boats to Save People | Inward greedy pairing | $O(N \log N)$ |
| [`bagTokens.cpp`](file:///home/legendneon/Backup/DSAPrograms/twopointers.cpp/bagTokens.cpp) | LC 948: Bag of Tokens | Two pointers: buy score low, sell for power high | $O(N \log N)$ |
| [`sortColors.cpp`](file:///home/legendneon/Backup/DSAPrograms/twopointers.cpp/sortColors.cpp) | LC 75: Sort Colors | Dutch National Flag (3-way partition) | $O(N)$ Time, $O(1)$ Space |
| [`DuplicateNumber.cpp`](file:///home/legendneon/Backup/DSAPrograms/twopointers.cpp/DuplicateNumber.cpp) | LC 287: Find the Duplicate Number | Floyd's Cycle Detection | $O(N)$ Time, $O(1)$ Space |
| [`longestMountainArray.cpp`](file:///home/legendneon/Backup/DSAPrograms/twopointers.cpp/longestMountainArray.cpp) | LC 845: Longest Mountain in Array | Peak detection & two-way expansion | $O(N)$ Time, $O(1)$ Space |
