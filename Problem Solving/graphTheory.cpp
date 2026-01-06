#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

//Graph Theory Problem Solving
// Input should in below format
// 2  
// 3 2  
// 5 4 7  
// 5 1  
// 5 3 4 5 6

/*
 * Complete the 'problemSolving' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY v
 */

int problemSolving(int k, vector<int> v) {
    //first sort vector v
    //indices contain sorted elements
    vector<int> indices;
    vector<int> deleteIndices;
    int days = 0;
    int i,j,temp;
    for (i=0;i<v.size();i++){
        for (j=(i+1);j<v.size();j++){
            if (v[i]>v[j]){
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
        indices.push_back(i);
        // cout<<v[i]<<"\t";
    }
    // cout<<endl;
    // int ansCount = 0;
    // temp = v[0];
    // for (i=1;i<(v.size()-1);i++){
    //     if (!((v[i]-temp)==k))
    //         indices.push_back(i);
    //     else
    //         temp = v[i];
    // }
    // days = days + 1;
    while (indices.size()!=0){
        int i = 0,j;
        deleteIndices.push_back(0);
        temp = v[indices[0]];
        // cout<<"Indices are \t"<<indices[0]<<"\t";
        for (i=1;i<indices.size();i++){
            // cout<<indices[i]<<"\t";
            if (((v[indices[i]]-temp)==k)){
                deleteIndices.push_back(i);
                temp = v[indices[i]];
            }
        }
        cout<<endl;
        for (j=(deleteIndices.size()-1);j>=0;j--){
            indices.erase(next(indices.begin(),deleteIndices[j]));
        }
        //check if left indices can be added to last element
        temp = v[deleteIndices[deleteIndices.size()-1]];
        deleteIndices.clear();
        for (i=0;i<indices.size();i++){
            cout<<v[indices[i]];
            if (((v[indices[i]]-temp)==k)||(v[indices[i]]-temp)==-k){
                deleteIndices.push_back(i);
            }
        }
        for (j=(deleteIndices.size()-1);j>=0;j--){
            indices.erase(next(indices.begin(),deleteIndices[j]));
        }
        deleteIndices.clear();
        days = days + 1;
    }
    return days;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));
    
    for (int j = 0;j<t;j++){
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int k = stoi(first_multiple_input[1]);

        string v_temp_temp;
        getline(cin, v_temp_temp);

        vector<string> v_temp = split(rtrim(v_temp_temp));

        vector<int> v(n);

        for (int i = 0; i < n; i++) {
            int v_item = stoi(v_temp[i]);

            v[i] = v_item;
        }

        int result = problemSolving(k, v);

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
