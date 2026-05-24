/**
138. Copy List with Random Pointer (Leetcode Medium)
A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.

Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]

Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]

Constraints:

0 <= n <= 1000
-104 <= Node.val <= 104
Node.random is null or is pointing to some node in the linked list.
 */


#include <iostream>
#include <vector>
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

Node* input(vector<int> headval){
    Node* head = new Node(0);
    Node* temp = head;

    for (int i=0;i<headval.size();i++){
        temp->next = new Node(headval[i]);
        temp = temp->next;
    }
    return head->next;
}

void output(Node* head){
    Node* temp = head;
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

void printResult(vector<int> headval, Node* ans, int x){
    cout<<"Input: x = "<<x<<", array = ";  printVector(headval);
    cout<<"Output: "; output(ans);
    cout<<endl;
}

class Solution {
public:
    /** Hurray solved this problem by my approach */
    // Node* copyRandomList(Node* head) {
    //     unordered_map<Node*, Node*> map;
    //     unordered_map<Node*, Node*> future;
    //     Node dummy(0);
    //     Node* copy = &dummy;
    //     Node* temp = head;

    //     while (temp){
    //         copy->next = new Node(temp->val);
            
    //         if (temp->random == temp){
    //             copy->next->random = copy->next;
    //         } else if (temp->random && map.count(temp->random)){
    //             copy->next->random = map[temp->random];
    //             if (temp->random->random == temp){
    //                 copy->next->random->random = copy->next;
    //             }
    //         } else if (temp->random){
    //             future[temp->random] = new Node(temp->random->val);
    //             copy->next->random = future[temp->random];
    //         } else if (future.count(temp)){
    //             copy->next = future[temp];
    //         }
    //         if (temp) map[temp] = copy->next;
    //         temp = temp->next;
    //         copy = copy->next;
    //     }
    //     return dummy.next;
    // }

    /** Standard Solution that I understood */
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        unordered_map<Node*, Node*> m;
        Node* curr = head;

        while (curr){
            m[curr] = new Node(curr->val);
            curr = curr->next;
        }

        curr = head;
        while (curr){
            m[curr]->next = m[curr->next];
            m[curr]->random = m[curr->random];
            curr = curr->next;
        }
        return m[head];
    }

    /** We can optimize it further by interleaving nodes, A->A(copied)->B->B(copied)->C->C(copied), then linking random and separating old, new head
     *  Return new head
     */
};

int main() {
    Node* head=NULL;
    Node* ans=NULL;
    Solution s;
    vector<int> headval;
    int x = 0;

    headval = {1,4,3,2,5,2}; x = 3;
    head = input(headval);
    ans = s.copyRandomList(head);
    printResult(headval, ans, x);

    headval = {2,1}; x = 2;
    head = input(headval);
    ans = s.copyRandomList(head);
    printResult(headval, ans, x);
}

