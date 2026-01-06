#include<iostream>
#include<string>
using namespace std;

//leetcode easy problem "Add two numbers"
//accepted

struct ListNode {
    int val;
    ListNode *next;
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3;
        ListNode* temp;
        ListNode* temp1;
        ListNode* temp3;
        l3 = new ListNode();
        temp = l1; temp1 = l2; temp3 = l3;
        string a="",b="",c="";
        while (temp!=NULL){
            a = to_string(temp->val)+a;
            temp = temp->next;
        }
        while(temp1!=NULL){
            b = to_string(temp1->val)+b;
            temp1 = temp1->next;
        }
        // cout<<a<<"\t"<<b<<endl;
        int len1,len2,len,sum,carry=0,i;
        len1 = a.length();
        len2 = b.length();
        len = (len1>len2)?len2:len1;
        for (i=0;i<len;i++){
            sum = (a[len1-1-i]-'0') + (b[len2-1-i]-'0') + carry;
            carry = sum/10;
            sum = sum%10;
            c = c+to_string(sum);
            // cout<<sum<<"\t"<<carry<<endl;
        }
        int diff = 0, s = 0;
        if (len1!=len){
            diff = len1-len;
            s = 1;
        }
        else {
            diff = len2-len;
            s = 2;
        }
        for (i=0;i<diff;i++){
            if (s == 1){
                sum = (a[diff-1-i]-'0')+carry;
                carry = sum/10;
                sum = sum%10;
                c = c+to_string(sum);
                // cout<<sum<<"\t"<<carry<<endl;
            }
            else if (s == 2){
                sum = (b[diff-1-i]-'0')+carry;
                carry = sum/10;
                sum = sum%10;
                c = c+to_string(sum);  
                // cout<<sum<<"\t"<<carry<<endl;           
            }
        }
        while (carry!=0){
            sum = carry%10;
            carry = carry/10;
            c = c+to_string(sum);
            cout<<sum<<"\t"<<carry<<endl;
        }
        for (i=0;i<c.length();i++){
            if (i!=0){
                temp3->next = new ListNode();
                temp3 = temp3->next;
            }
            temp3->val = (c[i]-'0');
        }
        return l3;
    }
};