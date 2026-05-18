// I am solving Leetcode 282. Expression Add Operators (Hard) using Backtracking
// This is last hard problem to be solved before reaching 10 hards solved within 70 questions solved

#include <iostream>
#include <vector>
using namespace std;

vector<string> addOperators(string num, int target)
{
    vector<string> ans;
    return ans;
}

void printIt(vector<string> nums){
    cout<<endl<<"[";
    for (int i=0;i<nums.size();i++){
        cout<<nums[i];
        if (i != nums.size()-1) cout<<", ";
    }
    cout<<"]"<<endl;
}

int main() {
    vector<string> sol;
    string num; int target;

    num = "123"; target = 6;

    sol = addOperators(num, target);
    printIt(sol);

    return 0;
}
