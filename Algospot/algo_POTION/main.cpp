#include <iostream>
#include <vector>
#include "cmath"
#include <algorithm>
using namespace std;


int gcd(int p, int q){
    if(q==0) return p;
    return gcd(q, p%q);
}

int ceil(int a, int b){
    return (a+b-1)/b;
}

vector<int> solve(const vector<int>& recipe, vector<int> put){
    int n=recipe.size();
    int b=recipe[0];
    for(int i=1; i<n; ++i){
        b=gcd(b,recipe[i]); // 최대 공약수 구하기
    }


    int a=b;
    for(int i=0; i<n; ++i){
        a=std::max(a, ceil(put[i]*b, recipe[i]));

    }

    vector<int> ret;
    for(int i=0; i<n; ++i){
        ret.push_back(recipe[i]*a/b - put[i]);
    }

    return ret;

}
int main() {
    int C, n, in;
    vector<int> r, p;
    cin >> C;
    while(C--){
        cin >> n;
        for(int i=0; i<n; ++i){
            cin >> in;
            r.push_back(in);
        }
        for(int i=0; i<n; ++i){
            cin >> in;
            p.push_back(in);
        }

        vector<int> ret=solve(r, p);
        for(auto r:ret){
            cout << r << " ";
        }
        r.clear();
        p.clear();
        cout<< endl;
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}