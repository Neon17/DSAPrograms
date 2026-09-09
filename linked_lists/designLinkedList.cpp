/*
    Leetcode Medium 707. Design Linked List

    Design your implementation of the linked list. You can choose to use a singly or doubly linked list.
    A node in a singly linked list should have two attributes: val and next. val is the value of the current node, 
        and next is a pointer/reference to the next node.
    If you want to use the doubly linked list,
     you will need one more attribute prev to indicate the previous node in the linked list. 
     Assume all nodes in the linked list are 0-indexed.

    Implement the MyLinkedList class:

    MyLinkedList() Initializes the MyLinkedList object.
    int get(int index) Get the value of the indexth node in the linked list. If the index is invalid, return -1.
    void addAtHead(int val) Add a node of value val before the first element of the linked list. 
    After the insertion, the new node will be the first node of the linked list.
    void addAtTail(int val) Append a node of value val as the last element of the linked list.
    void addAtIndex(int index, int val) Add a node of value val before the indexth node in the linked list. 
    If index equals the length of the linked list, the node will be appended to the end of the linked list. 
    If index is greater than the length, the node will not be inserted.
    void deleteAtIndex(int index) Delete the indexth node in the linked list, if the index is valid.
*/

#include <iostream>
using namespace std;

class MyLinkedList {
    struct ListNode {
        public:
            int val;
            ListNode* next;
            ListNode(int val) : val(val), next(nullptr) {}
            ListNode(int val, ListNode* next) : val(val), next(next) {}
    };

    ListNode* head;

public:
    MyLinkedList() {
        head = nullptr;
    }
    
    int get(int index) {
        if (!head) return -1;
        ListNode* temp = head;
        for (int i=0;i<index;i++){
            if (!temp || !temp->next) return -1;
            temp = temp->next;
        }
        return temp->val;
    }
    
    void addAtHead(int val) {
        ListNode* add = new ListNode(val);
        add->next = head;
        head = add;
    }
    
    void addAtTail(int val) {
        ListNode* temp = head;
        if (!temp) return addAtHead(val);
        while (temp->next) temp = temp->next;
        temp->next = new ListNode(val);
    }
    
    void addAtIndex(int index, int val) {
        if (index <= 0) return addAtHead(val);
        int size = 0;
        ListNode* temp = head;
        while (temp){
            size++;
            temp = temp->next;
        }
        if (index > size) return;
        temp = head;
        for (int i=1;i<index;i++) temp = temp->next;

        ListNode* add = new ListNode(val);
        add->next = temp->next;
        temp->next = add;
    }
    
    void deleteAtIndex(int index) {
        if (!head) return;
        if (index <= 0) {
            ListNode* next = head->next;
            head->next = nullptr;
            delete(head);
            head = next;
            return;
        }
        int size = 0;
        ListNode* temp = head;
        while (temp){
            size++;
            temp = temp->next;
        }
        if (index >= size) return;

        temp = head;
        for (int i=1;i<index;i++) temp = temp->next;
        ListNode* next = temp->next->next;
        delete(temp->next);
        temp->next = next;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main(){
    MyLinkedList* obj = new MyLinkedList();
    int param_1;
    
    // Build list: 1 -> 2 -> 3
    obj->addAtHead(1);
    obj->addAtTail(3);
    obj->addAtIndex(1, 2);  
    param_1 = obj->get(1);
    cout << param_1 << " "; // should return 2
    obj->deleteAtIndex(1);
    param_1 = obj->get(1);
    cout << param_1 << endl; // should return 3
    cout << endl;

    return 0;
}  
