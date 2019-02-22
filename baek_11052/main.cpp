

#include <iostream>
#include <vector>
#include <math.h>

int q;
int bottom_up_cut(std::vector<int> p, int n){
    std::vector<int> r(n+1);
    r[0]=0;
    for(int j=1; j<=n; ++j){
        q=-1;
        for(int i=0; i<=j; ++i)
            q=std::max(q, p[i]+r[j-i]);
        r[j]=q;
    }
    return r[n];
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int n, input;
    std::cin >> n;
    
    std::vector<int> p(1);
    for(int i=0; i<n; ++i){
        std::cin >> input;
        p.push_back(input);
    }
    
    std::cout << bottom_up_cut(p, n) ;
    return 0;
}

