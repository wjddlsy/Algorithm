#include <iostream>

using namespace std;

int tree[26][2];

void preOrder(int root){
    if(root=='.'-'A')
        return;
    cout<<(char)(root+'A');
    preOrder(tree[root][0]);
    preOrder(tree[root][1]);

}

void inOrder(int root){
    if(root=='.'-'A')
        return;
    inOrder(tree[root][0]);
    cout<<(char)(root+'A');
    inOrder(tree[root][1]);
}

void postOrder(int root){
    if(root=='.'-'A')
        return;
    postOrder(tree[root][0]);
    postOrder(tree[root][1]);
    cout<<(char)(root+'A');
}
int main() {
    int N;
    char root, left, right;
    cin>>N;
    for(int i=0; i<N; ++i){
        cin>>root>>left>>right;
        tree[root-'A'][0]=left-'A';
        tree[root-'A'][1]=right-'A';
    }
    preOrder(0);
    cout<<endl;
    inOrder(0);
    cout<<endl;
    postOrder(0);
    cout<<endl;

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}