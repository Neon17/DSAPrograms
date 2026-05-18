#include <iostream>
using namespace std;


struct node {
    struct node *prev;
    int data;
    struct node *next;
};

class list {
    struct node *START = NULL;

    public:

    list() {
        START = NULL;
    }
    void insert_at_end(int data){

        struct node *temp;
        temp = START;

        if (temp==NULL){
            START = new node;
            START->prev = NULL;
            START->data = data;
            START->next = NULL;
            return;
        }
        
        while (temp->next!=NULL) {
            temp = temp->next;
        }

        temp->next = new node;
        temp->next->data = data;
        temp->next->next = NULL;
        temp->next->prev = temp;

    }

    void insert_at_beginning(int data){

        struct node *temp;
        temp = START;

        if (temp==NULL){
            START = new node;
            START->prev = NULL;
            START->data = data;
            START->next = NULL;
            return;
        }

        while (temp->next!=NULL){
            temp = temp->next;
        }

        temp->next = new node;
        temp->next->prev = temp;
        temp->next->next = NULL;

        while (temp!=NULL){
            temp->next->data = temp->data;
            temp = temp->prev;
        }

        temp = START;
        temp->data = data;

    }

    void insert_at(int data, int pos){

        int TheEnd = 0;
        struct node *temp1, *temp2;

        if (pos<=1){
            insert_at_beginning(data);
            return;
        }
        
        temp1 = START;
        temp2 = START;
        //temp1 goes at the position (pos)
        //temp2 goes at the last and make new node

        if (temp1==NULL){
            START = new node;
            START->prev = NULL;
            START->data = data;
            START->next = NULL;
            return;
        }

        while (temp2->next!=NULL){
            temp2 = temp2->next;
        }
        temp2->next = new node;
        temp2->next->prev = temp2;
        temp2->next->next = NULL;

        int i;
        for (i=0;i<(pos-1);i++){
            temp1 = temp1->next;
            if (temp1->next==NULL){
                TheEnd = 1;
                break;
            }
        }

        if (TheEnd==1){
            insert_at_end(data);
            return;
        }

        while (temp2->next!=temp1){
            temp2->next->data = temp2->data;
            temp2 = temp2->prev;
        }

        temp1->data = data;
        
    }

    void delete_from_beginning(){
        if (START == NULL){
            cout<<"Empty List"<<endl;
        }
        struct node *temp = START;
        while(temp->next->next!=NULL){
            temp->data = temp->next->data;
            temp = temp->next;
        }
        temp->data = temp->next->data;
        delete(temp->next);
        temp->next = NULL; 
    }

    void delete_from_end(){
        struct node *temp = START;
        while (temp->next->next==NULL){
            temp = temp->next;
        }
        delete(temp->next);
        temp->next = NULL;
    }

    void delete_from (int pos){
        struct node *temp = START;
        int i;
        for (i=0;i<(pos-1);i++){
            temp = temp->next;
        }
        while(temp->next->next!=NULL){
            temp->data = temp->next->data;
            temp = temp->next;
        }
        temp->data = temp->next->data;
        delete(temp->next);
        temp->next = NULL;
    }

    void display() {
        struct node *temp = START;
        cout<<"-----------------------------------"<<endl;
        cout<<"Linked List Item"<<endl;
        while(temp!=NULL){
            cout<<temp->data<<endl;
            temp = temp->next;
        }
    }

};

int main() {
    list l;
    l.insert_at_end(5);
    l.insert_at_end(7);
    l.insert_at_beginning(3);
    l.insert_at_beginning(1);
    l.display();
    l.insert_at(4,3);
    l.display();
    l.delete_from_beginning();
    l.display();
    l.delete_from(2);
    l.display();


    return 0;
}