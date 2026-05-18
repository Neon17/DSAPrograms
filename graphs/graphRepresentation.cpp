#include<bits/stdc++.h>
using namespace std;

//adjacency matrix representation and adjacency list

struct node {
    int number;
    int weight;
    struct node *edges;
    struct node *anotherVertex;
};

class GraphList{
    int numberVertices;
    struct node *graph;
    bool *visited;

    public:

    GraphList(int numberVertices){
        this->numberVertices = numberVertices;
        graph = new node();
        visited = new bool[numberVertices];
        int i;
        for (i=0;i<numberVertices;i++){
            visited[i] = false;
        }
    }
    void fill(){
        int i,j;
        struct node *temp = graph;
        int numberEdges = 0;
        cout<<endl;
        for (i=0;i<numberVertices;i++){
            cout<<"Vertex Number: ";
            cin>>temp->number;
            cout<<"Weight of self Loop: ";
            cin>>temp->weight;
            temp->anotherVertex = new node();
            temp = temp->anotherVertex;
        }
        temp = graph;
        cout<<"Number of Edges in the Graph = ";
        cin>>numberEdges;
        int startVertex, endVertex,status,weight;
        struct node *startNode, *endNode;
        for (i=0;i<numberEdges;i++){
            cout<<"Enter starting vertex: ";
            cin>>startVertex;
            cout<<"Enter ending vertex: ";
            cin>>endVertex;
            cout<<"Enter weight of edge: ";
            cin>>weight;
            cout<<"Is the edge bidirectional?\n1.Yes\n2.No"<<endl;
            cout<<"Enter your choice in number: ";
            cin>>status;
            startNode = graph; endNode = graph;
            while(startNode->number != startVertex){
                startNode = startNode->anotherVertex;
            }
            while(endNode->number != endVertex){
                endNode = endNode->anotherVertex;
            }
            struct node *startEdge = startNode;
            while(startEdge->edges!=NULL){
                startEdge = startEdge->edges;
            }
            startEdge->edges = new node();
            startEdge->edges->number = endVertex;
            startEdge->edges->weight = weight;
            if (status == 1){
                struct node *endEdge = endNode;
                while(endEdge->edges!=NULL){
                    endEdge = endEdge->edges;
                }
                endEdge->edges = new node();
                endEdge->edges->number = startVertex;
                endEdge->edges->weight = weight;
            }
            display();
        }
    }
    void BFS(){
        //breadth first traversal
        //all visited edge is listed in queue2
        //all adjacent unvisited edge is listed in queue1
        cout<<endl<<"Breadth First Search = \t";
        struct node *temp = graph;
        list<int> queue1, queue2;
        queue1.push_back(temp->number);
        while((queue2.empty())||(queue2.size()!=numberVertices)){
            struct node *tempEdge = temp->edges;
            while(tempEdge!=NULL){
                if ((find(queue2.begin(),queue2.end(),tempEdge->number)==queue2.end())){
                    //if not already visited
                    if (find(queue1.begin(),queue1.end(),tempEdge->number)==queue1.end()){
                        //if not found that number in queue
                        queue1.push_back(tempEdge->number);
                    }
                }
                tempEdge = tempEdge->edges;
            }
            queue2.push_back(queue1.front());
            queue1.pop_front();
            // cout<<queue2.back()<<endl;
            temp = graph;
            while(temp->number != queue2.back()){
                temp = temp->anotherVertex;
            }
        }   
        for (int i:queue2){
            cout<<i<<"\t";
        }
        cout<<endl;
    }
    void DFS(){
        //depth first traversal
        cout<<endl<<"DFS Search = \t";
        struct node *temp = graph;
        list<int> stack;
        list<int> visited;
        stack.push_back(temp->number);
        while ((visited.empty())||(visited.size()!=numberVertices)){
            // cout<<"Current Visiting Vertex = "<<stack.back()<<endl;
            struct node *tempEdge;
            int number = stack.back();
            visited.push_back(number);
            stack.pop_back();
            //pop_back() and printing means visited
            temp = graph;
            while(temp->number != number){
                temp = temp->anotherVertex;
            }
            tempEdge = temp->edges;
            while(tempEdge!=NULL){
                if ((find(stack.begin(),stack.end(),tempEdge->number)==stack.end())){
                    //if not found that number in stack
                    if ((find(visited.begin(),visited.end(),tempEdge->number)==visited.end())){
                        //if not visited
                        stack.push_back(tempEdge->number);
                    }
                }
                tempEdge = tempEdge->edges;
            }
        }
        for (int i:visited){
            cout<<i<<"\t";
        }
        cout<<endl;
    }
    void searchDFS(){
        list<int> stack,visited;
        int vertex = graph->number; //starting vertex
        RecursiveDFS(vertex,visited,stack);
        cout<<"DFS Recursive Search = \t";
        for (int i:visited){
            cout<<i<<"\t";
        }
        cout<<endl;
    }
    void RecursiveDFS(int vertex, list<int> &visited, list<int> &stack){
        if (!(visited.empty())){
            if (visited.size()==numberVertices)
                return;
        }
        visited.push_back(vertex);
        struct node *temp = graph;
        while (temp->number!=vertex)
            temp = temp->anotherVertex;
        struct node *tempEdges = temp->edges;
        while(tempEdges!=NULL){
            if ((find(stack.begin(),stack.end(),tempEdges->number)==stack.end())){
                //if not found that number in stack
                if ((find(visited.begin(),visited.end(),tempEdges->number)==visited.end())){
                    //if not visited
                    stack.push_back(tempEdges->number);
                }
            }
            tempEdges = tempEdges->edges; 
        }
        int number = stack.back();
        stack.pop_back();
        RecursiveDFS(number,visited,stack);
    }
    void display(){
        struct node *temp = graph;
        int i;
        cout<<"-------------Adjacency List-------------"<<endl;
        for (i=0;i<numberVertices;i++){
            cout<<temp->number;
            struct node *tempEdge = temp->edges;
            if (tempEdge!=NULL)
                cout<<"\t->";
            while(tempEdge!=NULL){
                cout<<"\t"<<tempEdge->number;
                tempEdge = tempEdge->edges;
            }
            temp = temp->anotherVertex;
            cout<<endl;
        }
        cout<<"------------------------------------------"<<endl;
    }
};

class GraphMatrix {
    int numberVertices;
    int **graph;
    
    public:

    GraphMatrix(int numberVertices){
        this->numberVertices = numberVertices;
        graph = new int *[numberVertices];
        int i;
        for (i=0;i<numberVertices;i++){
            graph[i] = new int [numberVertices];
        }
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
    void display(){
        int i,j;
        cout<<"-------------Adjacency Matrix-------------"<<endl;
        cout<<" ";
        for (i=0;i<numberVertices;i++){
            cout<<"\t"<<i;
        }
        cout<<endl;
        for (i=0;i<numberVertices;i++){
            cout<<i;
            for (j=0;j<numberVertices;j++){
                cout<<"\t"<<graph[i][j];
            }
            cout<<endl;
        }
        cout<<"------------------------------------------"<<endl;
    }
};

int main(){
    // GraphMatrix *gm = new GraphMatrix(6);
    GraphList *gl = new GraphList(6);
    // gm->fill();
    gl->fill();
    // gm->display();
    // gl->display();
    gl->DFS();
    gl->BFS();
    gl->searchDFS(); //recursive DFS
    return 0;
}


