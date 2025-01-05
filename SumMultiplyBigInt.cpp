//It is program of Big Integer multiplication, sum, subtraction, division (with quotient, remainder and desired digit after decimal)
//It only works for integer having length less than 32767 because of string length limit of C++

#include <iostream>
#include <cstring>
#include <vector>
using  namespace std;

void sameBit(string& a, string& b);
void removeExtraLeadingZero(string& a);
string Subtract(string a, string b);
string Sum(string a, string b);
string Multiply(string a, string b);
vector<string> quotientRemainder(string a, string b);
string Divide(string a, string b, int method, int digitAfterDecimal);
string Factorial(int n);

void sameBit(string& a, string& b){
    //It converts to same length string by adding 0 at front
    if (a.size()==b.size()) return;
    int len1 = a.size(), len2 = b.size(),len = 0;
    int i, diff=0;
    diff = abs(len1-len2);
    string diffStr="";
    for (i=0;i<diff;i++)
        diffStr = diffStr + "0";
    if (len1>len2) b = diffStr+b;
    else if (len2>len1) a = diffStr+a;
}

void removeExtraLeadingZero(string& a){
    int i = 0, m = a.size();
    string b = "";
    int status = 0;
    for (i=0;i<m;i++){
        if ((a[i]!='0')){
            b += a[i];
            status = 1;
        }
        else{
            if (status == 1) b += a[i];
        }
    }
    a = b;
}

string Subtract(string a, string b){
    if (a==b) return 0;
    int sign = 0; //sign 1 means negative
    int len1 = a.size(), len2 = b.size();
    string large = "", small = "";
    if (len1>len2){
        large = a; small = b;
    }
    else if (len2>len1) {
        sign = 1;
        large = b; small = a;
    }
    else {
        int c = 0,i;
        for (i=0;i<len1;i++){
            if (a[i]<b[i]){
                sign = 1;
                c = 1; break;
            }
            else if (a[i]>b[i]){
                c = 2; break;
            }
        }
        large = (c==1)?b:a;
        small = (c==2)?b:a;
    }
    sameBit(large,small);

    int borrowing = 0, borrow = 0;
    int l = 0;
    string ans = "";
    int i,j;
    for (i=(small.size()-1);i>=0;i--){
        if (large[i]<small[i]){
            if (borrowing==0){
                borrow = 10;
                borrowing = 1;
            }
            else
                borrow = 9;
        }
        else {
            if (borrowing == 1){
                if (large[i]==small[i])
                    borrow = 9;
                else 
                    borrow = -1;
            }
        }
        l = (large[i]+borrow)-small[i];
        if ((i==0)&&(l==0)) break;
        ans = to_string(l)+ans;
        // cout<<ans<<endl;
        if ((borrowing==1)&&(borrow==-1)){
            borrow = 0; borrowing = 0;
        }
    }

    removeExtraLeadingZero(ans);
    return (sign==1)?("-"+ans):ans;
}

string Sum(string a, string b){
    string c = a, d = b;
    sameBit(c,d);
    int len = c.size(),i;
    int m, carry = 0, put;
    string sum = "";
    for (i=(len-1);i>=0;i--){
        m = c[i] - '0' + d[i] - '0' + carry;
        carry = m/10;
        put = m%10;
        sum = to_string(put)+sum;
        if (i==0){
            if (carry!=0) sum = to_string(carry)+sum;
        }
    }
    return sum;
}

string Multiply(string a, string b){
    int len1, len2, len;
    len1 = a.size(); len2 = b.size();
    len = (len1>len2)?len1:len2;
    int cal, put, carry=0, sum=0, two = 0;
    string sol = "", ans = "";
    int i,j;
    string zeros = "";
    for (i=(len2-1);i>=0;i--){
        zeros = "";
        for (j=(len2-1);j>i;j--){
            zeros = zeros + "0";
        }
        carry = 0; sol = "";
        for (j=(len1-1);j>=0;j--){
            cal = (b[i]-'0')*(a[j]-'0')+carry;
            put = cal%10;
            carry = cal/10;
            sol = to_string(put) + sol;
            if (j==0){
                if (carry!=0)
                    sol = to_string(carry) + sol;
            }
        }
        if (ans=="") ans = sol;
        else ans = Sum(ans,(sol+zeros));
    }

    return ans;
}

