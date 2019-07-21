#include <iostream>

using namespace std;

int main() {
    string A,B,C,D;
    cin>>A>>B>>C>>D;

    long long ret1=stoul(A+B);
    long long ret2=stoul(C+D);

    cout << ret1+ret2;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}