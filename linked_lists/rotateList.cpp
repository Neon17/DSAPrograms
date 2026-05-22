/**
 * Leetcode Medium 61. Rotate List
 * Companies: Microsoft, Amazon, Google, Facebook, Apple, Adobe, Uber, LinkedIn
 * 
 * Given the head of a linked list, rotate the list to the right by k places.
 * 
 * Example 1:
 * Input: head = [1,2,3,4,5], k = 2
 * Output: [4,5,1,2,3]
 * 
 * Example 2:
 * Input: head = [0,1,2], k = 4
 * Output: [2,0,1]
 * 
 * Constraints:
 * The number of nodes in the list is in the range [0, 500].
 * -100 <= Node.val <= 100
 * 0 <= k <= 2 * 109
 * 
 * 
 * I realized later (was so easy, but bruteforced at earler)
 * 1. Make cyclic linked list
 * 2. Find out tail from size-k-1
 * 3. Then tail->next is returned and doing tail->next = NULL to unlink them
 */

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // Brute Force Solution: O(n*k) time complexity, O(n) space complexity
    // ListNode* rotateRight(ListNode* head, int k) {
    //     if (!head || !head->next) return head;
    //     ListNode* temp = head;
    //     ListNode* newhead = new ListNode(0);
    //     ListNode* tempp = newhead;
    //     ListNode* right;
    //     int size = 0;

    //     while (temp){
    //         tempp->next = new ListNode(temp->val);
    //         temp = temp->next;
    //         tempp = tempp->next;
    //         right = tempp;
    //         size++;
    //     }

    //     k = k % size;
    //     if (k==0) return head;
    //     ListNode* left = newhead->next;

    //     for (int i=0;i<k;i++){
    //         ListNode* tempo = left;
    //         while (tempo->next->next){
    //             tempo = tempo->next;
    //         }
    //         ListNode* first = tempo->next;
    //         right = tempo;
    //         tempo->next = NULL;
    //         first->next = left;
    //         left = first;
    //     }

    //     return left;
    // }

    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        ListNode* temp = head;
        ListNode* newhead;
        int size = 1;

        while (temp->next){
            temp = temp->next;
            size++;
        }
        k = k % size;
        if (k == 0) return head;
        temp->next = head;
        temp = head; // finding tail in this variable temp by below for loop

        for (int i=0;i<(size-k-1);i++) temp = temp->next;
        newhead = temp->next;
        temp->next = NULL;

        return newhead;
    }
};

ListNode* input(vector<int> headval){
    // ListNode dummy(0);
    // ListNode* temp = &dummy;

    // for (int i=0;i<headval.size();i++){
    //     temp->next = new ListNode(headval[i]);
    //     temp = temp->next;
    // }
    // return dummy.next;

    // we can select either above way or below way

    ListNode* head = new ListNode(0);
    ListNode* temp = head;

    for (int i=0;i<headval.size();i++){
        temp->next = new ListNode(headval[i]);
        temp = temp->next;
    }
    return head->next;
}

void output(ListNode* head){
    ListNode* temp = head;
    cout<<"[";
    while (temp){
        cout<<temp->val;
        temp = temp->next;
        if (temp) cout<<",";
    }
    cout<<"]"<<endl;
}

void printResult(ListNode* head, ListNode* ans, int k){
    cout<<"Input: k = "<<k<<", array = ";  output(head);
    cout<<"Output: "; output(ans);
    cout<<endl;
}

int main() {
    ListNode* head=NULL;
    ListNode* ans=NULL;
    Solution s;
    vector<int> headval;
    int k = 0;

    headval = {1,2,3,4,5}; k = 7;
    head = input(headval);
    ans = s.rotateRight(head, k);
    printResult(head, ans, k);

    headval={1,2}, k=10;
    head = input(headval);
    ans = s.rotateRight(head, k);
    printResult(head, ans, k);
    

    return 0;
}
