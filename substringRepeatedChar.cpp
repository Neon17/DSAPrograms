//This is leetcode problem no. 3. Longest Substring Without Repeating Characters
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = 0;
        map <int, int> dict;
        vector<char> chars;
        int temp = -1;

        //Push all occurrences of unique characters in dictionary with position like dict[0] = 0, (0th position has 0th char)
        //Store unique occurrences in map 
        for (int i=0;i<s.length();i++){
            if (i==0){
                dict[i] = i;
                chars.push_back(s[i]);
            }
            temp = -1;
            for (int j=0;j<chars.size();j++){
                if (s[i]==chars[j]){
                    temp = j;
                    break;
                }
            }
            if (temp==-1){
                chars.push_back(s[i]);
                dict.insert({i, (chars.size()-1)});
            }
            else 
                dict.insert({i, temp});
        }
        // cout<<"All Characters and their Occurrences are given below"<<endl;
        // for (int i = 0; i<chars.size();i++){
        //     cout<<chars[i]<<"\t";
        // }
        // cout<<endl;
        // for (int i = 0;i<dict.size();i++){
        //     cout<<i<<" = "<<dict[i]<<endl;
        // }

        //for finding max length substring without repeating chars
        int tempLength = 0, countIndex = 0, flag = 0;
        int len = s.length();
        for (int i=0;i<s.length();i++){
            if (i==0){
                tempLength++;
                // cout<<i<<"\t tempLength = "<<tempLength<<endl;
                continue;
            }
            for (int j = countIndex; j<i;j++){
                if (dict[j]==dict[i]){
                    // cout<<"Starting from position "<<j+1<<endl;
                    if (length<tempLength) length = tempLength;
                    flag = 1;
                    countIndex = j + 1;
                    tempLength = i - j;
                    // cout<<"tempLength = "<<tempLength<<endl;
                    break;
                }
            }
            if (flag==0)
                tempLength++;
            flag = 0;
            // cout<<i<<"\t tempLength = "<<tempLength<<endl;
        }

        return length;
    }
};

int main(){
    Solution s;
    int len = s.lengthOfLongestSubstring("abcabcbb");
    cout<<"Length of Longest Substring without repeating characters = "<<len<<endl;
    return 0;
}
