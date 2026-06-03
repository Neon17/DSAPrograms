/**
 * 1123. Lowest Common Ancestor of Deepest Leaves (Leetcode Medium)
 * Given the root of a binary tree, return the lowest common ancestor of its deepest leaves.
 *
 * Recall that:
 *  
 * The node of a binary tree is a leaf if and only if it has no children
 * The depth of the root of the tree is 0. if the depth of a node is d, the depth of each of its children is d + 1.
 * The lowest common ancestor of a set S of nodes, is the node A with the largest depth such that every node in S is in the subtree with root A.
 * 
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4]
 * Output: [2,7,4]
 * Explanation: We return the node with value 2, colored in yellow in the diagram.
 * The nodes coloured in blue are the deepest leaf-nodes of the tree.
 * Note that nodes 6, 0, and 8 are also leaf nodes, but the depth of them is 2, but the depth of nodes 7 and 4 is 3.
 * 
 * Input: root = [0,1,3,null,2]
 * Output: [2]
 * Explanation: The deepest leaf node in the tree is 2, the lca of one node is itself.
 * 
 * Constraints:
 * 
 * The number of nodes in the tree will be in the range [1, 1000].
 * 0 <= Node.val <= 1000
 * The values of the nodes in the tree are unique.
 * 
 * Topics: Hash Table, Tree, Depth-First Search, Breadth-First Search, Binary Tree
 */

#include<iostream>
#include<vector>
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
private:
    int maxdepth = 0;
    void dfs(TreeNode* root, vector<TreeNode*>& deepest, int depth=0){
        if (!root) return;

        if (!root->left && !root->right){
            if (depth > maxdepth){
                maxdepth = depth;
                deepest.clear();
                deepest.push_back(root);
            } else if (depth == maxdepth){
                deepest.push_back(root);
            }
        }
        dfs(root->left, deepest, depth+1);
        dfs(root->right, deepest, depth+1);
    }

    bool ancestor(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& ans){
        if (!root) return false;

        int left = ancestor(root->left, p, q, ans);
        int right = ancestor(root->right, p, q, ans);
        int mid = (root == p || root == q);

        if (left + right + mid >= 2) ans = root;
        return (left + right + mid) > 0;
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        vector<TreeNode*> deepest;
        dfs(root, deepest);
        if (deepest.empty()) return nullptr;
        if (deepest.size() == 1) return deepest[0];
        int size = deepest.size();
        TreeNode* temp;
        for (int i=0;i<size-1;i++){
            temp = nullptr;
            ancestor(root, deepest[0], deepest[1], temp);
            deepest.erase(deepest.begin());
            deepest.erase(deepest.begin());
            deepest.insert(deepest.begin(), temp);
        }
        return temp;
    }
};

void printTree(TreeNode* root){
    if (!root) return;
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

int main() {
    Solution sol;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);   
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode* lca = sol.lcaDeepestLeaves(root);
    cout << "[ ";
    printTree(lca);
    cout << "]" << endl;

    return 0;
}
