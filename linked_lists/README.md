# 🔗 Linked Lists Pattern Guide

Linked Lists require mastering pointer manipulations without memory leaks or segmentation faults.

---

## 🧠 Core Mental Models & Universal Techniques

### 1. The Dummy Head Pattern (Sentinel Node)
- **Why:** Avoids edge cases when deleting or inserting at the head of the list.
- **Usage:**
  ```cpp
  ListNode dummy(0);
  dummy.next = head;
  ListNode* prev = &dummy;
  // all operations refer to dummy.next as head
  return dummy.next;
  ```

### 2. Fast & Slow Pointers (Tortoise & Hare)
- **Middle of List:** When `fast` reaches end, `slow` is at the middle.
- **Cycle Detection:** If `fast == slow`, cycle exists.

### 3. In-Place Reversal (3 Pointers)
- Maintain `prev = nullptr`, `curr = head`, `next = nullptr`.
- In a loop:
  ```cpp
  next = curr->next;
  curr->next = prev;
  prev = curr;
  curr = next;
  ```

### 4. Merge Sort on Linked List ($O(N \log N)$ Time, $O(1)$ Extra Space)
- Split list using fast/slow pointer (disconnect left half with `prev->next = nullptr`).
- Recursively sort both halves.
- Merge the two sorted lists using standard two-way merge.

---

## 📂 Folder Contents

| File | Problem / Concept | Technique | Complexity |
| :--- | :--- | :--- | :--- |
| [`singleLinkedList.cpp`](file:///home/legendneon/Backup/DSAPrograms/linked_lists/singleLinkedList.cpp) | Basic Singly Linked List | Insert, delete, display operations | $O(N)$ |
| [`doubleLinkedList.cpp`](file:///home/legendneon/Backup/DSAPrograms/linked_lists/doubleLinkedList.cpp) | Doubly Linked List | Two-way pointer management | $O(N)$ |
| [`designLinkedList.cpp`](file:///home/legendneon/Backup/DSAPrograms/linked_lists/designLinkedList.cpp) | LC 707: Design Linked List | Complete OOP implementation | $O(1)$ to $O(N)$ |
| [`addTwoNumbers.cpp`](file:///home/legendneon/Backup/DSAPrograms/linked_lists/addTwoNumbers.cpp) | LC 2: Add Two Numbers | Elementary addition with carry | $O(\max(N, M))$ |
| [`reverseLinkedListII.cpp`](file:///home/legendneon/Backup/DSAPrograms/linked_lists/reverseLinkedListII.cpp) | LC 92: Reverse Linked List II | In-place subsegment reversal | $O(N)$ |
| [`ReverseKGroup.cpp`](file:///home/legendneon/Backup/DSAPrograms/linked_lists/ReverseKGroup.cpp) | LC 25: Reverse Nodes in k-Group | Iterative $K$-group reversal | $O(N)$ |
| [`rotateList.cpp`](file:///home/legendneon/Backup/DSAPrograms/linked_lists/rotateList.cpp) | LC 61: Rotate List | Ring connection and $k \pmod L$ cut | $O(N)$ |
| [`oddEvenLinkedList.cpp`](file:///home/legendneon/Backup/DSAPrograms/linked_lists/oddEvenLinkedList.cpp) | LC 328: Odd Even Linked List | Two sublists interwoven splicing | $O(N)$ |
| [`partitionList.cpp`](file:///home/legendneon/Backup/DSAPrograms/linked_lists/partitionList.cpp) | LC 86: Partition List | Less-than / Greater-equal dummy chains | $O(N)$ |
| [`copyListRandomPointer.cpp`](file:///home/legendneon/Backup/DSAPrograms/linked_lists/copyListRandomPointer.cpp) | LC 138: Copy List with Random Pointer | Interweaving cloned nodes in-place | $O(N)$ |
| [`randomPointer.cpp`](file:///home/legendneon/Backup/DSAPrograms/linked_lists/randomPointer.cpp) | Deep copy with random pointers | Hash map / interweave variant | $O(N)$ |
| [`2wayMergeList.cpp`](file:///home/legendneon/Backup/DSAPrograms/linked_lists/2wayMergeList.cpp) | LC 21: Merge Two Sorted Lists | Two-pointer iterative merge | $O(N + M)$ |
| [`mergeKSortList.cpp`](file:///home/legendneon/Backup/DSAPrograms/linked_lists/mergeKSortList.cpp) | LC 23: Merge k Sorted Lists | Min-heap or divide-and-conquer merge | $O(N \log K)$ |
| [`insertionSortList.cpp`](file:///home/legendneon/Backup/DSAPrograms/linked_lists/insertionSortList.cpp) | LC 147: Insertion Sort List | Dummy head insertion traversal | $O(N^2)$ |
| [`sortList.cpp`](file:///home/legendneon/Backup/DSAPrograms/linked_lists/sortList.cpp) | LC 148: Sort List | Top-down Merge Sort | $O(N \log N)$ |
