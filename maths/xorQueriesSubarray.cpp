/*
Leetcode Medium 1310. XOR Queries of a Subarray

You are given an array arr of positive integers. You are also given the array queries where queries[i] = [lefti, righti].

For each query i compute the XOR of elements from lefti to righti (that is, arr[lefti] XOR arr[lefti + 1] XOR ... XOR arr[righti] ).

Return an array answer where answer[i] is the answer to the ith query.

Constraints:
1 <= arr.length, queries.length <= 3 * 10^4
1 <= arr[i] <= 10^9
queries[i].length == 2
0 <= lefti <= righti < arr.length
*/
#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> v){
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size(), start = 0, end = 0, temp = 0;
        vector<int> prefixXor(n+1, 0), res;
        for (int i=1;i<=n;i++) prefixXor[i] = prefixXor[i-1] ^ arr[i-1];

        for (int i=0;i<queries.size();i++){
            start = queries[i][0];
            end = queries[i][1];
            res.push_back(prefixXor[end+1] ^ prefixXor[start]);
        }
        return res; 
    }
};

int main(){
    Solution s;
    vector<int> arr, ans;
    vector<vector<int>> queries;

    arr = {1,3,4,8}; queries = {{0,1},{1,2},{0,3},{3,3}};
    ans = s.xorQueries(arr, queries);
    printVector(ans); // Expected output: [2,7,14,8]
    
    arr = {4,8,2,10}; queries = {{2,3},{1,3},{0,0},{0,3}};
    ans = s.xorQueries(arr, queries);
    printVector(ans); // Expected output: [8,0,4,4]

    return 0;
}
