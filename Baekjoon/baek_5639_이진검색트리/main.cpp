#include <iostream>

using namespace std;

struct node{
    int key;
    node* left;
    node* right;
    node(const int& _key):key(_key), left(NULL), right(NULL){

    }
    void setLeft(node *newLeft){left=newLeft;}
    void setRight(node *newRight){right=newRight;}
};

node* insert(node* root, node* node){
    if(root==NULL) return node;
    if(root->key>node->key){
        root->setLeft(insert(root->left, node));
    }
    else
        root->setRight(insert(root->right, node));
    return root;
}

void postOrder(node* root){
    if(root==NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->key<<'\n';
}
int main() {
    int in;
    node* root=NULL;
    while(cin>>in){
        //cin>>in;
        root=insert(root, new node(in));
    }
    postOrder(root);
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}