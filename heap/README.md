# 🏔️ Heap & Priority Queue Guide

Heaps are complete binary trees providing $O(1)$ lookup for the maximum (or minimum) element and $O(\log N)$ insertions and deletions.

---

## 🧠 Mental Model: When to Use

### 1. Two-Heap Pattern (Median of a Stream)
- Maintain two balanced heaps:
  - `max_heap` stores the smaller half of numbers.
  - `min_heap` stores the larger half of numbers.
- Maintain size invariant: `max_heap.size() == min_heap.size()` or `max_heap.size() == min_heap.size() + 1`.
- Median is either top of `max_heap` or average of tops!

### 2. Greedy Frequency Rearrangement (Task Scheduler / Reorganize String)
- Always pick the most frequent available character/task first (via max-heap).
- Put items on a cooldown queue until they become eligible again.

### 3. Event Scheduling (Single-Threaded CPU / Meeting Rooms III)
- Sort tasks/meetings by start time.
- Use a min-heap to track currently available resources (rooms, CPU cores) and another min-heap to track ongoing events by completion time.

---

## 📂 Folder Contents

| File | Problem | Pattern | Complexity |
| :--- | :--- | :--- | :--- |
| [`maxheap.cpp`](file:///home/legendneon/Backup/DSAPrograms/heap/maxheap.cpp) | Custom Max Heap implementation | Array-based binary heap with heapify | $O(\log N)$ push/pop |
| [`FindMedianDataStream.cpp`](file:///home/legendneon/Backup/DSAPrograms/heap/FindMedianDataStream.cpp) | LC 295: Find Median from Data Stream | Dual Heaps (Max-Heap + Min-Heap) | $O(\log N)$ add, $O(1)$ find |
| [`KClosestPoint.cpp`](file:///home/legendneon/Backup/DSAPrograms/heap/KClosestPoint.cpp) | LC 973: K Closest Points to Origin | Max-Heap of size $K$ | $O(N \log K)$ |
| [`ReorganizeString.cpp`](file:///home/legendneon/Backup/DSAPrograms/heap/ReorganizeString.cpp) | LC 767: Reorganize String | Max-Heap frequency pair greedy pop | $O(N \log \Sigma)$ |
| [`TaskScheduler.cpp`](file:///home/legendneon/Backup/DSAPrograms/heap/TaskScheduler.cpp) | LC 621: Task Scheduler | Max-Heap with wait-queue cooldown | $O(N)$ |
| [`SingleThreadedCPU.cpp`](file:///home/legendneon/Backup/DSAPrograms/heap/SingleThreadedCPU.cpp) | LC 1834: Single-Threaded CPU | Event simulation with min-heap | $O(N \log N)$ |
| [`MeetingRoomsIII.cpp`](file:///home/legendneon/Backup/DSAPrograms/heap/MeetingRoomsIII.cpp) | LC 2402: Meeting Rooms III | Two min-heaps: available & busy rooms | $O(M \log N)$ |
