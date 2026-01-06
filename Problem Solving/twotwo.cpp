#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

// Advanced Problem of hacker rank worth 150 points

/*
 * Complete the 'twoTwo' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING a as parameter.
 */

int twoTwo(string a) {
    string strength;
    int divisible = 0,temp1;
    for (int i = 0;i<a.length();i++){
        if (i==0)
            if (a[i]=='0') continue;
        strength = "";
        for (int j = i; j<a.length();j++){
            strength = strength + a[j];
            //strength is in power of 2
            temp1 = stoi(strength);
            if (floor(log2(temp1))==log2(temp1)){
                divisible = divisible+1;
            }
            // cout<<log2(temp1)<<"\t"<<temp1<<endl;
        }
    }
    // cout<<endl;
    return divisible;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string a;
        getline(cin, a);

        int result = twoTwo(a);

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
