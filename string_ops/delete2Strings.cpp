// Leetcode Medium 583. Delete Operation for Two Strings

#include <iostream>
#include <vector>
using namespace std;

int minDistance(string word1, string word2, int ind1=0, int ind2=0){
    if (ind1 >= word1.size()){
        return word2.size() - ind2;
    } else if (ind2 >= word2.size()){
        return word1.size() - ind1;
    }

    int a = 1000, b = 1000, c = 1000;
    if (word1[ind1] == word2[ind2]){
        return minDistance(word1, word2, ind1 + 1, ind2 + 1);
    }
    b = 1 + minDistance(word1, word2, ind1 + 1, ind2);
    c = 1 + minDistance(word1, word2, ind1, ind2 + 1);

    return min(a, min(b, c));
}

int convertDP(string word1, string word2){
    // we have to maintain 3D DP -> [ind1][ind2]
    // initialze the dp to INF,...

    vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1, 0));

    for (int i=0;i<word1.size();i++){
        dp[i][word2.size()] = word1.size() - i;
    }

    for (int i=0;i<word2.size();i++){
        dp[word1.size()][i] = word2.size() - i;
    }

    for (int i=word1.size()-1;i>=0;i--){
        for (int j=word2.size()-1;j>=0;j--){

            if (word1[i] == word2[j]) {
                dp[i][j] = dp[i+1][j+1];
                continue;
            }
            dp[i][j] = 1 + min(dp[i+1][j], dp[i][j+1]);
        }
    }
    return dp[0][0];
}

int main(){
    string word1 = "", word2 = "";

    word1 = "sea"; word2 = "eat";
    cout<<minDistance(word1, word2)<<endl;

    word1 = "leetcode"; word2 = "etco";
    cout<<minDistance(word1, word2)<<endl;

    return 0;
}

