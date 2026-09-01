/*
    Leetcode Medium 437. Path Sum III

    Given the root of a binary tree and an integer targetSum, 
        return the number of paths where the sum of the values along the path equals targetSum.

    The path does not need to start or end at the root or a leaf, 
         but it must go downwards (i.e., traveling only from parent nodes to child nodes).

    Constraints:
    The number of nodes in the tree is in the range [0, 1000].
    -109 <= Node.val <= 109
    -1000 <= targetSum <= 1000
*/

#include <iostream>
#include <vector>
#include <unordered_map>
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
    int count = 0;
    unordered_map<TreeNode*, pair<int, int>> memo; // memoization for (node, targetSum, curr) pairs
    unordered_map<long long, int> visited;
public:
    void dfs(TreeNode* root, int targetSum, long long curr = 0, bool isNewPath = true) {
        if (!root) return;
        if (isNewPath && memo.find(root) != memo.end() && memo[root].first == targetSum && memo[root].second == curr) {
            return;
        }
        if (isNewPath) {
            memo[root] = {targetSum, curr};
        }
        long long newcurr = curr + root->val;
        if (targetSum == newcurr) count++;

        dfs(root->left, targetSum, newcurr, false);
        dfs(root->right, targetSum, newcurr, false);
        dfs(root->left, targetSum);
        dfs(root->right, targetSum); 
    }

    int pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return count;
    }

    void dfsOptimal(TreeNode* root, int targetSum, long long prefix=0){
        if (!root) return;
        long long curr = root->val + prefix;
        
        if (visited.count(curr - targetSum)) count += visited[curr - targetSum];
        visited[curr]++;

        dfsOptimal(root->left, targetSum, curr);
        dfsOptimal(root->right, targetSum, curr);

        if (--visited[curr] == 0) visited.erase(curr);
    }

    int optimalPathSum(TreeNode* root, int targetSum){
        count = 0;
        visited[0] = 1;
        dfsOptimal(root, targetSum);
        return count;
    }
};

int main(){
    Solution s;
    TreeNode* root; int targetSum; 

    root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(11);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right->right = new TreeNode(1);
    targetSum = 8;
    // cout << s.pathSum(root, targetSum) << endl;
    cout << s.optimalPathSum(root, targetSum) << endl;

    root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);   
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);
    targetSum = 22;
    // cout << s.pathSum(root, targetSum) << endl;
    cout << s.optimalPathSum(root, targetSum) << endl;

    return 0;
}
