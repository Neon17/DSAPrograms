// This is first problem on segment trees
// This is Striver segment tree range update problem
// https://youtu.be/-dUiRtJ8ot0
// Taking reference from Striver, I am trying to solve this problem. The problem was this: https://leetcode.com/problems/range-sum-query-mutable/
// Leetcode Medium 307. Range Sum Query - Mutable

#include <iostream>
#include <vector>
using namespace std;

class NumArray {
private:
    int fillup(vector<int>& nums, int left, int right, int segindex = 0){
        if (left == right) return segTree[segindex] = nums[left]; 
        int n = left + (right - left)/2;
        return segTree[segindex] = fillup(nums, left, n, segindex*2+1) + fillup(nums, n+1, right, segindex*2+2);
    }
    
    void updateDown(int left, int right, int index, int value, int segindex = 0){
        if (segindex >= segTree.size() || segindex < 0) return;
        if (index < left || index > right) return;
        if (left == right && left == index) {
            segTree[segindex] = value;
            return;
        }
        int n = left + (right - left)/2;
        int newindex = segindex*2;

        if (index <= n) updateDown(left, n, index, value, newindex+1);
        if (index > n) updateDown(n+1, right, index, value, newindex+2);
        int a = (segindex*2+1 < segTree.size())? segTree[segindex*2+1]: 0;
        int b = (segindex*2+2 < segTree.size())? segTree[segindex*2+2]: 0;
        segTree[segindex] = a + b;
    }

    int sumDown(int left, int right, int acleft, int acright, int segindex = 0){
        if (right < acleft || left > acright) return 0;
        if (left >= acleft && right <= acright) return segTree[segindex];
        int n = left + (right - left)/2;
        int newindex = segindex*2;
        return sumDown(left, n, acleft, acright, newindex+1) + sumDown(n+1, right, acleft, acright, newindex+2);
    }

public:
    vector<int> segTree;
    int numSize;

    NumArray(vector<int>& nums) {
        int m = nums.size();
        this->numSize = m;
        segTree.resize(4*m, 0);
        if (m==0) return;
        fillup(nums, 0, m-1);
    }
    
    void update(int index, int val) {
        if (numSize == 0) return;
        updateDown(0, numSize-1, index, val);
    }
    
    int sumRange(int left, int right) {
        if (numSize == 0) return 0;
        return sumDown(0, numSize-1, left, right);
    }
};

int main(){
    vector<int> nums;

    nums = {1, 3, 5};
    NumArray* obj = new NumArray(nums);
    cout<< obj->sumRange(0, 2) << endl; // return 9
    obj->update(1, 2);   // nums = [1,2,5]
    cout<<obj->sumRange(0, 2)<<endl; // return 8

    return 0;
}

