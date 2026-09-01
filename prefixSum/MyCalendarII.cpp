/*
    Leetcode Medium 731. My Calendar II

    You are implementing a program to use as your calendar. We can add a new event if adding the event will not cause a triple booking.
    A triple booking happens when three events have some non-empty intersection (i.e., some moment is common to all the three events.).

    The event can be represented as a pair of integers startTime and endTime that 
        represents a booking on the half-open interval [startTime, endTime), the range of real numbers x such that startTime <= x < endTime.

    Implement the MyCalendarTwo class:

    MyCalendarTwo() Initializes the calendar object.
    boolean book(int startTime, int endTime) Returns true if the event can be added to the calendar successfully without causing a triple booking. 
    Otherwise, return false and do not add the event to the calendar.

    Constraints:
        0 <= startTime < endTime <= 10^9
        At most 1000 calls will be made to book.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class MyCalendarTwo {
    map<int, int> prefixmap;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        int prefix = 0, maxival = 0;

        for (const auto& [key, val]: prefixmap){
            if (key >= endTime) break;
            if (key > startTime) maxival = max(maxival, prefix);
            prefix += val;
            if (key >= startTime) maxival = max(maxival, prefix);
        }
        maxival = max(maxival, prefix);
        if (maxival >= 2) return false;
        prefixmap[startTime] += 1;
        prefixmap[endTime] -= 1;
        return true;
    }
};

void printVector(vector<bool> &v){
    for (int i=0;i<v.size();i++){
        if (v[i]) cout << "true ";
        else cout << "false ";
    }
    cout << endl;
}

int main(){
    MyCalendarTwo* obj = new MyCalendarTwo();
    bool param_1;
    vector<bool> res;

    param_1 = obj->book(10, 20); 
    res.push_back(param_1);

    param_1 = obj->book(50, 60); 
    res.push_back(param_1);

    param_1 = obj->book(10, 40); 
    res.push_back(param_1);

    param_1 = obj->book(5, 15);
    res.push_back(param_1);

    param_1 = obj->book(5, 10); 
    res.push_back(param_1);

    param_1 = obj->book(25, 55); 
    res.push_back(param_1);

    printVector(res); // Output: [true, true, true, false, true, true]
    res.clear();

    MyCalendarTwo* obj2 = new MyCalendarTwo();
    param_1 = obj2->book(24, 40); 
    res.push_back(param_1);

    param_1 = obj2->book(43, 50); 
    res.push_back(param_1);

    param_1 = obj2->book(27, 43); 
    res.push_back(param_1);

    param_1 = obj2->book(5, 21); 
    res.push_back(param_1);

    param_1 = obj2->book(30, 40);
    res.push_back(param_1);

    param_1 = obj2->book(14, 29); 
    res.push_back(param_1);

    param_1 = obj2->book(3, 19);
    res.push_back(param_1);    

    param_1 = obj2->book(3, 14); 
    res.push_back(param_1);

    param_1 = obj2->book(25, 39);
    res.push_back(param_1);

    param_1 = obj2->book(6, 19);
    res.push_back(param_1);

    printVector(res); // Output: [true,true,true,true,true,false,true,false,false,true]
    res.clear();

    return 0;
}

