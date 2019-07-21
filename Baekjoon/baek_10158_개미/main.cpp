#include <iostream>
#include <vector>

using namespace std;


int main() {
    int w, h, p, q, t;
    cin>>w>>h>>p>>q>>t;

    int px=(p+t)%w;
    int py=(q+t)%h;

    bool dirX=((p+t)/w)%2;
    bool dirY=((q+t)/h)%2;

    if(dirX) {
        px=w-px;
    }
    if(dirY) {
        py=h-py;
    }

    cout<<px<<" "<<py;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}