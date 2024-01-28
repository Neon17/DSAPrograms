// Binary Sub Trees

#include <iostream>
using namespace std;

struct bnode {
    int info;
    struct bnode *left;
    struct bnode *right;
    // struct bnode *parent;
};

class Tree {

    // bnode father(bnode n, bnode T);
    // bnode T not required as class Tree has main node root as the tree so eliminated in all

    protected:    
    struct bnode *root;

    public:

    Tree(){
        root = NULL;
    }


    bnode* Father(bnode* n, bnode *nod);
    bnode* Root(Tree* T);
    bnode* Root();
    bnode* leftChild(bnode *n);
    bnode* rightChild(bnode *n);
    void Info(bnode* n);
    bnode* Sibling(bnode* n, bnode* sib);
    bnode* Size();
    bool SetLeft(Tree* S);
    bool SetRight(Tree* S);
    void PreOrder(bnode *n, int key);
    void PostOrder(bnode *n, int key);
    void InOrder(bnode *n, int key);
    void Search(int k);
    //k is key
    void Insert(bnode *n, int k);
    void Delete(bnode *n, int k);
    int FindMin();
    int FindMax();

};

bnode* Tree::leftChild(bnode *n){
    return n->left;
}

bnode* Tree::rightChild(bnode *n){
    return n->right;
}

bnode* Tree::Root(Tree* T){
    return T->root;
}

bnode* Tree::Root(){
    return root;
}

void Tree::Info(bnode *n) {
    cout<<"Data = "<<n->info<<endl;
    cout<<"Left Subtree"<<((n->left==NULL)?"Present":"Absent")<<endl;
    cout<<"Right Subtree"<<((n->right==NULL)?"Present":"Absent")<<endl;
}

bnode* Tree::Father (bnode *n, bnode* nod){
    if ((n->left==nod)||(n->right==nod)){
        cout<<"Match Found.."<<endl;
        return n;
    }
    Father(n->left, nod);
    Father(n->right, nod);

    //Below can be done because we know n is either shifted left or right but doesn't go to root
    if (n==root){
        cout<<"Root Node doesn't have any father.."<<endl;
        return NULL;
    }
}

bnode* Tree::Sibling(bnode* n, bnode *sib){
    if (n == NULL){
        return NULL;
    }
    if (n == root){
        cout<<"Root Node doesn't have any sibling.."<<endl;
        return NULL;
    }
    if (n==sib){
        cout<<"Match Found.."<<endl;
        return n;
    }

    Sibling(n->left,sib);
    Sibling(n->right,sib);

    //Below can be done because we know n is either shifted left or right but doesn't go to root
    if (n==root){
        cout<<"Root doesn't have any sibling"<<endl;
        return NULL;
    }
}

void Tree::PostOrder(bnode *n, int key = 0){
    //key means key to be searched
    
    if (n==NULL){return;}
   
    PostOrder(n->left);
    PostOrder(n->right);
    cout<<n->info<<endl;
}

void Tree::PreOrder(bnode *n, int key = 0){ 
    //key means key to be searched
   
    if (n==NULL){return;}

    cout<<n->info<<endl;
    PreOrder(n->left);
    PreOrder(n->right);
}

void Tree::InOrder(bnode *n, int key=0){
    //key means key to be searched

    if (n==NULL){return;}

    InOrder(n->left);
    cout<<n->info<<endl;
    InOrder(n->right);
}

void Tree::Insert(bnode* n, int key){
    if ((n==root)&&(n==NULL)){
        n = new bnode;
        n->info = key;
        return;
    }
    if (n==NULL){return;}
    //We can do directly n = NewNode without checking below after n = NULL after redirecting to it correctly
    //We haven't done to prevent user from inserting NULL as parameter like Insert(NULL,5);

    if ((n->left==NULL)&&(n->right==NULL)){
        struct bnode *NewNode = new bnode;
        NewNode->info = key;
        if (key>n->info){
            n->right = NewNode;
        }
        else {
            n->left = NewNode;
        }
    }
    else if ((n->left == NULL)&&(key<=n->info)){
        struct bnode *NewNode = new bnode;
        NewNode->info = key;
        n->left = NewNode;
    }
    else if ((n->right == NULL)&&(key>n->info)){
        struct bnode *NewNode = new bnode;
        NewNode->info = key;
        n->right = NewNode;
    }

    if (key>n->info){
        Insert(n->right,key);
    }
    else {
        Insert(n->left,key);
    }
}

void Tree::Delete(bnode *n, int k){
    if (n->info==k){
        //We need parent to delete child not child itself
    }
    if (k<n->info){
        Delete(n->left,k);
    }
    else if (k>n->info){
        Delete(n->right,k);
    }
}

