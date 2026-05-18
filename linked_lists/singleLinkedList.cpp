#include <iostream>
using namespace std;


struct node {
    int data;
    struct node *next;
};


class list {
    struct node *START;
    struct node *temp;
    int counter = 0;
    public:
        list() {
            START = NULL;
        }

        void insert_at_end(int data) {

            if (START == NULL){
                START = new node;
                START->data = data;
                START->next = NULL;
                counter++;
                return;
            }

            int i;
            temp = START;
            for (i=0;i<(counter-1);i++){
                temp = temp->next;
            }
            temp->next = new node;
            temp->next->data = data;
            temp->next->next = NULL;
            counter++;

        }

        void insert_at(int data, int index){
            if (index<=1){
                insert_at_beginning(data);
                return;
            }
            else if (index>counter){
                insert_at_end(data);
                return;
            }
            struct node *NewNode;
            temp = START;
            int i;
            for (i=0;i<(index-2);i++){
                temp = temp->next;
            }
            NewNode = new node;
            NewNode->data = data;
            NewNode->next = temp->next;
            temp->next = NewNode;
            counter++;
        }

        void insert_at_beginning(int data){
            struct node *NewNode;
            NewNode = new node;
            NewNode->data = data;
            NewNode->next = START;
            START = NewNode;
            counter++;
        }

        void delete_from_beginning(){
            temp = START;
            int i;
            for (i=0;i<(counter-1);i++){
                temp->data = temp->next->data;
                temp = temp->next;
            }
            delete(temp->next);
            temp->next = NULL;
            counter--;
        }

        void delete_from(int index){
            if (index<=1){
                delete_from_beginning();
                return;
            }
            else if (index>=counter){
                delete_from_end();
                return;
            }
            temp = START;
            int i;
            for (i=0;i<(index-2);i++){
                temp = temp->next;
            }
            for (i=(index-1);i<(counter-1);i++){
                temp = temp->next;
                temp->data = temp->next->data;                
            }
            delete(temp->next);
            temp->next = NULL;
            counter--;
        }

        void delete_from_end(){
            temp = START;
            int i;
            for (i=0;i<(counter-2);i++){
                temp = temp->next;
            }
            delete(temp->next);
            temp->next = NULL;
            counter--;
        }

        void searchData(int data) {
            int i;
            temp = START;
            do{
                if (temp->data == data){
                    cout<<"Data found on list in rank "<<(i+1)<<endl;
                    return;
                }
                temp = temp->next;
            } while (temp!=NULL);
            if (temp==NULL){
                cout<<"Data not found"<<endl;
            }
        }

        void display() {
            int i;
            if (START == NULL){
                cout<<"List is Empty"<<endl;
                return;
            }
            temp = START;
            for (i=0;i<counter;i++){
                cout<<temp->data<<endl;
                temp = temp->next;
            }
        }
};


int main(){
    list l;
    l.insert_at_end(5);
    l.insert_at_end(6);
    l.insert_at_end(7);
    l.insert_at_end(8);
    l.insert_at(10,1);
    l.display();
    l.delete_from(3);
    cout<<"After deleting"<<endl;
    l.display();
    l.searchData(6);

    return 0;
}