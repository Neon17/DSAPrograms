/*
    Leetcode Medium 881. Boats to Save People

    You are given an array people where people[i] is the weight of the ith person, and an infinite number of boats where 
    each boat can carry a maximum weight of limit. 
    Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.

    Return the minimum number of boats to carry every given person.

    Constraints:
    1 <= people.length <= 5 * 10^4
    1 <= people[i] <= limit <= 3 * 10^4
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int ans = 0, n = people.size(), right = n-1, left = 0;
        sort(people.begin(), people.end());
        while (left <= right){
            if (people[left] + people[right] <= limit){
                left++;
                right--;
            } else {
                right--;
            }
            ans++;
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> people; int limit;

    people = {1,2}; limit = 3;
    cout << s.numRescueBoats(people, limit) << endl;

    people = {3,2,2,1}; limit = 3;
    cout << s.numRescueBoats(people, limit) << endl;

    people = {3,5,3,4}; limit = 5;
    cout << s.numRescueBoats(people, limit) << endl;

    return 0;
}
