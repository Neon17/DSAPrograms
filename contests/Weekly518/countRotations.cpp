
#include <iostream>
using namespace std;

class Solution {
public:
    int countRotations(string s, int k) {
        int nl = 0, nr = 0, n = s.size(), score = 0, count = 0;

        for (int rot = 0; rot < n; rot++){
            score = 0;
            
            for (int i = 1; i < n; i++){
                nl = (i + rot) % n;
                nr = (nl - 1 + n) % n;
                if (s[nl] == s[nr]) score++;
            }
            if (score == k) count++;
        }
        return count;
    }
};


int main(){
    Solution sol;
    string s; int k;

    s = "aab"; k = 1;
    cout<<sol.countRotations(s, k)<<endl;

    s = "abca"; k = 0;
    cout<<sol.countRotations(s, k)<<endl;

    s = "aa"; k = 1;
    cout<<sol.countRotations(s, k)<<endl;

    s = "ab"; k = 1;
    cout<<sol.countRotations(s, k)<<endl;

    return 0;
}
