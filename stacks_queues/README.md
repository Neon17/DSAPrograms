# 📚 Stacks and Queues Pattern Guide

Stacks (LIFO) and Queues (FIFO) form the backbone of buffer management, expression evaluation, and the ultra-important **Monotonic Stack** technique.

---

## 🧠 Mental Model: Monotonic Stack

A **Monotonic Stack** maintains its elements in strictly increasing or decreasing order. Whenever an incoming element violates the monotonic invariant, elements are popped.

### When to Use:
1. **Next Greater Element (NGE) / Next Smaller Element (NSE)**: Finding the first element to the left or right that is strictly greater or smaller in $O(N)$ total operations.
2. **Span & Histogram Boundaries**:
   - For each bar $i$, how far left and right can a rectangle of height $h[i]$ extend?
   - The left boundary is the Previous Smaller Element; the right boundary is the Next Smaller Element!
3. **Lexicographical Optimization (Remove K Digits / Remove Duplicate Letters)**:
   - Pop previous larger characters if more occurrences of those characters exist later in the string or if we have remaining removals allowed ($K > 0$).
4. **Contribution to All Subarrays**:
   - In *Sum of Subarray Minimums*: for each element `nums[i]`, count how many subarrays have `nums[i]` as the minimum:
     $$\text{count} = (\text{index}_i - \text{prev\_smaller}_i) \times (\text{next\_smaller}_i - \text{index}_i)$$

---

## 📂 Folder Contents

| File | Problem / Concept | Technique | Complexity |
| :--- | :--- | :--- | :--- |
| [`linearqueue.cpp`](file:///home/legendneon/Backup/DSAPrograms/stacks_queues/linearqueue.cpp) | Static linear queue | Array-based implementation | $O(1)$ ops |
| [`circularqueue.cpp`](file:///home/legendneon/Backup/DSAPrograms/stacks_queues/circularqueue.cpp) | Circular queue with modulo arithmetic | Ring buffer | $O(1)$ ops |
| [`priorityQueue.cpp`](file:///home/legendneon/Backup/DSAPrograms/stacks_queues/priorityQueue.cpp) | Priority queue implementation | Custom heap operations | $O(\log N)$ |
| [`stackInfixPrefix.cpp`](file:///home/legendneon/Backup/DSAPrograms/stacks_queues/stackInfixPrefix.cpp) | Infix to Postfix/Prefix conversion | Operator precedence stack | $O(N)$ |
| [`evaluateReversePolish.cpp`](file:///home/legendneon/Backup/DSAPrograms/stacks_queues/evaluateReversePolish.cpp) | LC 150: Evaluate Reverse Polish Notation | Operand stack evaluation | $O(N)$ |
| [`largestRectangleHistogram.cpp`](file:///home/legendneon/Backup/DSAPrograms/stacks_queues/largestRectangleHistogram.cpp) | LC 84: Largest Rectangle in Histogram | Monotonic increasing stack (NSE/PSE) | $O(N)$ |
| [`maximalRectangle.cpp`](file:///home/legendneon/Backup/DSAPrograms/stacks_queues/maximalRectangle.cpp) | LC 85: Maximal Rectangle | Row-by-row histogram reduction | $O(R \times C)$ |
| [`RemoveKDigits.cpp`](file:///home/legendneon/Backup/DSAPrograms/stacks_queues/RemoveKDigits.cpp) | LC 402: Remove K Digits | Monotonic increasing stack with $K$ quota | $O(N)$ |
| [`RemoveDuplicateLetter.cpp`](file:///home/legendneon/Backup/DSAPrograms/stacks_queues/RemoveDuplicateLetter.cpp) | LC 316: Remove Duplicate Letters | Monotonic stack + frequency map + seen set | $O(N)$ |
| [`sumSubarrayMinimums.cpp`](file:///home/legendneon/Backup/DSAPrograms/stacks_queues/sumSubarrayMinimums.cpp) | LC 907: Sum of Subarray Minimums | Contribution technique with PSE & NSE | $O(N)$ |
| [`sumSubarrayRanges.cpp`](file:///home/legendneon/Backup/DSAPrograms/stacks_queues/sumSubarrayRanges.cpp) | LC 2104: Sum of Subarray Ranges | $\sum \text{Maxes} - \sum \text{Mins}$ using monotonic stacks | $O(N)$ |
