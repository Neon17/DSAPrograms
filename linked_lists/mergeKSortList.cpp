/*
Leetcode Hard 23. Merge k Sorted Lists

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

Constraints:
    k == lists.length
    0 <= k <= 10^4
    0 <= lists[i].length <= 500
    -10^4 <= lists[i][j] <= 10^4
    lists[i] is sorted in ascending order.
    The sum of lists[i].length will not exceed 10^4.
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

void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

class Solution {
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
        tail->next = (l1)?l1:l2;
        return dummy.next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        if (lists.size() == 1) return lists[0];
        int size = lists.size();

        while (lists.size() > 1) {
            vector<ListNode*> newlists;
            size = lists.size();
            
            for (int i=0;i<size;i+=2){
                if (i+1 == size){
                    newlists.push_back(lists[i]);
                    continue;
                }
                ListNode* temp = merge(lists[i], lists[i+1]);
                newlists.push_back(temp);
            }
            lists = newlists;
        }
        return lists[0];
    }
};

int main(){
    ListNode* l1, *l2, *l3, *result;
    Solution sol;

    l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);
    l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);
    l3 = new ListNode(2);
    l3->next = new ListNode(6);

    vector<ListNode*> lists = {l1, l2, l3};
    result = sol.mergeKLists(lists);
    printList(result);

    vector<ListNode*> lists2 = {};
    result = sol.mergeKLists(lists2);
    printList(result);

    vector<ListNode*> lists3 = {nullptr};
    result = sol.mergeKLists(lists3);
    printList(result);

    return 0;
}

