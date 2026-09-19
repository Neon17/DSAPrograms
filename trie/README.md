# 🌲 Trie (Prefix Tree) Guide

A **Trie** is a tree data structure used for locating specific keys within a set, especially strings with common prefixes or bitwise binary prefixes.

---

## 🧠 Mental Model & Core Structure

Each node stores an array/map of child pointers and a flag indicating end-of-word:
```cpp
struct TrieNode {
    TrieNode* children[26] = {nullptr};
    bool isEndOfWord = false;
};
```
- **Insert:** $O(L)$ where $L$ is word length.
- **Search / StartsWith:** $O(L)$ prefix traversal.

---

## 📂 Folder Contents

| File | Problem | Pattern | Complexity |
| :--- | :--- | :--- | :--- |
| [`implementrie.cpp`](file:///home/legendneon/Backup/DSAPrograms/trie/implementrie.cpp) | LC 208: Implement Trie (Prefix Tree) | Standard 26-ary pointer tree | $O(L)$ per op |
