# 🔄 Sorting & Searching Algorithms Guide

Classic divide-and-conquer sorting algorithms that form the bedrock of algorithmic efficiency.

---

## 🧠 Mental Model: Merge Sort vs Quick Sort

| Algorithm | Divide Strategy | Combine Strategy | Best / Avg Time | Worst Time | Space Complexity | Stability |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **Merge Sort** | Split at middle $O(1)$ | Two-way merge $O(N)$ | $O(N \log N)$ | $O(N \log N)$ | $O(N)$ | Stable |
| **Quick Sort** | Partition around pivot $O(N)$ | Nothing to combine $O(1)$ | $O(N \log N)$ | $O(N^2)$ (bad pivot) | $O(\log N)$ (stack) | Unstable |

---

## 📂 Folder Contents

| File | Algorithm | Technique | Complexity |
| :--- | :--- | :--- | :--- |
| [`mergeSort.cpp`](file:///home/legendneon/Backup/DSAPrograms/sorting_searching/mergeSort.cpp) | Merge Sort | Divide and conquer with auxiliary array merge | $O(N \log N)$ Time, $O(N)$ Space |
| [`quickSort.cpp`](file:///home/legendneon/Backup/DSAPrograms/sorting_searching/quickSort.cpp) | Quick Sort | Lomuto/Hoare partition around pivot | $O(N \log N)$ Avg, $O(1)$ Extra Space |
