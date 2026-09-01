/*
    Leetcode Hard 732. My Calendar III

    A k-booking happens when k events have some non-empty intersection (i.e., there is some time that is common to all k events.)

    You are given some events [startTime, endTime), after each given event, 
        return an integer k representing the maximum k-booking between all the previous events.

    Implement the MyCalendarThree class:

    MyCalendarThree() Initializes the object.
    int book(int startTime, int endTime) 
    Returns an integer k representing the largest integer such that there exists a k-booking in the calendar.

    Constraints:
        0 <= startTime < endTime <= 10^9
        At most 400 calls will be made to book.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class MyCalendarThree {
    map<int, int> prefixmap;
public:
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        int prefix = 0, maxival = 0;
        prefixmap[startTime] += 1;
        prefixmap[endTime] -= 1;

        for (const auto& [key, val]: prefixmap){
            prefix += val;
            maxival = max(maxival, prefix);
        }        
        return maxival;
    }
};

void printVector(vector<int> &v){
    for (int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

int main(){
    MyCalendarThree* obj = new MyCalendarThree();
    vector<int> res;

    res.push_back(obj->book(10, 20));
    res.push_back(obj->book(50, 60));
    res.push_back(obj->book(10, 40));
    res.push_back(obj->book(5, 15));
    res.push_back(obj->book(5, 10));
    res.push_back(obj->book(25, 55));

    printVector(res);
    return 0;
}


