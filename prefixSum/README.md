# ➕ Prefix Sum & Difference Array Pattern Guide

Prefix Sums convert range query calculations from $O(N)$ into $O(1)$ by precomputing running totals. The Difference Array technique applies range updates $[L, R] += \Delta$ in $O(1)$ time.

---

## 🧠 Mental Model: When to Use

### 1. Hash Map + Prefix Sum ($\text{Subarray Sum} = K$)
- Let $P[i] = \sum_{j=0}^{i} \text{nums}[j]$.
- The sum of subarray from $j+1$ to $i$ is $P[i] - P[j]$.
- To find if a subarray sum equals $K$: check if $P[i] - K$ exists in our hash map!

### 2. Modulo Arithmetic Subarrays ($\sum \text{nums} \pmod K == 0$)
- If $P[i] \pmod K == P[j] \pmod K$, the sum of elements between $j+1$ and $i$ is a multiple of $K$.
- Always handle negative remainders: `rem = ((rem % k) + k) % k`.

### 3. Difference Array (Line Sweep)
- For range update $[L, R]$ with $+x$:
  - `diff[L] += x`
  - `diff[R + 1] -= x`
- Running prefix sum over `diff` yields the final values for all points!

---

## 📂 Folder Contents

| File | Problem | Pattern | Complexity |
| :--- | :--- | :--- | :--- |
| [`contiguousArray.cpp`](file:///home/legendneon/Backup/DSAPrograms/prefixSum/contiguousArray.cpp) | LC 525: Contiguous Array | Treat 0 as -1, find longest sum 0 subarray | $O(N)$ |
| [`continuousSubarraySum.cpp`](file:///home/legendneon/Backup/DSAPrograms/prefixSum/continuousSubarraySum.cpp) | LC 523: Continuous Subarray Sum | Remainder modulo $K$ hash map | $O(N)$ |
| [`subarraySumDivisibleK.cpp`](file:///home/legendneon/Backup/DSAPrograms/prefixSum/subarraySumDivisibleK.cpp) | LC 974: Subarray Sums Divisible by K | Count prefix sum remainder frequencies | $O(N)$ |
| [`makeSumDivisibleP.cpp`](file:///home/legendneon/Backup/DSAPrograms/prefixSum/makeSumDivisibleP.cpp) | LC 1590: Make Sum Divisible by P | Shortest subarray removal with remainder target | $O(N)$ |
| [`corporateFlightBookings.cpp`](file:///home/legendneon/Backup/DSAPrograms/prefixSum/corporateFlightBookings.cpp) | LC 1109: Corporate Flight Bookings | 1D Difference Array | $O(N + Q)$ |
| [`MyCalendarII.cpp`](file:///home/legendneon/Backup/DSAPrograms/prefixSum/MyCalendarII.cpp) | LC 731: My Calendar II | Boundary sweep count $\le 2$ | $O(N^2)$ |
| [`MyCalendarIII.cpp`](file:///home/legendneon/Backup/DSAPrograms/prefixSum/MyCalendarIII.cpp) | LC 732: My Calendar III | Ordered map coordinate sweep maximum | $O(N \log N)$ |
| [`NumSubmatricesSumTarget.cpp`](file:///home/legendneon/Backup/DSAPrograms/prefixSum/NumSubmatricesSumTarget.cpp) | LC 1074: Number of Submatrices That Sum to Target | 2D Prefix Sum reduced to 1D Subarray Sum | $O(R^2 \times C)$ |
