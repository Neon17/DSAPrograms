/**
 * Leetcode Medium 86. Partition List
 * 
 * Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
 * You should preserve the original relative order of the nodes in each of the two partitions.
 * 
 * Example 1:
 * Input: head = [1,4,3,2,5,2], x = 3
 * Output: [1,2,2,4,3,5]
 * 
 * Example 2:
 * Input: head = [2,1], x = 2
 * Output: [1,2]
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

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode lefthead(0), righthead(0);
        ListNode* left = &lefthead;
        ListNode* right = &righthead;

        ListNode* temp = head;
        while (temp){
            if (temp->val < x){
                left->next = temp;
                left = left->next;
            } else {
                right->next = temp;
                right = right->next;
            }
            temp = temp->next;
        }
        right->next = nullptr;
        left->next = righthead.next;
        return lefthead.next;
    }
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

void printResult(vector<int> headval, ListNode* ans, int x){
    cout<<"Input: x = "<<x<<", array = ";  printVector(headval);
    cout<<"Output: "; output(ans);
    cout<<endl;
}

int main() {
    ListNode* head=NULL;
    ListNode* ans=NULL;
    Solution s;
    vector<int> headval;
    int x = 0;

    headval = {1,4,3,2,5,2}; x = 3;
    head = input(headval);
    ans = s.partition(head, x);
    printResult(headval, ans, x);

    headval = {2,1}; x = 2;
    head = input(headval);
    ans = s.partition(head, x);
    printResult(headval, ans, x);
}
