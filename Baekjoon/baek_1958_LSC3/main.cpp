#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int cache[101][101][101];
string a, b, c;
int main() {
    cin>>a>>b>>c;
    for(int i=1; i<=a.size(); ++i){
        for(int j=1; j<=b.size(); ++j){
            for(int k=1; k<=c.size(); ++k){
                if(a[i-1]==b[j-1]&&b[j-1]==c[k-1])
                    cache[i][j][k]=cache[i-1][j-1][k-1]+1;
                else
                    cache[i][j][k]=max({cache[i-1][j][k], cache[i][j-1][k], cache[i][j][k-1]});
            }
        }
    }
    cout<<cache[a.size()][b.size()][c.size()];
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}