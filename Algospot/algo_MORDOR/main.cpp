#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

const int maxInt=numeric_limits<int>::max();
// 배열의 구간 최소 쿼리를 해결하기 위한 구간 트리의 구현
// RMQ (range minimum query)
struct RMQ {
    // 배열의 길이
    int n;
    // 각 구간의 최소치
    vector<int> rangeMin;
    RMQ(const vector<int>& array) {
        n=array.size();
        rangeMin.resize(n*4);
        init(array, 0, n-1, 1);
    }
    // node 노드가 array[left, right] 배열을 표현할 때
    // node를 루트로 하는 서브트리를 초기화하고, 이 구간의 최소치를 반환
    int init(const vector<int>& array, int left, int right, int node){
        if(left==right)
            return rangeMin[node]=array[left];
        int mid=(left+right)/2;
        int leftMin=init(array, left, mid, node*2); //오른쪽 자식
        int rightMin=init(array, mid+1, right, node*2+1); //왼쪽 자식
        return rangeMin[node]=min(leftMin, rightMin);
    }
    int query(int left, int right, int node, int nodeLeft, int nodeRight){
        // 두 구간이 겹치지 않으면 아주 큰 값 반환 = 무시
        if(right<nodeLeft || nodeRight<left) return maxInt;
        // node가 표현하는 범위가 array[left,..right]에 완전히 포함되는 경우
        if(left<=nodeLeft && nodeRight<=right)
            return rangeMin[node];
        // 양쪽 구간을 나눠서 푼 뒤 결과를 합침
        int mid=(nodeLeft+nodeRight)/2;
        return min(query(left, right, node*2, nodeLeft, mid),
                   query(left, right, node*2+1, mid+1, nodeRight));
    }

    int query(int left, int right){
        return query(left, right, 1, 0, n-1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        vector<int> minV, maxV;
        int N, Q, in, a, b;
        cin>>N>>Q;
        for(int i=0; i<N; ++i){
            cin>>in;
            minV.push_back(in);
            maxV.push_back(-in);
        }
        RMQ minH(minV);
        RMQ maxH(maxV);

        for(int i=0; i<Q; ++i){
            cin>>a>>b;
            cout<<-minH.query(a, b)-maxH.query(a, b)<<'\n';
        }

    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}