# 🔢 Mathematics & Bit Manipulation Guide

Mathematical algorithms focus on prime factorization, modular exponentiation, binary representation, and bitwise tricks.

---

## 🧠 Core Mental Models

### 1. Sieve of Eratosthenes ($O(N \log \log N)$)
- Find all primes up to $N$ by marking multiples of each prime starting from $p^2$.

### 2. Binary Exponentiation ($O(\log N)$)
- Compute $x^n$ by squaring $x$ when $n$ is even and multiplying once when $n$ is odd:
  $$x^n = (x^2)^{n/2} \quad \text{if } n \text{ is even}, \quad x \times x^{n-1} \quad \text{if } n \text{ is odd}$$

### 3. Bitwise XOR Partitioning (Single Number III)
- Given array where all numbers appear twice except two numbers $A$ and $B$:
  - Total XOR: $X = A \oplus B$.
  - Find lowest set bit: `diff = X & (-X)`.
  - Partition all numbers into two groups based on this bit. XORing each group reveals $A$ and $B$ independently!

---

## 📂 Folder Contents

| File | Problem | Technique | Complexity |
| :--- | :--- | :--- | :--- |
| [`sieveErasthothenes.cpp`](file:///home/legendneon/Backup/DSAPrograms/maths/sieveErasthothenes.cpp) | Sieve of Eratosthenes | Prime generator | $O(N \log \log N)$ |
| [`pow.cpp`](file:///home/legendneon/Backup/DSAPrograms/maths/pow.cpp) | LC 50: Pow(x, n) | Binary Exponentiation | $O(\log N)$ |
| [`superpow.cpp`](file:///home/legendneon/Backup/DSAPrograms/maths/superpow.cpp) | LC 372: Super Pow | Modular arithmetic with large array exponent | $O(\text{digits} \times \log 10)$ |
| [`divide2Integers.cpp`](file:///home/legendneon/Backup/DSAPrograms/maths/divide2Integers.cpp) | LC 29: Divide Two Integers | Bit shifting subtraction without `*`, `/`, `%` | $O(\log^2 N)$ |
| [`singleNumberIII.cpp`](file:///home/legendneon/Backup/DSAPrograms/maths/singleNumberIII.cpp) | LC 260: Single Number III | XOR sum + lowest set bit partition | $O(N)$ Time, $O(1)$ Space |
| [`kFactorN.cpp`](file:///home/legendneon/Backup/DSAPrograms/maths/kFactorN.cpp) | LC 1492: The kth Factor of n | $O(\sqrt{N})$ factor enumeration | $O(\sqrt{N})$ |
