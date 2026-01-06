#include<iostream>
#include<string>
using namespace std;

//Leetcode "Maximum Swap"

class Solution {
public:
    int maximumSwap(int num) {
        string numString = to_string(num);
        int len = numString.length();
        int numArray[len],temp=0;
        for (int i=0;i<len;i++){
            numArray[i] = numString[i] - '0';
        }
        int max,maxIndex = 0;
        for (int i=0;i<len;i++){
            max = numArray[i]; maxIndex = i;
            for (int j=(i+1);j<len;j++){
                cout<<numArray[j]<<"\t";
                if (maxIndex==i){
                    if (max<numArray[j]){
                        cout<<"Exchange\t";
                        max = numArray[j];
                        maxIndex = j;
                    }
                }
                else {
                    if (max<=numArray[j]){
                        cout<<"Exchange\t";
                        max = numArray[j];
                        maxIndex = j;
                    }
                }
            }
            cout<<endl;
            if (i!=maxIndex){
                //swap and return
                temp = numArray[maxIndex];
                numArray[maxIndex] = numArray[i];
                numArray[i] = temp;
                break;
            }
        }
        int ans = 0;
        for (int i=0;i<len;i++){
            ans = ans*10 + numArray[i];
        }
        return ans;
    }
};