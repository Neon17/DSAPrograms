/*
Leetcode Medium 138. Copy List with Random Pointer

A linked list of length n is given such that each node contains an additional random pointer, 
which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, 
where each new node has its value set to the value of its corresponding original node.
 Both the next and random pointer of the new nodes should point to new nodes in the copied list such that 
        the pointers in the original list and copied list represent the same list state. 
          None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, 
       where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. 
     Each node is represented as a pair of [val, random_index] where:
        val: an integer representing Node.val
        random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
        Your code will only be given the head of the original linked list.

Constraints:
    0 <= n <= 1000
    -10^4 <= Node.val <= 10^4
    Node.random is null or is pointing to some node in the linked list.
*/
#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << "[" << current->val << ", ";
        if (current->random) {
            cout << current->random->val;
        } else {
            cout << "null";
        }
        cout << "] ";
        current = current->next;
    }
    cout << endl;
}

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> map;
        Node *temp = head;
        Node dummy(0); Node* copy = &dummy;
        map[nullptr] = nullptr;

        while (temp){
            copy->next = new Node(temp->val);
            copy->next->random = temp->random;
            map[temp] = copy->next;
            temp = temp->next;
            copy = copy->next;
        }

        copy = dummy.next;
        while (copy) {
            copy->random = map[copy->random];
            copy = copy->next;
        }
        return dummy.next;
    }
};

int main(){
    Solution sol;
    Node* head, *ans;

    head = new Node(7);
    head->next = new Node(13);
    head->next->next = new Node(11);
    head->next->next->next = new Node(10);
    head->next->next->next->next = new Node(1);

    head->random = nullptr;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head;

    printList(head);
    ans = sol.copyRandomList(head);
    printList(ans);
    return 0;
}
