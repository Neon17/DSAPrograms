/*
Problem Statement
You are given a string 
S consisting of uppercase English letters.

Output the string obtained by replacing every character in 
S other than A with ..
*/

#include <iostream>
using namespace std;

int main(){
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(s[i] != 'A'){
            s[i] = '.';
        }
    }
    cout << s << endl;
    return 0;
}
