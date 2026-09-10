/*
    Leetcode Medium 147. Insertion Sort List

    Given the head of a singly linked list, sort the list using insertion sort, and return the sorted list's head.

    The steps of the insertion sort algorithm:

    Insertion sort iterates, consuming one input element each repetition and growing a sorted output list.
    At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list and inserts it there.
    It repeats until no input elements remain.
    The following is a graphical example of the insertion sort algorithm. 
    The partially sorted list (black) initially contains only the first element in the list. 
    One element (red) is removed from the input data and inserted in-place into the sorted list with each iteration.

    Constraints:
    The number of nodes in the list is in the range [1, 5000].
    -5000 <= Node.val <= 5000
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
    while (current) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* curr = &dummy;

        while (curr->next){
            ListNode* temp = &dummy;

            while (temp->next != curr->next){
                if (temp->next->val > curr->next->val) break;
                temp = temp->next;
            }
            if (temp->next != curr->next){
                ListNode* next = curr->next;
                curr->next = curr->next->next;
                next->next = temp->next;
                temp->next = next;
            } else  curr = curr->next;
        }
        return dummy.next;
    }
};

int main(){
    Solution sol;
    ListNode* head, *ans;

    head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);
    ans = sol.insertionSortList(head);
    printList(ans);

    head = new ListNode(-1);
    head->next = new ListNode(5);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(0);
    ans = sol.insertionSortList(head);
    printList(ans);

    return 0;
}

