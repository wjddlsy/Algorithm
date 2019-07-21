#include <iostream>

using namespace std;
int main() {
    int k, n, w;
    cin >> k>>n>>w;

    int money= k*w*(w+1)/2;

    if(n>=money)
        cout<<0;
    else
        cout<<money-n;

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}