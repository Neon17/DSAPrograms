/**
 * 109. Convert Sorted List to Binary Search Tree (Leetcode Medium)

    Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height-balanced binary search tree.
    A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

    Example 1:
    Input: head = [-10,-3,0,5,9]
    Output: [0,-3,9,-10,null,5]

    Example 2:
    Input: head = []
    Output: []

    Constraints:
    The number of nodes in head is in the range [0, 2 * 104].
    -105 <= Node.val <= 105
 */

#include <iostream>
#include <cmath>
#include <unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
I think there should be 2 functions
1. Finding median of linked list and making it root of the tree
2. Recursively calling the function for left and right half of the linked list to make left and right subtree of the root respectively
*/

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        TreeNode* tree;
        if (!head) return nullptr;
        
        tree = new TreeNode();
        ListNode* temp = head;
        int size = 0;
        while (temp){
            size++;
            temp = temp->next;
        }
        cout << size << endl;
        partition(head, size, tree);
        return tree;
    }

    void partition(ListNode* head, int size, TreeNode* tree, int start = 1){
        if (size < 1) return;
        int end = start + size - 1;
        int mid = ceil((start + end + 1)/2);
        
        ListNode* temp = head;
        for (int i=1;i<mid;i++){
            temp = temp->next;
        }
        cout << start << " " << end << " " << mid << " "<<size<<", value = " << temp->val << endl;
        tree->val = temp->val;

        if (size == 1) return;
        if (mid-1 >= start){
            tree->left = new TreeNode();
            partition(head, mid-start, tree->left, start);
        }
        if (mid+1 <= end){
            tree->right = new TreeNode();
            partition(head, end-mid, tree->right, mid+1);
        }
    }
};

void output(TreeNode* tree){
    if (tree == nullptr) return;
    cout << tree->val << " ";
    output(tree->left);
    output(tree->right);
}

int main(){
    Solution s;
    // ListNode* head = new ListNode(-10);
    // head->next = new ListNode(-3);
    // head->next->next = new ListNode(0);
    // head->next->next->next = new ListNode(5);
    // head->next->next->next->next = new ListNode(9);

    ListNode* head = nullptr;
    TreeNode* tree = s.sortedListToBST(head);
    cout << "Preorder Traversal of the tree: ";
    output(tree);
    return 0;
}

