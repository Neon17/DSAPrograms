//Sum of Subset Problem is solved by my made dynamic approach
//Taking reference from knapsack, I developed algorithm myself
//It only finds one solution
//solution is stored in vector which stores indices of included array(input elements)
//This can run slower because we have to print table of O(n*n) 
//Time Complexity = O(n*n)

#include <bits/stdc++.h>
using namespace std;

class Subset {
    vector <int> arr;
    int targetSum;
    vector <vector<int>> table;
    vector <int> solution;
    public:
        Subset(){

        }
        Subset(int targetSum){
            this->targetSum = targetSum;
        }
        void fill(){
            int size,i,temp;
            cout<<"Enter the target sum: ";
            cin>>targetSum;
            cout<<"Enter the number of elements = ";
            cin>>size;
            for (i=0;i<size;i++){
                cout<<"Enter the element : ";
                cin>>temp;
                arr.push_back(temp);
            }
        }
        void randomFill(){
            // targetSum = 3;
            // arr.push_back(1); arr.push_back(2); arr.push_back(3);

            // targetSum = 30;
            // arr = {3, 34, 4, 12, 5, 2};
            
            //abdul bari subset problem 
            // arr = {5,10,12,13,15,18};
            // targetSum = 30;

            //jenny lectures subset by dynamic
            arr = {1,2,5,9,4};
            targetSum = 18;
        }
        void initializeTable(){
            int i,j,rowSize = arr.size();
            vector <int> temp;
            for (j=0;j<=targetSum;j++)
                temp.push_back(0);
            for (i=0;i<=rowSize;i++)
                table.push_back(temp);
        }
        void fillTable(){
            //It fills table with size (totalItemsCount+1)*(targetSum+1)
            initializeTable();
            cout<<"-----------Table-------------"<<endl;
            int i,j,rowSize = arr.size(),temp=0;
            for (i=1;i<=rowSize;i++){
                for (j=1;j<=targetSum;j++){
                    if (j>=arr[i-1]){
                        temp = max<int>(table[i-1][j],(table[i-1][j-arr[i-1]]+arr[i-1]));
                        table[i][j] = temp;
                    }
                    else 
                        table[i][j]=table[i-1][j];
                }
            }
        }
        void displayTable(){
            int i,j;
            for (i=0;i<=arr.size();i++){
                for (j=0;j<=targetSum;j++){
                    cout<<table[i][j]<<"\t";
                }
                cout<<endl;
            }
        }
        void solveTable(){
            int i,j,notedown = -1;
            int size = arr.size();
            int remaining = targetSum;
            if (table[size][targetSum]!=targetSum)
                return;
            for (i=size;i>=1;i--){
                for (j=targetSum;j>=0;j--){
                    if (table[i][j]==targetSum){
                        notedown = i;
                        break;
                    }
                }
                if (notedown!=-1){
                    remaining -= arr[i-1];
                    solution.push_back(i-1);
                }
                if (remaining<=0)
                    break;
            }
        }
        void displayResult(){
            cout<<"---------Solution--------------"<<endl;
            if (solution.size()==0){
                cout<<"No Solution Found!"<<endl;
                return;
            }
            int i;
            for (i=0;i<solution.size();i++){
                cout<<arr[solution[i]]<<"\t";
            }
            cout<<endl;
        }
};

int main(){
    Subset s;
    s.randomFill();
    s.fillTable();
    s.displayTable();
    s.solveTable();
    s.displayResult();
    return 0;
}

