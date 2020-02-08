#include <iostream>
#include <vector>

using namespace std;

int color[4];
int num[10];

int main() {

    int maxNum = 0;
    int pair1=0 , pair2 = 0, triple = 0, four = 0;
    bool allSame  = false, straight = false ;

    for(int i=0; i<5; ++i) {
        char c;
        int n;
        cin >> c >> n;
        if(c=='R') {
            color[0]++;
        } else if(c=='B') {
            color[1]++;
        } else if(c=='Y') {
            color[2]++;
        } else if(c=='G') {
            color[3]++;
        }
        num[n]++;
        maxNum = max(maxNum, n);
    }


    for(int i=0; i<4; ++i) {
        if(color[i] == 5) {
            allSame = true;
            break;
        }
    }

    for(int i=1; i<=9; ++i) {
        if(num[i] == 2) {
            pair1 == 0 ? pair1 = i : pair2 = i;
        } else if(num[i] == 3) {
            triple = i;
        } else if(num[i] == 4) {
            four = i;
        }
    }


    for(int i=1; i<=6; ++i) {
        if(num[i] && num[i+1] && num[i+2] && num[i+3] && num[i+4]) {
            straight = true;
        }
    }

    if(allSame && straight) {
        cout << 900 + maxNum;
    } else if(allSame) {
        cout << 600 + maxNum;
    } else if(straight) {
        cout << 500 + maxNum;
    } else if(four) {
        cout << 800 + four;
    } else if(triple && pair1) {
        cout << 700 + 10 * triple + pair1;
    } else if(triple) {
        cout << 400 + triple;
    } else if(pair1 && pair2) {
        cout << 300 + 10 * max(pair1, pair2) + min(pair1, pair2);
    } else if(pair1) {
        cout << 200 + pair1;
    } else {
        cout << 100 + maxNum;
    }

   // std::cout << "Hello, World!" << std::endl;
    return 0;
}
