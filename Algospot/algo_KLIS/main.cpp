#include <iostream>
#include <algorithm>
#include <climits>
#include <string.h>
#include <vector>
using namespace std;

int S[501], cacheLen[501], cacheCnt[501];
int n, k;
const long long MAX=2000000000+1;

//S[start]에서 시작하는 증가 부분 수열 중 최대 길이 반환
int lis(int start){
    int& ret=cacheLen[start+1];
    if(ret!=-1) return ret;
    ret=1;
    for(int next=start+1; next<n; ++next){
        if(start==-1 || S[start]<S[next])
            ret=max(ret, lis(next)+1);
    }
    return ret;
}

//S[start]에서 시작하는 최대 증가 부분 수열의 수 반환
int count(int start){
    if(lis(start)==1) return 1;
    int& ret=cacheCnt[start+1];
    if(ret!=-1) return ret;
    ret=0;
    for(int next=start+1; next<n; ++next){
        if((start==-1) || (S[start]<S[next] && lis(start)==lis(next)+1))
            ret=min(MAX, (long long)ret+count(next)); // 오버플로우...

    }
    return ret;
}

void reconstruct(int start, int skip, vector<int>& lisl){
    //1. S[start]는 항상 LIS에 포함된다.
    if(start!=-1) lisl.push_back(S[start]);
    //2. 뒤에 올 수 있는 숫자들과 위치의 목록을 만든다.
    //(숫자, 숫자의 위치)의 목록이 된다.
    vector<pair<int, int>> followers;
    for(int next=start+1; next<n; ++next){
        if((start==-1 || S[start]<S[next]) && lis(start)==lis(next)+1){
            followers.push_back({S[next], next});
        }
    }
    sort(followers.begin(), followers.end());
    for(int i=0; i<followers.size(); ++i){
        int idx=followers[i].second;
        int cnt=count(idx);
        if(cnt<=skip)
            skip-=cnt;
        else{
            reconstruct(idx, skip, lisl);
            break;
        }
    }
}

int main() {
    int c;
    cin>>c;
    while(c--){
        //int n, k;
        cin>>n>>k;
        memset(cacheLen, -1, sizeof(cacheLen));
        memset(cacheCnt, -1, sizeof(cacheCnt));
        for(int i=0; i<n; ++i){
            cin>>S[i];
        }
        vector<int> lisl;
        reconstruct(-1, k-1, lisl);
        cout<<lisl.size()<<endl;
        for(auto l:lisl)
            cout<<l<<" ";
        cout<<endl;

    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}