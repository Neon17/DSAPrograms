/*
Leetcode Medium 421. Maximum XOR of Two Numbers in an Array

Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.

Example 1:

Input: nums = [3,10,5,25,2,8]
Output: 28
Explanation: The maximum result is 5 XOR 25 = 28.
Example 2:

Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
Output: 127

Constraints:
1 <= nums.length <= 2 * 10^5
0 <= nums[i] <= 2^31 - 1
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    class TrieNode {
        TrieNode* left; // for 0
        TrieNode* right; // for 1

    public:
        TrieNode(){
            left = nullptr;
            right = nullptr;
        }
        void insert(int num){

            TrieNode* tempo = this;
            for (int i = 31; i >= 0; i--){

                int temp = (num >> i) & 1;
                if (temp == 1) {
                    if (!tempo->right) tempo->right = new TrieNode();
                    tempo = tempo->right;
                } else {
                    if (!tempo->left) tempo->left = new TrieNode();
                    tempo = tempo->left;
                }
            }
        }
        int findBest(int num){
            int res = 0;

            TrieNode* tempo = this;
            for (int i = 31; i >= 0; i--){

                int temp = (num >> i) & 1;
                if (temp == 0) {
                    if (tempo->right) {
                        tempo = tempo->right;   
                        res |= (1 << i);
                    }
                    else tempo = tempo->left;
                }
                else {
                    if (tempo->left) {
                        tempo = tempo->left;
                        res |= (1 << i);
                    }
                    else tempo = tempo->right;
                }
            }
            return res;
        }
    };

public:
    int findMaximumXOR(vector<int>& nums) {
        int maxi = 0;

        TrieNode* root = new TrieNode();
        for (int i=0;i<nums.size();i++) root->insert(nums[i]);

        for (int i=0;i<nums.size();i++){
            maxi = max(maxi, root->findBest(nums[i]));
        }
        return maxi;
    }
};

int main(){
    Solution s;
    vector<int> nums;

    nums = {3,10,5,25,2,8};
    cout << s.findMaximumXOR(nums) << endl; // Expected output: 28

    nums = {14,70,53,83,49,91,36,80,92,51,66,70};
    cout << s.findMaximumXOR(nums) << endl; // Expected output: 127

    return 0;
}
