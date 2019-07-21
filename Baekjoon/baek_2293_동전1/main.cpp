#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int values[101];
int cache[10001];
int main() {
    int n, k;
    cin>>n>>k;
    for(int i=1; i<=n; ++i){
        cin>>values[i];
    }

    cache[0]=1;

    for(int i=1; i<=n; ++i){
        for(int j=1; j<=k; ++j){
            if(j>=values[i])
                cache[j]+=cache[j-values[i]];
        }
    }


    cout<<cache[k];

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}