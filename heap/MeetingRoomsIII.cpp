// Leetcode Hard 2402. Meeting Rooms III
/*
    You are given an integer n. There are n rooms numbered from 0 to n - 1.
    You are given a 2D integer array meetings where meetings[i] = [starti, endi] means that a meeting will be held during the half-closed time interval [starti, endi). 
    All the values of starti are unique.

    Meetings are allocated to rooms in the following manner:

    Each meeting will take place in the unused room with the lowest number.
    If there are no available rooms, the meeting will be delayed until a room becomes free. The delayed meeting should have the same duration as the original meeting.
    When a room becomes unused, meetings that have an earlier original start time should be given the room.
    Return the number of the room that held the most meetings. If there are multiple rooms, return the room with the lowest number.

    A half-closed interval [a, b) is the interval between a and b including a and not including b.

    Constraints:
        1 <= n <= 100
        1 <= meetings.length <= 10^5
        meetings[i].length == 2
        0 <= starti < endi <= 5 * 10^5
        All the values of starti are unique.

    Topics: Senior Staff, Array, Hash Table, Sorting, Heap (Priority Queue), Simulation, Weekly Contest 309
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> rooms(n, 0);
        sort(meetings.begin(), meetings.end());
        priority_queue<int, vector<int>, greater<int>> idleRooms; // roomNumber
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> availableRooms; // {finish_time, roomNumber}
        for (int i=0;i<n;i++) idleRooms.push(i);
        long long time = 0;

        for (int i=0;i<meetings.size();i++){
            if (time < meetings[i][0]) time = meetings[i][0];

            while (!availableRooms.empty() && availableRooms.top().first <= time){
                auto [_, roomNumber] = availableRooms.top();
                availableRooms.pop();
                idleRooms.push({roomNumber});
            }
            if (idleRooms.empty()){
                auto [finish_time, room] = availableRooms.top();
                availableRooms.pop();
                time = finish_time;
                idleRooms.push(room);
                while (!availableRooms.empty() && availableRooms.top().first <= time){
                    auto [_, room] = availableRooms.top();
                    availableRooms.pop();
                    idleRooms.push(room);
                }
            }
            auto room = idleRooms.top();
            rooms[room]++;
            idleRooms.pop();
            int duration = meetings[i][1] - meetings[i][0];
            availableRooms.push({time + duration, room});
        }
        int maxi = INT_MIN;
        for (int i=0;i<rooms.size();i++){
            if (maxi < rooms[i]) maxi = rooms[i];
        }
        int maxindex = 0, maxicount = 0;
        for (int i=0;i<rooms.size();i++){
            if (rooms[i] == maxi){
                if (maxicount == 0) maxindex = i;
                maxicount++;
            } 
        }
        return maxindex;
    }
};

int main() {
    Solution sol;
    int n = 0;
    vector<vector<int>> meetings;

    n = 2, meetings = {{0,10},{1,5},{2,7},{3,4}};
    cout<<sol.mostBooked(n, meetings)<<endl;

    n = 3, meetings = {{1,20},{2,10},{3,5},{4,9},{6,8}};
    cout<<sol.mostBooked(n, meetings)<<endl;

    return 0;
}
