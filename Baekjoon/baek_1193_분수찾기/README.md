# 1193 



# Solve

## Think

## Code

```c++
#include <iostream>
#include <vector>

using namespace std;
int main() {
    int x, i, r;
    cin >> x;
    for(i=1; i<10000; ++i){
        if(x<=i*(i+1)/2) {
            r=i*(i+1)/2-x;
            break;
        }
    }
    int a, b;

    if(i%2==0) {
        a=i-r;
        b=1+r;
    }// 짝수3
    else{
        a=1+r;
        b=i-r;
    }
    cout << a << "/"<< b;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
```

