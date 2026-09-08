/*
Leetcode Hard 218. The Skyline Problem

A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. 
Given the locations and heights of all the buildings, 
return the skyline formed by these buildings collectively.

The geometric information of each building is given in the array buildings where buildings[i] = [lefti, righti, heighti]:

lefti is the x coordinate of the left edge of the ith building.
righti is the x coordinate of the right edge of the ith building.
heighti is the height of the ith building.
You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.

The skyline should be represented as a list of "key points" sorted by their x-coordinate in the form [[x1,y1],[x2,y2],...]. 
Each key point is the left endpoint of some horizontal segment in the skyline except the last point in the list, 
which always has a y-coordinate 0 and is used to mark the skyline's termination where the rightmost building ends. 
Any ground between the leftmost and rightmost buildings should be part of the skyline's contour.

Note: There must be no consecutive horizontal lines of equal height in the output skyline. 
For instance, [...,[2 3],[4 5],[7 5],[11 5],[12 7],...] is not acceptable; 
the three lines of height 5 should be merged into one in the final output as such: [...,[2 3],[4 5],[12 7],...]

Constraints:
1 <= buildings.length <= 104
0 <= lefti < righti <= 231 - 1
1 <= heighti <= 231 - 1
buildings is sorted by lefti in non-decreasing order.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        // I think we can use sweep line to process the events and priority queue to track the current heights of buildings.
        int n = buildings.size(), curr = 0, temp = 0;
        priority_queue<pair<int,int>> pq;
        map<int, vector<int>> times;
        vector<vector<int>> res;
        vector<char> deleted(n, 0);

        for (int i=0;i<n;i++){
            times[buildings[i][0]].push_back(i+1);
            times[buildings[i][1]].push_back(-(i+1));
        }

        for (auto it: times){

            for (int ind: it.second){
                if (ind > 0) pq.push({buildings[ind-1][2], ind-1});
                else deleted[-ind-1] = 1;
            }
            
            while (!pq.empty() && deleted[pq.top().second]) pq.pop();

            temp = (!pq.empty())?pq.top().first:0;
            if (curr != temp) res.push_back({it.first, temp});
            curr = temp;
        }
        return res;
    }
};

void printVector(vector<vector<int>> &v){
    for (int i=0;i<v.size();i++){
        cout << "[" << v[i][0] << "," << v[i][1] << "] ";
    }
    cout << endl;
}

int main(){
    Solution* obj;
    vector<vector<int>> buildings;

    buildings = {{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
    vector<vector<int>> ans = obj->getSkyline(buildings);
    printVector(ans); // Expected output: [[2,10],[3,15],[7,12],[12,0],[15,10],[20,8],[24,0]]

    buildings = {{0,2,3},{2,5,3}};
    ans = obj->getSkyline(buildings);
    printVector(ans); // Expected output: [[0,3],[5,0]]

    return 0;
}

