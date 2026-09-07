/*
    Leetcode Medium 1845. Seat Reservation Manager

    Design a system that manages the reservation state of n seats that are numbered from 1 to n.

    Implement the SeatManager class:

    SeatManager(int n) Initializes a SeatManager object that will manage n seats numbered from 1 to n. All seats are initially available.
    int reserve() Fetches the smallest-numbered unreserved seat, reserves it, and returns its number.
    void unreserve(int seatNumber) Unreserves the seat with the given seatNumber.

    Constraints:
        1 <= n <= 10^5
        1 <= seatNumber <= n
        For each call to reserve, it is guaranteed that there will be at least one unreserved seat.
        For each call to unreserve, it is guaranteed that seatNumber will be reserved.
        At most 10^5 calls in total will be made to reserve and unreserve.
*/

#include <iostream>
#include <queue>
using namespace std;

class SeatManager {
    priority_queue<int, vector<int>, greater<int>> pq;
public:
    SeatManager(int n) {
        for (int i = 1; i <= n; i++) pq.push(i);
    }
    
    int reserve() {
        int res = pq.top();
        pq.pop();
        return res;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};

void printVector(vector<int> &v){
    for (int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

int main(){
    SeatManager* obj;
    vector<int> ans;

    obj = new SeatManager(5);
    ans.push_back(obj->reserve());
    ans.push_back(obj->reserve());
    obj->unreserve(2);
    ans.push_back(obj->reserve());
    ans.push_back(obj->reserve());
    ans.push_back(obj->reserve());
    ans.push_back(obj->reserve());
    obj->unreserve(5);

    printVector(ans);
    return 0;
}

