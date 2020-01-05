#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    int not_cute = 0, cute = 0;

    for(int i=0; i<N; ++i) {
        int a;
        cin >> a;
        if(a)
            cute++;
        else
            not_cute++;
    }

    if(cute > not_cute) {
        cout << "Junhee is cute!";
    } else {
        cout <<  "Junhee is not cute!";
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
