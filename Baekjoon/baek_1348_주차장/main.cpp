#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int R, C;
string board[50];
vector<int> adj[100];
int aMatch[100], bMatch[100];
bool visited[100];

void bfs(){

}
int main() {
    cin>>R>>C;
    for(int i=0; i<R; ++i){
        cin>>board[i];
    }
    int a=123;
    cout<<__builtin_popcount(a);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}