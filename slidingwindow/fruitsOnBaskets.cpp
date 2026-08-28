/*
Leetcode Medium 904. Fruit Into Baskets

You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

You only have two baskets, and each basket can only hold a single type of fruit. 
There is no limit on the amount of fruit each basket can hold.
Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. 
The picked fruits must fit in one of your baskets.
Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
Given the integer array fruits, return the maximum number of fruits you can pick.

Constraints:
1 <= fruits.length <= 10^5
0 <= fruits[i] < fruits.length
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        vector<int> pos(2, -1);
        vector<int> taken(2, -1);
        int left = 0, right = 0, maxval = (-1) * (__INT32_MAX__ - 1);

        for (right;right < fruits.size(); right++){
            if (taken[0] == fruits[right] || taken[1] == fruits[right]) {
                if (taken[0] == fruits[right]) pos[0] = right;
                else pos[1] = right;
                continue;
            }
            if (taken[0] == -1){
                taken[0] = fruits[right];
                pos[0] = right;
                continue;
            } else if (taken[1] == -1){
                taken[1] = fruits[right];
                pos[1] = right;
                continue;
            } 
            maxval = max(maxval, right - left);
            if (pos[0] > pos[1]){
                left = pos[1] + 1;
                taken[1] = fruits[right];
                pos[1] = right;
            } else {
                left = pos[0] + 1;
                taken[0] = fruits[right];
                pos[0] = right;
            }
        }
        if (right - left > maxval) maxval = right - left;
        return maxval;
    }
};

int main(){
    Solution solution;
    vector<int> fruits;

    fruits = {1,2,1};
    cout << solution.totalFruit(fruits) << endl;

    fruits = {0,1,2,2};
    cout << solution.totalFruit(fruits) << endl;

    fruits = {1,2,3,2,2};
    cout << solution.totalFruit(fruits) << endl;

    fruits = {3,3,3,1,2,1,1,2,3,3,4};
    cout << solution.totalFruit(fruits) << endl;

    fruits = {0,1,6,6,4,4,6};
    cout << solution.totalFruit(fruits) << endl;

    return 0;
}

