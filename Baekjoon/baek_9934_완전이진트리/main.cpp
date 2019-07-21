#include <iostream>
#include <vector>
using namespace std;

int trees[2000];
int K;
void buildTree(vector<int> &tree, int n, int pos, int left, int right){
    if(n==K)
        return;
    int index=(left+right)/2;
    trees[pos]=tree[index];
    buildTree(tree, n+1, pos*2, left, index-1);
    buildTree(tree, n+1, pos*2+1, index+1, right);
}
int main() {
    //int K;
    cin>>K;
    int num=(1<<K)-1;
    vector<int> tree;
    for(int i=0; i<num; ++i){
        int k;
        cin>>k;
        tree.push_back(k);
    }
    buildTree(tree, 0, 1, 0, num);
    for(int i=0; i<K; ++i){
        for(int j=(1<<i); j<(1<<i+1); ++j){
            cout<<trees[j]<<" ";
        }
        cout<<endl;
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}