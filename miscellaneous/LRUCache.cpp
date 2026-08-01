// Leetcode Medium 146. LRU Cache
// Question: What is data structure we can use to move, insert and delete random elements in O(1) time complexity?
// Answer: Doubly Linked List + Hash Map

#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;


class LRUCache {
    struct ListNode{
        int key;
        int value;
        ListNode* prev;
        ListNode* next;
        ListNode(int k, int v): key(k), value(v), prev(nullptr), next(nullptr) {}
    };
    int capacity, size;
    ListNode* head; ListNode* tail;
    unordered_map<int, ListNode*> map;

    void shiftToTail(ListNode* temp, int value = -1){
        if (value != -1) temp->value = value;
        if (!temp->next) return;
        ListNode* prev = temp->prev;
        ListNode* next = temp->next;
        if (prev) prev->next = next;
        else head = temp->next;
        next->prev = prev;

        prev = tail;
        prev->next = temp;
        prev->next->next = nullptr;
        temp->prev = prev;
        tail = temp;
    }

    void insertNewKey(int key, int value){
        if (!head){
            head = new ListNode(key, value);
            tail = head;
            map[key] = tail;
            return;
        }
        ListNode* newNode = new ListNode(key, value);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        map[key] = tail;
        return;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        head = nullptr; tail = nullptr;
    }
    
    int get(int key) {
        if (!map.count(key)) return -1;
        ListNode* temp = map[key];
        int val = temp->value;
        shiftToTail(temp);
        return val;
    }
    
    void put(int key, int value) {
        if (size < capacity || map.count(key)){
            if (!map.count(key)){
                insertNewKey(key, value);
                size++;
                return;
            }
            ListNode* temp = map[key];
            shiftToTail(temp, value);
            return;
        }
        ListNode* tempo = head->next;
        int key1 = head->key;
        delete(head);
        map.erase(key1);
        if (tempo) tempo->prev = nullptr;
        else tail = nullptr;
        head = tempo;
        insertNewKey(key, value);
    }
};

void printVector(vector<string> ans){
    for (int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    /*
    ["LRUCache","put","put","get","put","get","put","get","get","get"]
[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]
    */
    vector<string> ans;
    LRUCache* obj = new LRUCache(2);
    ans.push_back("null");
    obj->put(1, 1);
    ans.push_back("null");
    obj->put(2, 2);
    ans.push_back("null");
    ans.push_back(to_string(obj->get(1)));
    obj->put(3, 3);
    ans.push_back("null");
    ans.push_back(to_string(obj->get(2)));
    obj->put(4, 4);
    ans.push_back("null");
    ans.push_back(to_string(obj->get(1)));
    ans.push_back(to_string(obj->get(3)));
    ans.push_back(to_string(obj->get(4)));

    printVector(ans);

    return 0;
}
