// this is parenthesis generation problem solved using backtracking
#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<string> test){
    cout<<"-----------------------"<<endl;
    cout<<"Total = "<<test.size()<<endl;
    cout<<"[";
    for (int i=0;i<test.size();i++){
        cout<<"\""<<test[i]<<"\"";
        if (i!=(test.size()-1)) cout<<",";
    }
    cout<<"]"<<endl;
    cout<<"------------------------"<<endl;
}

void generateParenthesis(int n, vector<string>& parenthesis, string& current, int start=0, int end=0){
    if ((start == n) && (end == n)){
        parenthesis.push_back(current);
    }

    if (start<n){
        current = current + "(";
        generateParenthesis(n, parenthesis, current, start+1, end);
        current.pop_back();
    } 
    if (end<start){
        current = current + ")";
        generateParenthesis(n, parenthesis, current, start, end+1);
        current.pop_back();
    }
}

int main(){
    int n = 5;
    vector<string> parenthesis;
    string current(6, '\0');
    generateParenthesis(n, parenthesis, current);
    printVector(parenthesis);
    return 0;
}
