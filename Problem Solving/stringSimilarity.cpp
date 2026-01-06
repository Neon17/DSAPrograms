#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'stringSimilarity' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int stringSimilarity(string s) {
    int len = s.length(),i,j,k;
    string m;
    int ans = s.length(),temp;
    string subString[len-1];
    for (i=1;i<len;i++){
        subString[i-1] = s.substr(i,len-i);
        temp = 0;
        for (k=0;k<(len-i);k++){
            if (subString[i-1][k]!=s[k])
                break;
            temp = temp + 1;
        }
        ans = ans+temp;
    }
    // for (i=1;i<len;i++){
    //     m = "";  temp = 0;
    //     for (j=i;j<len;j++){
    //         m += s[j];
    //     } 
    //     for (k=0;k<m.length();k++){
    //         if (m[k]!=s[k])
    //             break;
    //         temp = temp + 1;
    //     }
    //     ans = ans+temp;        
    // }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        int result = stringSimilarity(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
