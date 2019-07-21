#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int cache[100][1000];

int n, w;
int need[100], weight[100], choices[101];
string names[100];

int packing(int index, int remain){
    if(index==n){
        return 0;
    }
    int& ret=cache[index][remain];
    if(ret!=-1)
        return ret;
    ret=packing(index+1, remain);
    if(remain>=weight[index])
        ret=max(packing(index+1, remain-weight[index])+need[index], ret);
    return ret;

}

//packing(index, remain)이 선택한 물건들의 목록을 picked에 저장
void reconstruct(int index, int remain, vector<int>& picked){
    if(index==n) return;
    if(packing(index, remain)==packing(index+1, remain))
        reconstruct(index+1, remain, picked);
    else{ //넣는 경우
        picked.push_back(index);
        reconstruct(index+1, remain-weight[index], picked);
    }
}


int main() {
    int c;
    cin>>c;
    while(c--){
        cin>>n>>w;
        for(int i=0; i<n; ++i){
            cin>>names[i]>>weight[i]>>need[i];

        }
        memset(cache, -1, sizeof(cache));
        vector<int> picked;
        reconstruct(0, w, picked);
        int sum=0;
        for(int i=0; i<picked.size(); ++i){
            sum+=need[picked[i]];
        }
        cout<<sum<<" "<<picked.size()<<endl;

        for(int i=0; i<picked.size(); ++i){
            cout<<names[picked[i]]<<endl;
        }

    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}