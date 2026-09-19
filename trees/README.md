# 🌲 Binary Trees and Binary Search Trees (BST) Guide

Trees are hierarchical recursive structures. Most tree problems are naturally solved using either Depth-First Search (DFS: Preorder, Inorder, Postorder) or Breadth-First Search (BFS / Level Order).

---

## 🧠 Mental Model: How to Approach

### 1. DFS Traversal Choice
- **Preorder (Root, Left, Right):** Path construction, cloning, serialization.
- **Inorder (Left, Root, Right):** Generates **sorted order** in BSTs! Crucial for validating BSTs or finding $k$-th smallest elements.
- **Postorder (Left, Right, Root):** Bottom-up aggregation. Use when children must be evaluated before computing the parent's answer (e.g., Tree Height, Diameter, Maximum Path Sum, Maximum Sum BST).

### 2. Lowest Common Ancestor (LCA)
- Recurse on left and right subtrees:
  - If current node matches $p$ or $q$, return current node.
  - If both subtrees return non-null, current node is the LCA!
  - If only one subtree returns non-null, propagate that non-null node upwards.

### 3. Tree Reconstruction
- Unique reconstruction requires **Inorder** + (either **Preorder** or **Postorder**).
- The root is at the boundary of Preorder (start) or Postorder (end).
- Looking up the root in Inorder divides the tree into left and right subtrees.

---

## 📂 Folder Contents

| File | Problem / Concept | Technique | Complexity |
| :--- | :--- | :--- | :--- |
| [`binarySearchTree.cpp`](file:///home/legendneon/Backup/DSAPrograms/trees/binarySearchTree.cpp) | Basic BST operations | Insert, search, delete, traversal | $O(H)$ |
| [`BST.cpp`](file:///home/legendneon/Backup/DSAPrograms/trees/BST.cpp) | Complete BST structure | Implementation & verification | $O(H)$ |
| [`LCA.cpp`](file:///home/legendneon/Backup/DSAPrograms/trees/LCA.cpp) | LC 236: Lowest Common Ancestor | Recursive postorder bubbling | $O(N)$ |
| [`LCADeepestLeaves.cpp`](file:///home/legendneon/Backup/DSAPrograms/trees/LCADeepestLeaves.cpp) | LC 1123: LCA of Deepest Leaves | Subtree depth comparison | $O(N)$ |
| [`PathSumII.cpp`](file:///home/legendneon/Backup/DSAPrograms/trees/PathSumII.cpp) | LC 113: Path Sum II | Backtracking root-to-leaf paths | $O(N)$ |
| [`PathSumIII.cpp`](file:///home/legendneon/Backup/DSAPrograms/trees/PathSumIII.cpp) | LC 437: Path Sum III | Prefix sum hash map on tree path | $O(N)$ |
| [`constructPostInOrder.cpp`](file:///home/legendneon/Backup/DSAPrograms/trees/constructPostInOrder.cpp) | LC 106: Construct from Inorder & Postorder | Index hash map & interval recursion | $O(N)$ |
| [`sortedToBinarySearchTree.cpp`](file:///home/legendneon/Backup/DSAPrograms/trees/sortedToBinarySearchTree.cpp) | LC 108: Sorted Array to Balanced BST | Divide and conquer at midpoint | $O(N)$ |
| [`maximumSumBSTBInaryTree.cpp`](file:///home/legendneon/Backup/DSAPrograms/trees/maximumSumBSTBInaryTree.cpp) | LC 1373: Maximum Sum BST in Binary Tree | Postorder tuple `{isBST, sum, minVal, maxVal}` | $O(N)$ |
