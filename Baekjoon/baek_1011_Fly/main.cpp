#include <iostream>
#include <math.h>
using namespace std;

#define MAX 99
int cache[MAX][2]={{0,}};

int main() {
    double T, x, y, s;
    cin>>T;
    while(T--){
        cin>>x>>y;
        int dist=y-x;
        if(dist==2)
            cout<<2;
        else {
            double d = sqrt(dist);
            if (dist == (int) d * (int) d) {
                cout << (int) (d + d - 1);
            } else {
                int dd = (int) d + 1;
                if (dd * dd - dist >= dd)
                    cout << dd + dd - 1 - 1;
                else
                    cout << dd + dd - 1;
            }
        }
        cout << endl;
    }
    return 0;
}