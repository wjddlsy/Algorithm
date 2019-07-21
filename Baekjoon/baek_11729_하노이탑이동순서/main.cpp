#include <iostream>
#include <cmath>
using namespace std;


void hanoi(int n, int from, int to) {
    if(n==0)
        return;
    hanoi(n-1, from, 6-from-to);
    cout<<from<<" "<<to<<'\n';
    hanoi(n-1, 6-from-to, to);
}
int main() {
    int N;
    cin>>N;
    cout<<(1<<N)-1<<'\n';
    hanoi(N, 1, 3);
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}