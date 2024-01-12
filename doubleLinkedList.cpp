#include <iostream>
using namespace std;


struct node {
    struct node *prev;
    int data;
    struct node *next;
};

class list {
    struct node *START = NULL;

    list() {
        START = new node;
    }
    void insert_at_end(int data){

        struct node *temp;
        temp = START;

        if (temp==NULL){
            temp->prev = NULL;
            temp->data = data;
            temp->next = NULL;
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

        while(temp->next!=NULL){
            temp->data = temp->next->data;
            temp = temp->next;
        }

        while (temp->next->next!=NULL){
            temp = temp->next;
        }
        delete(temp->next);
        temp->next = NULL;
    }

    void insert_at(int data, int pos){

        struct node *temp;
        temp = START;

        int i;
        for (i=0;i<(pos-1);i++){
            temp = temp->next;
        }

        
    }

};

int main() {
    return 0;
}