vector<string> quotientRemainder(string a, string b){
    //It returns vec[0]->quotient, vec[1]->remainder
    //It is like a/b
    removeExtraLeadingZero(a);
    removeExtraLeadingZero(b);
    vector<string> vec;
    if (b=="0"){
        vec.push_back("undefined");
        vec.push_back("undefined");
    }
    else if (a=="0"){
        vec.push_back("0");
        vec.push_back("0");
    }

    string quotient = "", remainder = "";
    if (a==b) {
        quotient = "1";
        remainder = "0";
    }
    else if (a.size()<b.size()) {
        quotient = "0";
        remainder = a;
    }
    else {
        //do calculation here
        //make multiplication table of b
        string remAns = a;
        int take = b.size(); int i;
        string number, multiplend = "";
        string prevNote="", remNumber = "";
        int start = 0, stop = 0;

        while(stop == 0){
            if (start == 0){
                number = remAns.substr(start,take);
                if (number==b){ 
                    remNumber = "";
                    number = "";
                    quotient += "1"; 
                    if (take==(a.size())){
                        remAns = "";
                        break;
                    }
                    remAns = remAns.substr(start+take, remAns.size()-start-take+1);
                    start = start + take;
                    take = 1;
                    continue;
                }
                else if (number<b) {
                    take ++;
                }
                number = remAns.substr(start,take);
            }
            else {
                number = remNumber+remAns[0]; 
            }
            //make multiplication table from 1 to 9
            prevNote = "0";
            for (i=1;i<=9;i++){
                multiplend = Multiply(b, to_string(i));
                if ((multiplend.size()>number.size()))
                    break;
                else if ((multiplend.size()<number.size())){
                    prevNote = multiplend;
                    continue;
                }
                else {
                    if (strcmp(multiplend.c_str(), number.c_str())>0) break;
                    else {
                        prevNote = multiplend;
                        continue;
                    }
                }
            }
            quotient += to_string(i-1);
            remNumber = Subtract(number, prevNote);
            if (start < (a.size()-1))
                remAns = a.substr(start + take, (a.size()-start - take+1));
            // cout<<"number = "<<number<<" remNumber = "<<remNumber<<" remAns = "<<remAns<<" quotient = "<<(i-1)<<endl;
            start = start + take;
            if (start == take){
                take = 1; //we take extra 1 integer after first
            }
            if (start >= (a.size())) stop = 1;
        }
        remainder = remNumber;
    }

    vec.push_back(quotient);
    vec.push_back(remainder);

    return vec;
}

string Divide(string a, string b, int method = 0, int digitAfterDecimal = 3){
    //this function is like a/b
    //method = 0 means answer will be in quotient, remainder and will return empty
    //method = 1 means answer will be in desired precision and will return answer

    vector<string> vec;
    vec = quotientRemainder(a,b);

    string quotient = "", remainder = "";
    quotient = vec[0]; remainder = vec[1];

    cout<<"Result of "<<a<<"/"<<b<<endl;
    cout<<"Quotient = "<<quotient<<endl;
    cout<<"Remainder = "<<remainder<<endl;

    if (method == 0) return "";

    string newNumber = remainder;
    int i;
    string addZeros = "";

    vector<string> vec1;
    string quotient1 = "", temp="";

    for (i=0;i<digitAfterDecimal;i++){
        newNumber += "0";
        vec1 = quotientRemainder(newNumber, b);
        quotient1 += vec1[0];
        newNumber = vec1[1];
    }
    string ans = quotient + "." + quotient1;
    cout<<"Answer = "<<ans<<endl;

    return "";
}

string Factorial(int n){
    //n is less than or equal to 100 now
    //n holds less than or equal to 32765
    string ans = "1";
    int i;
    for (i=n;i>=2;i--){
        if (ans!="1") ans = Multiply(ans,to_string(i));
        else ans = to_string(i);
    }
    return ans;
}

int main(){
    cout<<"Hello World!"<<endl;
    string a = "99";
    string b = "9";
    string add = Sum(a,b);
    cout<<a<<" + "<<b<<" = "<<add<<endl;
    string mul = Multiply(a,b);
    cout<<a<<" X "<<b<<" = "<<mul<<endl;
    string m = Factorial(100);
    cout<<"Factorial of 100 = "<<m<<endl;
    cout<<"Length of Factorial = "<<m.size()<<endl;

    string c = "5879";
    string d = "7576";
    string sub = Subtract(c,d);
    cout<<c<<" - "<<d<<" = "<<sub<<endl;

    string e = "2223";
    string f = "222";
    Divide(e,f,1,5);
    
    return 0;
}
