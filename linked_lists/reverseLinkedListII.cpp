/**
 * Leetcode Medium 92. Reverse Linked List II
 * 
 * Given the head of a singly linked list and two integers left and right where left <= right, 
 *  1. reverse the nodes of the list from position left to position right, 
 *  2. return the reversed list.
 * 
 * Example 1:
 * Input: head = [1,2,3,4,5], left = 2, right = 4
 * Output: [1,4,3,2,5]
 * 
 * Example 2:
 * Input: head = [5], left = 1, right = 1
 * Output: [5]
 * 
 * Constraints:
 * The number of nodes in the list is in the range [0, 200].
 * -100 <= Node.val <= 100
 * -200 <= x <= 200
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

ListNode* input(vector<int> headval){
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

void printVector(vector<int> v){
    cout<<"[";
    for (int i=0;i<v.size();i++){
        cout<<v[i];
        if (i!=v.size()-1) cout<<",";
    }
    cout<<"]"<<endl;
}

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head->next || left == right) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        for (int i=1;i<left;i++){
            prev = prev->next;
        }

        ListNode* curr = prev->next;
        for (int i=0;i<right-left;i++){
            ListNode* nextNode = curr->next;
            curr->next = nextNode->next;
            nextNode->next = prev->next;
            prev->next = nextNode;
        }
        return dummy.next;
    }
};

void printResult(vector<int> headval, ListNode* ans, int left, int right){
    cout<<"Input: left = "<<left<<", right = "<<right<<", array = ";  printVector(headval);
    cout<<"Output: "; output(ans);
    cout<<endl;
}

int main() {
    ListNode* head=NULL;
    ListNode* ans=NULL;
    Solution s;
    vector<int> headval;
    int left=0, right = 0;

    headval = {1,2,3,4,5}; left = 2; right = 3;
    head = input(headval);
    ans = s.reverseBetween(head, left, right);
    printResult(headval, ans, left, right);

    headval = {1,2,3,4,5}; left = 1; right = 5;
    head = input(headval);
    ans = s.reverseBetween(head, left, right);
    printResult(headval, ans, left, right);


    headval = {1,2,3,4,5}; left = 2; right = 4;
    head = input(headval);
    ans = s.reverseBetween(head, left, right);
    printResult(headval, ans, left, right);

    headval = {5}; left = 1, right = 2;
    head = input(headval);
    ans = s.reverseBetween(head, left, right);
    printResult(headval, ans, left, right);
}
