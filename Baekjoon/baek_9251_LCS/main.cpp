#include <iostream>


using namespace std;

int cache[1001][1001];
bool chk[1001]={false,};
int main() {
    string a, b;
    cin >> a>> b;

    for(int i=1; i<=a.size(); ++i){
        for(int j=1; j<=b.size(); ++j){
            if(a[i-1]==b[j-1]) {
                cache[i][j] = cache[i - 1][j - 1] + 1;
                chk[i-1]=true;
            }
            else
                cache[i][j]=max(cache[i-1][j], cache[i][j-1]);
        }
    }

    cout<<cache[a.size()][b.size()];
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}