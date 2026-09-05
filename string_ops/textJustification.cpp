/*
    Leetcode Medium 68. Text Justification

    Given an array of strings words and a width maxWidth, 
    format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.

    You should pack your words in a greedy approach; that is, pack as many words as you can in each line. 
    Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.

    Extra spaces between words should be distributed as evenly as possible. 
    If the number of spaces on a line does not divide evenly between words, 
        the empty slots on the left will be assigned more spaces than the slots on the right.

    For the last line of text, it should be left-justified, and no extra space is inserted between words.

    Note:

    A word is defined as a character sequence consisting of non-space characters only.
    Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
    The input array words contains at least one word.

    Constraints:
        1 <= words.length <= 300
        1 <= words[i].length <= 20
        words[i] consists of only English letters and symbols.
        1 <= maxWidth <= 100
        words[i].length <= maxWidth
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        string temp = "";
        int space = 0, index = 0;
        vector<int> numWords;

        for (int i=0;i<words.size();i++){
            if (space + words[i].size() <= maxWidth){
                if (index >= result.size()){
                    result.push_back(words[i]);
                    numWords.push_back(1);
                } else {
                    result[index] += " ";
                    for (int j=0;j<words[i].size();j++){
                        result[index] += words[i][j];
                    }
                    numWords[index]++;
                }
            } else {
                space = 0;
                result.push_back(words[i]);
                numWords.push_back(1);
                index++;
            }
            space += words[i].size() + 1;
        }

        for (int i=0;i<result.size()-1;i++){
            if (numWords[i] <= 1) {
                while (result[i].size() < maxWidth) result[i] += ' ';
                continue;
            }
            
            space = 0;
            for (int j=0;j<result[i].size();j++){
                if (result[i][j] == ' ') space++;
            }
            space += (result[i].size() < maxWidth)? (maxWidth - result[i].size()):0;
            
            vector<int> spaces(numWords[i]-1, 0);
            int count = numWords[i]-1;
            for (int i=0;i<space;i++){
                spaces[i%count]++;
            }

            temp = "";
            int wordCount = 0, j = 0;

            while (j < result[i].size()){
                while (j < result[i].size() && result[i][j] != ' ') {
                    temp += result[i][j];
                    j++;
                }
                wordCount++;
                if (wordCount < numWords[i]) {
                    int wordspace = spaces[wordCount-1];
                    for (int k=0;k<wordspace;k++) temp += ' ';
                } 
                j++;
            }
            result[i] = temp;
        }
        while (result[result.size()-1].size() < maxWidth) result[result.size()-1] += ' ';
        return result;
    }
};

void printVector(vector<string> vec){
    for (int i=0;i<vec.size();i++){
        cout<<vec[i]<<endl;
    }
}

int main(){
    Solution sol;
    vector<string> words; int maxWidth;

    words = {"This", "is", "an", "example", "of", "text", "justification."}; maxWidth = 16;
    vector<string> ans = sol.fullJustify(words, maxWidth);
    printVector(ans); cout<<endl;

    words = {"What","must","be","acknowledgment","shall","be"}; maxWidth = 16;
    ans = sol.fullJustify(words, maxWidth);
    printVector(ans); cout<<endl;

    words = {"Science","is","what","we","understand","well","enough","to","explain",
             "to","a","computer.","Art","is","everything","else","we","do"}; maxWidth = 20;
    ans = sol.fullJustify(words, maxWidth);
    printVector(ans); cout<<endl;

    return 0;
}

