/*
    Leetcode Medium 1109. Corporate Flight Bookings

    There are n flights that are labeled from 1 to n.
    You are given an array of flight bookings bookings, where 
        bookings[i] = [firsti, lasti, seatsi] 
            represents a booking for flights firsti through lasti (inclusive) with seatsi seats reserved for each flight in the range.

    Return an array answer of length n, where answer[i] is the total number of seats reserved for flight i.

    Constraints:
        1 <= n <= 2 * 10^4
        1 <= bookings.length <= 2 * 10^4
        bookings[i].length == 3
        1 <= firsti <= lasti <= n
        1 <= seatsi <= 10^4
*/

#include<iostream>
#include<vector>
using namespace std;

void printVector(vector<int> &v){
    for (int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res(n, 0);
        for (int i=0;i<bookings.size();i++){
            res[bookings[i][0]-1] += bookings[i][2];
            if (bookings[i][1] < n) res[bookings[i][1]] -= bookings[i][2];
        }
        for (int i=1;i<n;i++){
            res[i] += res[i-1];
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> bookings; int n;
    vector<int> res;  

    bookings = {{1,2,10},{2,3,20},{2,5,25}}; n = 5;
    res = sol.corpFlightBookings(bookings, n);
    printVector(res); // Output: [10, 55, 45, 25, 25]

    bookings = {{1,2,10},{2,2,15}}; n = 2;
    res = sol.corpFlightBookings(bookings, n);
    printVector(res); // Output: [10, 25]

    return 0;
}
