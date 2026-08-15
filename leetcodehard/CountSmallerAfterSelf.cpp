// Leetcode Hard 315. Count of Smaller Numbers After Self

// Input: nums = [5,2,6,1]
// Output: [2,1,1,0] 
// I am thinking of 3 different approaches to solve this problem.
/*
 * Segment Tree Approach:

    - We build segment tree at first considering range 0-3 as count of smaller numbers after 0 up to 3
    - If we have to find count of smaller numbers for ith index, then we just have to collect and add all range from ith to last of array
    - We can collect like this, if we are asked to find count of smaller number after 1th index, then we proceed like below
    - We go on looking for node that have start range same as 1 (1 - x), then after that x, we have to explore on right
    - We go on exploring right and right subtree, on that we add count if start range value is less or equal to that index, 
    - I'm little confused here, I will try later on

* Merge Sort

    - We can just split up to individual and go on merging
    - But at merging time, we check comparision and store comparison count somewhere in vector<int> count (let's say)
    - That means we should split and merge normally but at each comparision, just count (inverse count method maybe)

* Self Balancing Binary Search Tree

    - This I found easiest. We just have to make BST class with appropriate insert function
    - Insert should properly insert elements so BST property is satisfied
    - Then at every index, we can just check count of left subtree
    - Instead of building and later checking with every index, we can go on increasing count in vector<int> count at every insert (may be this is faster and efficient)
*/

#include <iostream>
#include <vector>
#include <math.h>
#include <unordered_map>
using namespace std;

class MyTriedSolution {
private:
    vector<int> num_smaller;
    vector<pair<int,int>> map;

    void split(vector<int>& nums, int left, int right){
        if (left >= right) return;
        int mid = left + (right - left)/2;
        split(nums, left, mid);
        split(nums, mid+1, right);
        merge(nums, left, mid, right);
    }

    void merge(vector<int>&nums, int left, int mid, int right){
        vector<int> ans;
        int nums1index = left, nums2index = mid+1, updates = 0;
        vector<pair<int,int>> newmap;
        while (nums1index <= mid || nums2index <= right){
            if (nums1index <= mid && nums2index <= right && nums[nums1index] == nums[nums2index]){
                num_smaller[map[nums1index].second] += updates;
                newmap.push_back({map[nums1index].second, ans.size()});
                ans.push_back(nums[nums1index]);
                nums1index++; 
            } else if (nums1index <= mid && nums2index <= right && nums[nums1index] < nums[nums2index]){
                num_smaller[map[nums1index].second] += updates;
                newmap.push_back({map[nums1index].second, ans.size()});
                ans.push_back(nums[nums1index]);
                nums1index++;
            } else if (nums1index <= mid && nums2index <= right && nums[nums1index] > nums[nums2index]){
                newmap.push_back({map[nums2index].second, ans.size()});
                ans.push_back(nums[nums2index]);
                updates++;
                nums2index++;
            } else if (nums1index <= mid){
                num_smaller[map[nums1index].second] += updates;
                newmap.push_back({map[nums1index].second, ans.size()});
                ans.push_back(nums[nums1index]);
                nums1index++;
            } else if (nums2index <= right){
                newmap.push_back({map[nums2index].second, ans.size()});
                ans.push_back(nums[nums2index]);
                nums2index++;
            }
        }
        for (int i=left; i<=right;i++) nums[i] = ans[i-left];
        int i = left;
        for (auto it:newmap) {
            map[it.second+left] = {it.first, i};
            i++;
        }
    }

public:
    vector<int> countSmaller(vector<int>& nums) {
        num_smaller.resize(nums.size(), 0);
        for (int i=0;i<nums.size();i++) map[i] = {i, i};
        split(nums, 0, nums.size()-1);
        return num_smaller;
    }
};

class Solution {
private:
    vector<int> count; 
    vector<pair<int, int>> arr;

    void mergeSort(int left, int right) {
        if (left >= right) return;
        int mid = left + (right - left) / 2;
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, mid, right);
    }

    void merge(int left, int mid, int right) {
        vector<pair<int, int>> temp; 
        int i = left;      
        int j = mid + 1;  
        int rightCount = 0;

        while (i <= mid || j <= right) {
            if (i <= mid && j <= right && arr[i].first <= arr[j].first) {
                count[arr[i].second] += rightCount;
                temp.push_back(arr[i]);
                i++;
            } 
            else if (i <= mid && j <= right && arr[i].first > arr[j].first) {
                rightCount++;
                temp.push_back(arr[j]);
                j++;
            }
            else if (i <= mid) {
                count[arr[i].second] += rightCount;
                temp.push_back(arr[i]);
                i++;
            }
            else {
                temp.push_back(arr[j]);
                j++;
            }
        }
        for (int k = 0; k < temp.size(); k++) {
            arr[left + k] = temp[k];
        }
    }

public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        count.assign(n, 0);
        arr.clear();
        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }
        mergeSort(0, n - 1);
        return count;
    }
};

class BinarySearchSolution {
    // I tried this Binary Search Tree approach, it is correct but not that optimal, why?
    // Because it is not self balancing, so in worst case it can be O(n^2) time complexity, 
    // Insertion time = O(h) where h is height of tree, in worst case h = n (becoz unbalancing nature), so O(n^2)
    // We have to create avl trees, balance at every insertion, learned how to do, but will not implement as it takes a lot of time and maynot irrelevant on interview

    struct BinaryTree {
        BinaryTree* left;
        BinaryTree* right;
        int val;
        int ind;
        int leftCount;
        BinaryTree(): left(nullptr), right(nullptr), val(0), ind(0), leftCount(0){}
        BinaryTree(int val): left(nullptr), right(nullptr), val(val), ind(0), leftCount(0){}
        BinaryTree(int ind, int val): left(nullptr), right(nullptr), val(val), ind(ind), leftCount(0){}
    };

    BinaryTree* root;
    vector<int> count;

    void insert(BinaryTree* root, int& ind, int& val, int count=0){
        if (!root) return;
        if (val >= root->val) {
            count += root->leftCount;
            if (val > root->val) count++;
            if (root->right) insert(root->right, ind, val, count);
            else {
                this->count[ind] = count;
                root->right = new BinaryTree(ind, val);
            }
        } else {
            root->leftCount++;
            if (root->left) insert(root->left, ind, val, count);
            else {
                this->count[ind] = count;
                root->left = new BinaryTree(ind, val);
            }
        }
    }

public:
    vector<int> countSmaller(vector<int>& nums) {
        root = nullptr;
        count.resize(nums.size(), 0);
        root = new BinaryTree(nums[nums.size()-1]);
        for (int i=nums.size()-2; i>=0;i--) insert(root, i, nums[i]);
        return count;
    }
};

int main() {
    Solution s;
    vector<int> nums, ans;

    nums = {5,2,6,1};
    ans = s.countSmaller(nums);
    for (auto it:ans) cout << it << " ";
    cout << endl;

    return 0;
}

