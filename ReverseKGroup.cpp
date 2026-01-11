// I am solving Leetcode 25. Reverse Nodes in k-Group (Hard), reversing nodes of a linked list k at a time and returning its modified list.
// The topics are: Linked List, Recursion
//

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

ListNode *reverseKGroup(ListNode *head, int k)
{
    ListNode *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    // cout << "Total Nodes = " << count << endl;

    int groups = count / k;
    if (groups == 0)
        return head;

    ListNode *combined = new ListNode();
    ListNode *part[groups];

    ListNode *curr = head;
    // cout << "groups = " << groups << endl;
    // cout << "k = " << k << endl;
    count = 0;

    for (int i = 0; i < groups; i++)
    {
        part[i] = nullptr;
        // cout << "count = " << count << ", ";
        // cout << "stopcriteria = " << (i + 1) * k << endl;
        while (count < (i + 1) * k)
        {
            count++;
            ListNode *next = curr->next;
            curr->next = part[i];
            part[i] = curr;
            curr = next;
        }
        count = i * k + k;
    }

    ListNode *tempo = part[0];
    for (int i = 1; i < groups; i++)
    {
        while (tempo->next != nullptr)
        {
            tempo = tempo->next;
        }
        tempo->next = part[i];
    }
    while (tempo->next != NULL)
    {
        tempo = tempo->next;
    }
    tempo->next = curr;
    return part[0];
}

int main()
{
    // ListNode *test = new ListNode(1);
    // test->next = new ListNode(2);
    // test->next->next = new ListNode(3);
    // test->next->next->next = new ListNode(4);
    // test->next->next->next->next = new ListNode(5);
    // test->next->next->next->next->next = nullptr;

    // [8,0,4,0,1,6,2,4,5,6]
    int arr[] = {8, 0, 4, 0, 1, 6, 2, 4, 5, 6};

    ListNode *test = new ListNode(arr[0]);
    ListNode *temp = test;
    for (int i = 1; i < (sizeof(arr) / sizeof(arr[0])); i++)
    {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
        cout << " Original = ";
    temp = test;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout<<endl;

    ListNode *test1 = reverseKGroup(test, 2);

    cout << " Original = ";
    temp = test;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout<<endl;

    cout << "After reversing = ";
    while (test1 != NULL)
    {
        cout << test1->val << " ";
        test1 = test1->next;
    }
    cout<<endl;
    return 0;
}
