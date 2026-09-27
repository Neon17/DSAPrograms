/*
Leetcode Medium 105. Construct Binary Tree from Preorder and Inorder Traversal

Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and 
    inorder is the inorder traversal of the same tree, construct and return the binary tree.

Constraints:
    1 <= preorder.length <= 3000
    inorder.length == preorder.length
    -3000 <= preorder[i], inorder[i] <= 3000
    preorder and inorder consist of unique values.
    Each value of inorder also appears in preorder.
    preorder is guaranteed to be the preorder traversal of the tree.
    inorder is guaranteed to be the inorder traversal of the tree.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void printTree(TreeNode* root) {
    if (!root) {
        cout << "null\n";
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int sz = q.size();

        for (int i = 0; i < sz; ++i) {
            TreeNode* node = q.front();
            q.pop();

            cout << node->val << " ";

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    cout << "\n";
}

class Solution {
    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int& preindex, int left = 0, int right = 0){   
        if (right < left || preindex >= preorder.size()) return nullptr;
        
        TreeNode* root = new TreeNode(preorder[preindex]);
        if (left == right) {
            preindex++;
            return root;
        }

        int ind = 0;
        for (int i = left; i <= right; i++){
            if (preorder[preindex] == inorder[i]){
                ind = i; break;
            }
        }
        preindex++;

        root->left = dfs(preorder, inorder, preindex, left, ind-1);
        root->right = dfs(preorder, inorder, preindex, ind+1, right);                
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root;
        int preindex = 0;

        root = dfs(preorder, inorder, preindex, 0, inorder.size() - 1);
        return root;
    }
};

int main() {
    Solution sol;
    vector<int> preorder, inorder;

    preorder = {3,9,20,15,7};
    inorder = {9,3,15,20,7};
    TreeNode* root = sol.buildTree(preorder, inorder);
    printTree(root);

    preorder = {-1};
    inorder = {-1};
    root = sol.buildTree(preorder, inorder);
    printTree(root);

    return 0;
}

