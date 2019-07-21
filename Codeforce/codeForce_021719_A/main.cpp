#include <iostream>
using namespace std;
int main() {
    int n, v;
    cin>>n>>v;
    int total=0;
    int price=1;
    int present=0;
    n--;
    while(n>0){
        int buy=min(n, v-present);
        present+=buy;
        n-=buy;
        total+=price*buy;
        present--;
        price++;
    }
    cout<<total;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}