#include <iostream>
#include <vector>

using namespace std;

int cache[4001];
int arr[4001];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin>>N;
    for(int i=0; i<N; ++i) {
        int n; cin>>n;
        arr[i*2] = n;
    }
    cin>>M;
    for(int i=0; i<2*N; ++i) {
        int mid = i, left = i-1, right = i+1;
        while(left>=0 && right<2*N) {
            if(arr[left]!=arr[right]) {
                break;
            }
            cache[mid]++;
            left--; right++;
        }
    }

    for(int i=0; i<M; ++i) {
        int S, E;
        cin>>S>>E;
        S--; E--;
        S*=2; E*=2;
        if(cache[(S+E)/2] >= (E - S) / 2 )
            cout<<1<<'\n';
        else
            cout<<0<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}