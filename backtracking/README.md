# 🔙 Backtracking Pattern Guide

Backtracking is a systematic method for exploring all possible decision trees. When a partial configuration violates constraints, the algorithm "backtracks" (undoes the previous choice) to explore alternative branches.

---

## 🧠 Mental Model: The Universal Template

```cpp
void backtrack(State& state, vector<Choice>& choices) {
    if (isSolution(state)) {
        recordSolution(state);
        return;
    }

    for (const auto& choice : choices) {
        if (!isValid(choice, state)) continue; // Pruning!

        makeChoice(state, choice);
        backtrack(state, choices);
        undoChoice(state, choice); // Clean up state
    }
}
```

### Key Techniques:
- **Pruning:** Early rejection of branches (e.g., bitmasks or lookup arrays for Queen column/diagonals in N-Queens, row/column/box checks in Sudoku).
- **Combinations vs Permutations:** 
  - Combinations: pass `startIndex` to prevent re-picking earlier elements.
  - Permutations: use a `visited` boolean array.
- **Shortest Transformations (Word Ladder):** BFS is optimal for shortest length; Backtracking/DFS with BFS-parent mapping is used to reconstruct **all shortest transformation paths** (Word Ladder II).

---

## 📂 Folder Contents

| File | Problem | Pattern | Complexity |
| :--- | :--- | :--- | :--- |
| [`generateParenthesisBacktrack.cpp`](file:///home/legendneon/Backup/DSAPrograms/backtracking/generateParenthesisBacktrack.cpp) | LC 22: Generate Parentheses | Counting open/close brackets | $O(\frac{4^N}{\sqrt{N}})$ |
| [`NQueens.cpp`](file:///home/legendneon/Backup/DSAPrograms/backtracking/NQueens.cpp) | LC 51: N-Queens | Column & Diagonal safety sets | $O(N!)$ |
| [`SudokuSolver.cpp`](file:///home/legendneon/Backup/DSAPrograms/backtracking/SudokuSolver.cpp) | LC 37: Sudoku Solver | Row/Col/Box constraint pruning | Exponential bounded |
| [`sumSubsetProblem.cpp`](file:///home/legendneon/Backup/DSAPrograms/backtracking/sumSubsetProblem.cpp) | Subset Sum Backtracking | Pick / skip recursion tree | $O(2^N)$ |
| [`01KnapsackBacktrack.cpp`](file:///home/legendneon/Backup/DSAPrograms/backtracking/01KnapsackBacktrack.cpp) | 0/1 Knapsack via Backtracking | Bounded weight pruning | $O(2^N)$ |
| [`regularExpressionBacktrack.cpp`](file:///home/legendneon/Backup/DSAPrograms/backtracking/regularExpressionBacktrack.cpp) | LC 10: Regular Expression Matching | Wildcard and star branching | Exponential |
| [`WordLadder.cpp`](file:///home/legendneon/Backup/DSAPrograms/backtracking/WordLadder.cpp) | LC 127: Word Ladder | BFS level-order shortest path | $O(N \times L \times 26)$ |
| [`WordLadder2.cpp`](file:///home/legendneon/Backup/DSAPrograms/backtracking/WordLadder2.cpp) | LC 126: Word Ladder II | BFS distance graph + DFS path reconstruction | Exponential worst-case |
