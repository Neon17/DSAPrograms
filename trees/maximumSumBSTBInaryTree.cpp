/*
1373. Maximum Sum BST in Binary Tree
Hard
Topics
premium lock icon
Companies
Hint
Given a binary tree root, return the maximum sum of all keys of any sub-tree which is also a Binary Search Tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 
Example 1:

Input: root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
Output: 20
Explanation: Maximum sum in a valid Binary search tree is obtained in root node with key equal to 3.
Example 2:

Input: root = [4,3,null,1,2]
Output: 2
Explanation: Maximum sum in a valid Binary search tree is obtained in a single root node with key equal to 2.
Example 3:

Input: root = [-4,-2,-5]
Output: 0
Explanation: All values are negatives. Return an empty BST.
 
Constraints:

The number of nodes in the tree is in the range [1, 4 * 104].
-4 * 104 <= Node.val <= 4 * 104
*/
#include <iostream>
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
    struct Node {
        int sumvalue = 0;
        int maxvalue = 0;
        int minvalue = 0;
        bool isbinary = false;
        Node():sumvalue(0), maxvalue(-1*(__INT32_MAX__-1)), minvalue(__INT32_MAX__), isbinary(true) {}
        Node(int sumvalue, int maxvalue, int minvalue, bool isbinary = false):sumvalue(sumvalue), maxvalue(maxvalue), minvalue(minvalue), isbinary(isbinary){}
    };
    int maximumsum = -1*(__INT32_MAX__-1);

    Node dfs(TreeNode* root){
        if (!root) return Node();
        Node left = dfs(root->left);
        Node right = dfs(root->right);

        int mini = min(left.minvalue, root->val);
        int maxi = max(right.maxvalue, root->val);
        int sumi = left.sumvalue + right.sumvalue + root->val;

        if (!left.isbinary || !right.isbinary)  return Node(sumi, mini, maxi, false);  
     
        if (root->val > left.maxvalue && root->val < right.minvalue){
            maximumsum = max(maximumsum, sumi);
            return Node(sumi, maxi, mini, true);
        } 
        return Node(sumi, maxi, mini, false);  
    };

    int maxSumBST(TreeNode* root) {
        maximumsum = -1*(__INT32_MAX__-1);
        Node temp = dfs(root);
        return (maximumsum > 0)? maximumsum:0;
    }
};

int main() {
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(4);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(5);
    root->right->right->left = new TreeNode(4);
    root->right->right->right = new TreeNode(6);
    cout << s.maxSumBST(root) << endl;

    root = new TreeNode(4);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    cout << s.maxSumBST(root) << endl;

    root = new TreeNode(-4);
    root->left = new TreeNode(-2);
    root->right = new TreeNode(-5);
    cout << s.maxSumBST(root) << endl;


    return 0;
}
