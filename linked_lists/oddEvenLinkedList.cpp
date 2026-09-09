/*
    Leetcode Medium 328. Odd Even Linked List

    Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, 
         and return the reordered list.

    The first node is considered odd, and the second node is even, and so on.

    Note that the relative order inside both the even and odd groups should remain as it was in the input.

    You must solve the problem in O(1) extra space complexity and O(n) time complexity.

    Constraints:
        The number of nodes in the linked list is in the range [0, 104].
        -10^6 <= Node.val <= 10^6
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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return head;
        ListNode* left = head;
        ListNode* right = head->next;
        ListNode* temp = head->next;
        int ind = 3;

        while (temp->next){
            if (ind % 2 != 0){
                ListNode* next = temp->next->next;
                temp->next->next = left->next;
                left->next = temp->next;
                temp->next = next;
                left = left->next;
                ind++;
                continue;
            }
            right = right->next;
            temp = temp->next;
            ind++;
        }
        return head;
    }
};

int main(){
    Solution solution;
    ListNode* l1;

    l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(3);
    l1->next->next->next = new ListNode(4);
    l1->next->next->next->next = new ListNode(5);
    solution.oddEvenList(l1);
    printList(l1);

    l1 = new ListNode(2);
    l1->next = new ListNode(1);
    l1->next->next = new ListNode(3);
    l1->next->next->next = new ListNode(5);
    l1->next->next->next->next = new ListNode(6);
    l1->next->next->next->next->next = new ListNode(4);
    l1->next->next->next->next->next->next = new ListNode(7);
    solution.oddEvenList(l1);
    printList(l1);

    return 0;
}

