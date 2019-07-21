#include <iostream>
#include <vector>
using namespace std;

int gcd(int p, int q){
    if(q==0) return p;
    return gcd(q, p%q);

}
int main() {
    int n, in, first;
    cin>>n;
    cin>>first;
    vector<int> rings;
    for(int i=1; i<n; ++i){
        cin>>in;
        int g = gcd( first, in);
        cout << first/g << "/" << in/g << endl;
    }



    //std::cout << "Hello, World!" << std::endl;
    return 0;
}