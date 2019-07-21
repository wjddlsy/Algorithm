#include <iostream>
#include <cmath>
using namespace std;

//int tree[320001];
//
//int n;
//void insert(int h, int start, int flag){
//    if(h==n)
//        return;
//    int parent_n=pow(2, h-1);
//    int end=start-parent_n*2+1;
//    int rend=end;
//    for(int i=parent_n; i<parent_n*2; i++){
//        if(flag==1) {
//            tree[i*2] = start;
//            tree[i*2 + 1] = start - parent_n;
//            start--;
//        }
//        else {
//            tree[i*2] = end;
//            tree[i*2+1] = end+parent_n;
//            end++;
//        }
//    }
//    insert(h+1, rend-1, -flag);
//}
//
//void preOrder(int root){
//    if(tree[root]==0)
//        return;
//    cout<<tree[root]<<" ";
//    preOrder(root*2);
//    preOrder(root*2+1);
//}

//int main() {
//    cin>>n;
//    if(n==1){
//        cout<<1;
//        return 0;
//    }
//    int total=pow(2, n)-1;
//    tree[1]=total-2;
//    tree[2]=total;
//    tree[3]=total-1;
//    insert(2, total-3, -1);
//    preOrder(1);
//    //std::cout << "Hello, World!" << std::endl;
//    return 0;
//}

#define maxt (1<<15) // 노드 개수
int n, t, sol[maxt], depth[maxt]; //t=노드 개수 depth= 내 노드의 level이 얼만지

void next(int d){
    for(int i=t; i>0; --i){
        sol[t+i]=sol[i]=sol[i-1]*2; // 곱하기 2
        depth[t+i]=depth[i]=depth[i-1]+1;
    }

    for(int i=1; i<=t+t; ++i){
        if((depth[i]==d)^(i<=t)) sol[i]++; // +1
    }

    sol[0]=1;
    depth[0]=0;
    t=t+t+1;
}
int main(void){
    depth[0]=0; // tree
    sol[0]=t=1; //preorder
    cin>>n; // tree depth
    for(int i=1; i<n; ++i) next(i); //트리 만들깅
    for(int i=0; i<t; ++i) cout<<sol[i];
    return 0;
}



