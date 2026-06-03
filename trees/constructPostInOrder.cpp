/**
 * 106. Construct Binary Tree from Inorder and Postorder Traversal (Leetcode Medium)
 * 
 * Given two integer arrays inorder and postorder where 
 * inorder is the inorder traversal of a binary tree and 
 * postorder is the postorder traversal of the same tree, 
 * construct and return the binary tree.
 * 
 * Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
 * Output: [3,9,20,null,null,15,7]
 * 
 * Input: inorder = [-1], postorder = [-1]
 * Output: [-1]
 * 
 * Constraints:
 * 
 * 1 <= inorder.length <= 3000
 * postorder.length == inorder.length
 * -3000 <= inorder[i], postorder[i] <= 3000
 * inorder and postorder consist of unique values.
 * Each value of postorder also appears in inorder.
 * inorder is guaranteed to be the inorder traversal of the tree.
 * postorder is guaranteed to be the postorder traversal of the tree.
 * 
 * Topics: Array, Hash Table, Tree, Divide and Conquer, Binary Tree
 * 
 * General Test Cases (inorder, postorder):
 * [9,3,15,20,7]
 * [9,15,7,20,3]
 * [-1]
 * [-1]
 * [10,9,3,11,15,20,7]
 * [10,9,11,15,7,20,3]
 * [4,2,5,6,1,3,8,9,7,10]
 * [4,5,6,2,9,8,10,7,3,1]
 * [3,2,6,17,1,7,5,9,8,4,10,14,13,11,20,15,19]
 * [6,2,1,7,17,3,8,9,5,14,13,20,19,15,11,10,4]
 */

#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>
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
    void splitBuild(TreeNode*& root, vector<int> inorder, vector<int> postorder, int low, int high, int low1, int high1) {
        if (high == low) {
            root->val = inorder[low];
            return;
        }
        if (high < low || high1 < low1) return;

        int ind1 = 0;
        for (int i=0;i<inorder.size();i++) {
            if (inorder[i] == postorder[high1]) {
                ind1 = i;
                break;
            }
        }
        root->val = postorder[high1];
        if (ind1 > low) {
            root->left = new TreeNode(0);
            unordered_set<int> leftSet(inorder.begin() + low, inorder.begin() + ind1);
            int newHigh1 = high1 - 1;
            while (newHigh1 >= low1 && leftSet.count(postorder[newHigh1])==0) {
                newHigh1--;
            }
            splitBuild(root->left, inorder, postorder, low, ind1-1, low1, newHigh1);
        }
        if (ind1 < high) {
            root->right = new TreeNode(0);
            unordered_set<int> rightSet(inorder.begin() + ind1 + 1, inorder.begin() + high + 1);
            int newLow = low1;
            while (newLow <= high1 && rightSet.count(postorder[newLow])==0) {
                newLow++;
            }
            splitBuild(root->right, inorder, postorder, ind1+1, high, newLow, high1 - 1);
        }
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* root = new TreeNode(0);
        if (inorder.size() == 1) {
            root->val = inorder[0];
            return root;
        }
        int high = inorder.size() - 1;
        splitBuild(root, inorder, postorder, 0, high, 0, high);
        return root;
    }
};

void printOrderByOrder(TreeNode* node) {
    queue<TreeNode*> q;
    q.push(node);

    while (!q.empty()) {
        int size = q.size();
        for (int i=0;i<size;i++) {
            TreeNode* curr = q.front();
            q.pop();
            if (curr) {
                cout<<curr->val<<" ";
                q.push(curr->left);
                q.push(curr->right);    
            } else {
                cout<<"null ";
            }
        }
    }
}

int main() {
    Solution sol;
    vector<vector<int>> orderCollection = {
        {9,3,15,20,7},
        {9,15,7,20,3},
        {-1},
        {-1},
        {10,9,3,11,15,20,7},
        {10,9,11,15,7,20,3},
        {4,2,5,6,1,3,8,9,7,10},
        {4,5,6,2,9,8,10,7,3,1},
        {3,2,6,17,1,7,5,9,8,4,10,14,13,11,20,15,19},
        {6,2,1,7,17,3,8,9,5,14,13,20,19,15,11,10,4}
    };

    for (int i=0;i<orderCollection.size();i+=2) {
        TreeNode* root = sol.buildTree(orderCollection[i], orderCollection[i+1]);
        cout<<"Order by Order Traversal of Constructed Tree: ";
        printOrderByOrder(root);
        cout<<endl;
    }
    return 0;
}
