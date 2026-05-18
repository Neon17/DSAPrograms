#include <iostream>
using namespace std;

struct node {
    struct node *leftChild;
    struct node *rightChild;
    int data;
};

class BinarySearchTree{
    struct node *root = NULL;
    public:
        void insertNode(int data){
            if (root==NULL){
                root = new node();
                root->data = data;
                return;
            }
            struct node *temp;
            temp = root;
            int status = 0;
            while(status==0){
                if (data<temp->data){
                    if (temp->leftChild==NULL){
                        temp->leftChild = new node();
                        temp->leftChild->data = data;
                        status = 1;
                    }
                    temp = temp->leftChild;
                }
                else {
                    if (temp->rightChild==NULL){
                        temp->rightChild = new node();
                        temp->rightChild->data = data;
                        status = 1;
                    }
                    temp = temp->rightChild;
                }
            }
        }
        void deleteNode(int key){
            deleteNode(root,key);
        }
        void deleteNode(struct node *temp, int key){
            //inorder successor
            if (key<temp->data){
                deleteNode(temp->leftChild,key); return;
            }
            else if (key>temp->data){
                deleteNode(temp->rightChild,key); return;
            }
            struct node *successor;
            if ((temp->rightChild!=NULL)&&(temp->leftChild!=NULL)){
                struct node *succParent;
                successor = temp;
                while((successor->leftChild!=NULL)&&(successor->rightChild!=NULL)){
                    succParent = successor;
                    if ((successor->leftChild!=NULL))
                        successor = successor->leftChild;
                    else if (successor->rightChild!=NULL){
                        successor = successor->rightChild;
                    }
                }
                temp->data = successor->data;
                if (succParent->leftChild==NULL){
                    delete(succParent->rightChild);
                    succParent->rightChild = NULL;
                }
                else {
                    delete(succParent->leftChild);
                    succParent->leftChild = NULL;
                }
            }
            else if (temp->rightChild==NULL){
                successor = temp->leftChild;
                delete temp;
                temp = successor;
                
            }
            else{
                successor = temp->rightChild;
                delete temp;
                temp = successor;
            }
        }
        void postOrderTraversal(){
            cout<<"Post Order Traversal"<<endl;postOrderTraversal(root);cout<<endl;
        }
        void preOrderTraversal(){
            cout<<"Pre Order Traversal"<<endl;preOrderTraversal(root);cout<<endl;
        }
        void inOrderTraversal(){
            cout<<"In Order Traversal"<<endl;inOrderTraversal(root);cout<<endl;
        }

    private:
        void postOrderTraversal(struct node *root){
            if (root==NULL){ return; }
            if ((root->leftChild==NULL)&&(root->rightChild==NULL)){
                cout<<root->data<<",";
                return;
            }
            postOrderTraversal(root->leftChild);
            postOrderTraversal(root->rightChild);
            cout<<root->data<<",";
        }
        void preOrderTraversal(struct node *root){
            if (root==NULL){ return; }
            if ((root->leftChild==NULL)&&(root->rightChild==NULL)){
                cout<<root->data<<",";
                return;
            }
            cout<<root->data<<",";
            if (root->leftChild!=NULL)
                preOrderTraversal(root->leftChild);
            if (root->rightChild!=NULL)
                preOrderTraversal(root->rightChild);
        }
        void inOrderTraversal(struct node *root){
            if (root==NULL){ return; }
            if ((root->leftChild==NULL)&&(root->rightChild==NULL)){
                cout<<root->data<<",";
                return;
            }
            if (root->leftChild!=NULL)
                inOrderTraversal(root->leftChild);
            cout<<root->data<<",";
            if (root->rightChild!=NULL)
                inOrderTraversal(root->rightChild);
        }
};


int main(){
    BinarySearchTree b1;
    b1.insertNode(12);
    b1.insertNode(3);
    b1.insertNode(5);
    b1.insertNode(2);
    b1.insertNode(24);
    b1.insertNode(30);
    b1.insertNode(16);
    b1.postOrderTraversal();
    b1.preOrderTraversal();
    b1.inOrderTraversal();
    b1.deleteNode(24);
    b1.postOrderTraversal();
    b1.preOrderTraversal();
    b1.inOrderTraversal();
    return 0;
}
