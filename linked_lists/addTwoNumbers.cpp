/*
    Leetcode Medium 2. Add Two Numbers

    You are given two non-empty linked lists representing two non-negative integers. 
    The digits are stored in reverse order, and each of their nodes contains a single digit. 
    Add the two numbers and return the sum as a linked list.

    You may assume the two numbers do not contain any leading zero, except the number 0 itself.

    Constraints:
    The number of nodes in each linked list is in the range [1, 100].
    0 <= Node.val <= 9
    It is guaranteed that the list represents a number that does not have leading zeros.
*/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
        ListNode* curr = res;

        ListNode* temp = l1;
        ListNode* temp2 = l2;
        int carryover = 0, sum = 0;

        while (temp || temp2){
            if (temp && temp2){
                sum = temp->val + temp2->val + carryover;
                temp = temp->next;
                temp2 = temp2->next;
            } else if (temp){
                sum = temp->val + carryover;
                temp = temp->next;
            } else {
                sum = temp2->val + carryover;
                temp2 = temp2->next;
            }
            carryover = sum/10;
            sum = sum%10;
            curr->next = new ListNode(sum);
            curr = curr->next;
        }
        if (carryover > 0) curr->next = new ListNode(carryover);
        return res->next;
    }
};

int main(){
    Solution solution;
    ListNode* l1, *l2, *l3;

    l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    l2 = new ListNode(5);   
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    l3 = solution.addTwoNumbers(l1, l2);
    printList(l3);

    l1 = new ListNode(0);
    l2 = new ListNode(0);
    l3 = solution.addTwoNumbers(l1, l2);
    printList(l3);

    l1 = new ListNode(9);
    l1->next = new ListNode(9);
    l1->next->next = new ListNode(9);
    l1->next->next->next = new ListNode(9);
    l1->next->next->next->next = new ListNode(9);
    l1->next->next->next->next->next = new ListNode(9);
    l1->next->next->next->next->next->next = new ListNode(9);
    l2 = new ListNode (9);
    l2->next = new ListNode(9);
    l2->next->next = new ListNode(9);
    l2->next->next->next = new ListNode(9);
    l3 = solution.addTwoNumbers(l1, l2);
    printList(l3);

    return 0;
}
