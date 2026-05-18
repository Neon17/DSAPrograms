//Solving Bellman-Ford using dynamic programming approach
#include <bits/stdc++.h>
using namespace std;

class Graph{
    int numberVertices;
    int **graph;
    float *d; //shortest distance from some source
    int startVertex;

    public:
    Graph(int numberVertices){
        this->numberVertices = numberVertices;
        graph = new int*[numberVertices];
        int i;
        for (i=0;i<numberVertices;i++){
            graph[i] = new int[numberVertices];
        }
    }
    Graph(){
        numberVertices = 7;
        graph = new int*[numberVertices];
        int i;
        for (i=0;i<numberVertices;i++){
            graph[i] = new int[numberVertices];
        }
    }
    void randomFill(){
        int i,j;
        for (i=0;i<numberVertices;i++){
            for (j=0;j<numberVertices;j++){
                graph[i][j] = 0;
            }
        }
        graph[0][1] = 6;
        graph[0][2] = 5;
        graph[0][3] = 5;
        graph[1][4] = -1;
        graph[2][1] = -2;
        graph[2][4] = 1;
        graph[3][2] = -2;
        graph[3][5] = -1;
        graph[4][6] = 3;
        graph[5][6] = 3;
        //Are these graph vertices are from Abdul Bari
    }
    void fill(){
        cout<<endl;
        cout<<"Enter the weight of edge between vertices.."<<endl;
        int i,j;
        for (i=0;i<numberVertices;i++){
            for (j=0;j<numberVertices;j++){
                cout<<"Weight between "<<i<<" and "<<j<<" = ";
                cin>>graph[i][j];
            }
        }
    }
    void fillDistance(int startVertex){
        d = new float[numberVertices];
        int j;
        this->startVertex = startVertex;

        //initialize the distances i.e make source distance 0 other infinity
        for (j=0;j<numberVertices;j++){
            if (j==startVertex){
                d[j] = 0;
                continue;
            }
            d[j] = numeric_limits<float>::infinity();
        }
    }
    void shortestDistance(){
        //initialization done on void fillDistance(int startVertex);
        int i,k;

        // display();
        // cout<<endl;
        // char c = getchar();
        list<int> queue1,queue2;
        int vertex = 0;
        //go through every edges 6 times
        for (i=0;i<6;i++){
            do {
                queue2.push_back(vertex);
                for (k=0;k<numberVertices;k++){
                    if (graph[vertex][k]==0){continue;}
                    // cout<<"graph[vertex][k] = "<<graph[vertex][k]<<endl;
                    // cout<<"d[k] = "<<d[k]<<endl;
                    // cout<<"d[vertex] = "<<d[vertex]<<endl;
                    if (d[vertex]+graph[vertex][k]<d[k])
                        d[k] = d[vertex] + graph[vertex][k];
                    //to push in queue we need to find out whether it is already in queue or visited
                    if (find(queue1.begin(),queue1.end(),k)==queue1.end()){
                        if (find(queue2.begin(),queue2.end(),k)==queue2.end()){
                            queue1.push_back(k);
                        }
                    }
                }
                // display();
                // char c = getchar();
                vertex = queue1.front();
                queue1.pop_front();
            } while (queue2.size()!=numberVertices);
            queue1.clear();
            queue2.clear();
        }
    }
    void display(){
        int i;
        for (i=0;i<numberVertices;i++){
            if (i==startVertex)
                continue;
            cout<<"Distance from "<<startVertex<<" to "<<i<<" = "<<d[i]<<endl;
        }
    }
};

int main(){
    Graph g;
    g.randomFill();
    g.fillDistance(0);
    g.shortestDistance();
    g.display();

    return 0;
}
