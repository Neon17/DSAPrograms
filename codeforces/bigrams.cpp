// 2242A - Bigrams

#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n = 0, nums = 0;
    cin >> n;
    vector<vector<int>> v;

    for (int i = 0; i < n; i++){
        cin>>nums;
        vector<int> v1(nums);

        for (int j=0;j<nums;j++){
            cin>>v1[j];
        }
        v.push_back(v1);
    }
    bool status = false, note = false;
    for (int i=0;i<n;i++){
        status = false; note = false;

        for (int j = 0; j < v[i].size(); j++){
            if (v[i][j] >= 3) { status = true; break; }
            else if (v[i][j] == 2) {
                if (note) { status = true; break; }
                else note = true;
            }
        }
        cout<<(status?"YES":"NO")<<endl;
    }

    return 0;
}
