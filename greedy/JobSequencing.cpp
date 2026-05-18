#include <iostream>
using namespace std;

struct Job {
    string name;
    int profit;
    int deadline;
};

class Jobs {
    struct Job *job;int jobs_count; int start = 12;
    public: 
        Jobs(){
            jobs_count = 5;
            cout<<"Every Job takes one unit of time.."<<endl;
            job = new Job[sizeof(Job)*jobs_count];
        }
        void collectTotaljobs() {            
            int i;
            for (i=0;i<jobs_count;i++){
                cout<<"Enter object name: ";
                cin>>job[i].name;
                cout<<"Enter profit: ";
                cin>>job[i].profit;
                cout<<"Enter deadline of object: ";
                cin>>job[i].deadline;
                cin.clear();
            }
        }
        void fillRandom(){
            int i;
            for (i=0;i<jobs_count;i++){
                job[i].name = "J"+to_string(i);
                job[i].profit = rand()%20+1;
                job[i].deadline = rand()%12+1;
            }
        }
        void sortByD(){
            //sort by deadline
            int i,j;
            for (i=0;i<jobs_count;i++){
                for (j=(i+1);j<jobs_count;j++){
                    float a,b;
                    a = (job[i].deadline);
                    b = (job[j].deadline);
                    if (a>b){
                        struct Job temp;
                        temp = job[i];
                        job[i] = job[j];
                        job[j] = temp;
                    }
                    else if (a==b){
                        if (job[i].profit<job[j].profit){
                            struct Job temp;
                            temp = job[i];
                            job[i] = job[j];
                            job[j] = temp;
                        }
                    }
                }
            }         
        }
        void pickJobs(){
            sortByD();
            struct Job x[jobs_count];
            int xlength = 0,i,j;
            int status = 0;
            for (i=0;i<jobs_count;i++){
                for (j=0;j<xlength;j++){
                    if ((x[j].deadline==job[i].deadline)){status=1; cout<<"Hello";break;}
                }
                if (status == 0){
                    x[xlength] = job[i];
                    xlength++;
                }
                status = 0;
            }
            displayPickedJobs(x,xlength);
        }
        void displayJobs(){
            //displaying information
            int i;
            cout<<"Job Name\t";
            for (i=0;i<jobs_count;i++){
                cout<<job[i].name<<"\t";
            }
            cout<<endl;
            cout<<"Profits\t\t";
            for(i=0;i<jobs_count;i++){
                cout<<job[i].profit<<"\t";
            }
            cout<<endl;
            cout<<"Deadline\t";
            for(i=0;i<jobs_count;i++){
                cout<<job[i].deadline<<"\t";
            }
            cout<<endl;
            cout<<"Time\t\t";
            for (i=0;i<jobs_count;i++){
                cout<<job[i].deadline-1<<"-"<<job[i].deadline<<"\t";
            }
            cout<<endl;
        }
        void displayPickedJobs(struct Job pickedJobs[], int length){
            int i;
            cout<<"Job Name\t";
            for (i=0;i<length;i++){
                cout<<pickedJobs[i].name<<"\t";
            }
            cout<<endl;
            cout<<"Profits\t\t";
            for(i=0;i<length;i++){
                cout<<pickedJobs[i].profit<<"\t";
            }
            cout<<endl;
            cout<<"Deadline\t";
            for(i=0;i<length;i++){
                cout<<pickedJobs[i].deadline<<"\t";
            }
            cout<<endl;
            cout<<"Time\t\t";
            for (i=0;i<length;i++){
                cout<<pickedJobs[i].deadline-1<<"-"<<pickedJobs[i].deadline<<"\t";
            }
            cout<<endl;
        }
};


int main(){
    cout<<"Knapsack Problem"<<endl;

    Jobs j;
    // b.collectTotaljobs();
    j.fillRandom();
    cout<<"Before choosing Job"<<endl;
    j.displayJobs();
    cout<<"After choosing Job within Deadline"<<endl;
    j.pickJobs();

    return 0;
}


