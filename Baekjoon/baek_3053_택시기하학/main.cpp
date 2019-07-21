#include <iostream>
#include <math.h>
using namespace std;

#define PI 3.14159265358979323846
int main() {
    cout.setf(ios::fixed);
    double n;
    cin>>n;
    cout.precision(6);
    cout << n*n*PI << endl;
    cout << n*n*2 << endl;

    return 0;
}