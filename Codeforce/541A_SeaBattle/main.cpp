#include <iostream>
using namespace std;
int main() {
    int w1, w2, h1, h2;
    cin>>w1>>h1>>w2>>h2;
    int total=(w1+2)*(h1+h2+2);
    int current=(w1*h1)+(w2*h2);
    int sub=(w1-w2)*(h2);
    cout<<total-current-sub;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}