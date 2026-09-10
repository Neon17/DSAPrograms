/*
    Leetcode Medium 148. Sort List

    Given the head of a linked list, return the list after sorting it in ascending order.

    Constraints:
    The number of nodes in the list is in the range [0, 5 * 10^4].
    -10^5 <= Node.val <= 10^5
*/
#include <iostream>
#include <cmath>
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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        int size = 0;
        ListNode dummy(0);
        dummy.next = head;

        for (ListNode* p = head; p; p = p->next) size++;

        for (int width = 1; width < size; width *= 2){
            ListNode* curr = dummy.next;
            ListNode* tail = &dummy;

            while (curr){
                ListNode* left = curr;
                ListNode* right = split(left, width);
                curr = split(right, width);

                tail->next = merge(left, right);
                while (tail->next) tail = tail->next;
            }
        }

        return dummy.next;
    }
private:
    ListNode* split(ListNode* head, int n){
        if (!head) return nullptr;
        for (int i=1;i<n && head->next; i++) head = head->next;
        ListNode* rest = head->next;
        head->next = nullptr;
        return rest;
    }

    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (l1 && l2){
            if (l1->val <= l2->val){
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }        

        tail->next = l1 ? l1: l2;
        return dummy.next;
    }    
};

int main(){
    Solution solution;

    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);
    head = solution.sortList(head);
    printList(head);

    head = new ListNode(-1);
    head->next = new ListNode(5);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(0);
    head = solution.sortList(head);
    printList(head);

    return 0;
}

