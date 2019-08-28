#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <bitset>
using namespace std;

struct node {
    node *left, *right;
    node():left(nullptr), right(nullptr) {

    }
    int key;
};

struct Tree {

    node *root;
    string order="";

    Tree():root(nullptr) {

    }

    void insert(node *here, node *input) {
        if(root==nullptr) {
            root=input;
            return;
        }
        if(here->key>input->key) {
            if(here->left!=nullptr)
                insert(here->left, input);
            else
                here->left=input;
        }
        else {
            if(here->right!=nullptr)
                insert(here->right, input);
            else
                here->right=input;
        }
    }

    void insertInterface(int key) {
        node *n=new node;
        n->key=key;
        insert(root, n);
    }

    void traverse(node *here, int cnt) {
        order+=to_string(cnt);
        if(here->left!=nullptr) {
            order+="l";
            traverse(here->left, cnt+1);
        }
        if(here->right!=nullptr) {
            order+="r";
            traverse(here->right, cnt+1);
        }
    }
    void traverse() {
        traverse(root, 0);
    }
};
int main() {
    int n, k;
    cin>>n>>k;
    set<string> ret;
    for(int i=0; i<n; ++i) {
        Tree tree;
        for(int j=0; j<k; ++j) {
            int order; cin>>order;
            tree.insertInterface(order);
        }
        tree.traverse();
        ret.insert(tree.order);
    }
    cout<<ret.size();
    // 오름차순 내림차순 트리 넣는 순서
    // 2^20 = 1000000 백만 ...
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}