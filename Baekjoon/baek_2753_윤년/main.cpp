#include <iostream>
#include <vector>

using namespace std;

int main() {
    int year;
    cin >> year;
    if ((year % 4 == 0 and year % 100 != 0) || year % 400 == 0)
        cout << 1;
    else
        cout << 0;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}