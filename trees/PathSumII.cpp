/**
 * 113. Path Sum II (Leetcode Medium)
 * 
 * Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. 
 * Each path should be returned as a list of the node values, not node references.
 * A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.
 */

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root) return {};
        if (!root->left && !root->right && root->val == targetSum) return {{targetSum}};

        vector<vector<int>> choice1, choice2;
        if (root->left) choice1 = pathSum(root->left, targetSum-root->val);
        if (root->right) choice2 = pathSum(root->right, targetSum-root->val);

        for (int i=0;i<choice1.size();i++) choice1[i].insert(choice1[i].begin(), root->val);
        for (int i=0;i<choice2.size();i++){
            choice2[i].insert(choice2[i].begin(), root->val);
            choice1.push_back(choice2[i]);
        }

        return choice1;        
    }
};


int main() {
    Solution sol;
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);

    vector<vector<int>> result = sol.pathSum(root, 22);
    for (const auto& path : result) {
        for (int val : path) {
            cout << val << " ";
        }        cout << endl;
    }  

    return 0;
}
