/*
    Leetcode Hard 25. Reverse Nodes in k-Group

    Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

    k is a positive integer and is less than or equal to the length of the linked list. 
    If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

    You may not alter the values in the list's nodes, only nodes themselves may be changed.

    Constraints:
        The number of nodes in the list is n.
        1 <= k <= n <= 5000
        0 <= Node.val <= 1000
*/

#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
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
    void reverse(ListNode*& head){
        if (!head) return;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* temp = dummy.next;

        while (temp->next){
            ListNode* next = temp->next;
            temp->next = temp->next->next;
            next->next = dummy.next;
            dummy.next = next;            
        }
        head = dummy.next;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k <= 1) return head;
        ListNode dummy(0);
        dummy.next = head;
        int i = 0;

        ListNode* prevGroupEnd = &dummy;
        ListNode* currGroupStart = &dummy;
        ListNode* newGroupStart = head;
        ListNode* temp = head;

        while (temp){
            currGroupStart = temp;
            for (i=1;i<k;i++) {
                if (!temp) break;
                temp = temp->next;
            }
            if (i < k || !temp) break;
            newGroupStart = temp->next;
            temp->next = nullptr;
            temp = currGroupStart;

            reverse(temp);
            prevGroupEnd->next = temp;
            currGroupStart->next = newGroupStart;
            prevGroupEnd = currGroupStart;
            temp = newGroupStart;
        } 
        return dummy.next;
    }
};

int main()
{
    Solution sol; ListNode* head, *ans;

    head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    ans = sol.reverseKGroup(head, 2);
    printList(ans);

    head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    ans = sol.reverseKGroup(head, 3);
    printList(ans);

    return 0;
}
