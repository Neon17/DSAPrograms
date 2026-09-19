# 🔤 String Operations & String DP Guide

String problems encompass parsing, simulations, big integer arithmetic, palindromic structures, and classic 2D String Dynamic Programming (Edit Distance, Longest Common Subsequence).

---

## 🧠 Mental Model: 2D String DP Matrix

When comparing two strings $S$ (length $M$) and $T$ (length $N$), let `dp[i][j]` be the optimal cost/length considering prefix $S[0 \dots i-1]$ and $T[0 \dots j-1]$:
- If characters match ($S[i-1] == T[j-1]$): `dp[i][j] = dp[i-1][j-1]` (zero cost transition).
- If characters differ: take the best choice among:
  - Insertion: `dp[i][j-1] + 1`
  - Deletion: `dp[i-1][j] + 1`
  - Replacement: `dp[i-1][j-1] + 1`

---

## 📂 Folder Contents

| File | Problem | Pattern | Complexity |
| :--- | :--- | :--- | :--- |
| [`editDistance.cpp`](file:///home/legendneon/Backup/DSAPrograms/string_ops/editDistance.cpp) | LC 72: Edit Distance (Levenshtein) | 2D Insert/Delete/Replace DP | $O(M \times N)$ |
| [`delete2Strings.cpp`](file:///home/legendneon/Backup/DSAPrograms/string_ops/delete2Strings.cpp) | LC 583: Delete Operation for Two Strings | LCS reduction: $M + N - 2 \times \text{LCS}$ | $O(M \times N)$ |
| [`minOperationsPalindrome.cpp`](file:///home/legendneon/Backup/DSAPrograms/string_ops/minOperationsPalindrome.cpp) | Minimum Insertions to Make String Palindrome | $N - \text{LPS}(S)$ (Longest Palindromic Subsequence) | $O(N^2)$ |
| [`multiplyStrings.cpp`](file:///home/legendneon/Backup/DSAPrograms/string_ops/multiplyStrings.cpp) | LC 43: Multiply Strings | Elementary array digit multiplication | $O(M \times N)$ |
| [`SumMultiplyBigInt.cpp`](file:///home/legendneon/Backup/DSAPrograms/string_ops/SumMultiplyBigInt.cpp) | BigInt Addition & Multiplication | Arbitrary precision string simulation | $O(M \times N)$ |
| [`compareVersionNumbers.cpp`](file:///home/legendneon/Backup/DSAPrograms/string_ops/compareVersionNumbers.cpp) | LC 165: Compare Version Numbers | Dot-separated numeric parsing | $O(N + M)$ |
| [`textJustification.cpp`](file:///home/legendneon/Backup/DSAPrograms/string_ops/textJustification.cpp) | LC 68: Text Justification | Greedy line packing with distributed space | $O(N)$ |
| [`zigzagConversion.cpp`](file:///home/legendneon/Backup/DSAPrograms/string_ops/zigzagConversion.cpp) | LC 6: Zigzag Conversion | Direction-toggling row simulation | $O(N)$ |
| [`WordBreakII.cpp`](file:///home/legendneon/Backup/DSAPrograms/string_ops/WordBreakII.cpp) | LC 140: Word Break II | Memoized DFS / Backtracking + Trie | Exponential |
| [`substringRepeatedChar.cpp`](file:///home/legendneon/Backup/DSAPrograms/string_ops/substringRepeatedChar.cpp) | Longest Substring Without Repeating Characters | Sliding window with last seen map | $O(N)$ |
| [`stringEdit.cpp`](file:///home/legendneon/Backup/DSAPrograms/string_ops/stringEdit.cpp) | String edit operations & transformations | String mutation simulation | $O(N)$ |
