#include <iostream>

using namespace std;

int main() {
    int in, out, p_max=0, p=0;
    for(int i=0; i<4; ++i){
        cin >> out>> in;
        p_max=max(p, p_max);
        p-=out;
        p+=in;
    }
    cout << p_max;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}