#include <iostream>
using namespace std;

struct Item {
    string name;
    int profit;
    int weight;
};

class Bucket {
    struct Item *item; int capacity; int items_count;
    public: 
        Bucket(){
            // cout<<"Enter total capacity of bucket: ";
            // cin>>capacity;
            capacity = 17;
            // cout<<"Enter the number of items: ";
            items_count = 5;
            // cin>>items_count;
            item = new Item[sizeof(Item)*items_count];
        }
        void collectTotalItems() {            
            int i;
            for (i=0;i<items_count;i++){
                cout<<"Enter object name: ";
                cin>>item[i].name;
                cout<<"Enter profit: ";
                cin>>item[i].profit;
                cout<<"Enter weight of object: ";
                cin>>item[i].weight;
                cin.clear();
            }
        }
        void fillRandom(){
            int i;
            for (i=0;i<items_count;i++){
                item[i].name = "Item"+to_string(i);
                item[i].profit = rand()%20+1;
                item[i].weight = rand()%20+1;
            }
            fill();
        }
        void sortByPW(){
            //sort by profit/weight
            int i,j;
            for (i=0;i<items_count;i++){
                for (j=(i+1);j<items_count;j++){
                    float a,b;
                    a = (item[i].profit/item[i].weight);
                    b = (item[j].profit/item[j].weight);
                    if (a<b){
                        struct Item temp;
                        temp = item[i];
                        item[i] = item[j];
                        item[j] = temp;
                    }
                }
            }         
        }
        void fill(){
            sortByPW();
            float x[items_count],totalProfit=0;
            int i,totalWeight=0;
            for (i=0;i<items_count;i++){
                totalWeight += item[i].weight;
                if (totalWeight<capacity){
                    x[i] = 1;
                    totalProfit += item[i].profit;
                }
                else {
                    totalWeight -= item[i].weight;
                    int diff = capacity - totalWeight;
                    if (diff == 0){
                        x[i] = 0;
                    }
                    else {
                        x[i] = (float)diff/item[i].weight;
                        totalWeight = capacity;
                    }
                }
            }
            //displaying information
            cout<<"Total Capacity = "<<capacity<<endl;
            cout<<"Objects Given\t";
            for (i=0;i<items_count;i++){
                cout<<item[i].name<<"\t";
            }
            cout<<endl;
            cout<<"Profits Object\t";
            for(i=0;i<items_count;i++){
                cout<<item[i].profit<<"\t";
            }
            cout<<endl;
            cout<<"Weight Object\t";
            for(i=0;i<items_count;i++){
                cout<<item[i].weight<<"\t";
            }
            cout<<endl;
            cout<<"Profit/W\t";
            for (i=0;i<items_count;i++){
                cout<<item[i].profit/item[i].weight<<"\t";
            }
            cout<<endl;
            cout<<"Fraction Taken = ";
            for (i=0;i<items_count;i++){
                printf("%0.2f\t",x[i]);
            }
            cout<<endl;
            cout<<"Total Profit = "<<totalProfit<<endl;
        }
};


int main(){
    cout<<"Knapsack Problem"<<endl;

    Bucket b;
    // b.collectTotalItems();
    b.fillRandom();

    return 0;
}
