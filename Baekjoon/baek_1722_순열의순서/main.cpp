#include <iostream>
#include <vector>

using namespace std;

long long factorials[21];

void getFactorial() {
    factorials[0]=factorials[1]=1;
    for(int i=1; i<=20; ++i){
        factorials[i]=factorials[i-1]*i;
    }
}
int main() {
    int N, P;
    long long k;
    cin>>N>>P;
    getFactorial();
    vector<int> perm;

    vector<int> numbers;
    for(int i=1; i<=N; ++i){
        numbers.emplace_back(i);
    }

    if(P==1) {
        cin>>k; k--;
        vector<int> ret;
        for(int i=1; i<=N; ++i){
            int numerator = k / factorials[N-i];
            k = k % factorials[N-i];
            ret.emplace_back(numbers[numerator]);
            numbers.erase(numbers.begin()+numerator);
        }
        for(auto &p:ret){
            cout<<p<<" ";
        }
    } else {
        perm.resize(N);
        long long ret=1;

        for(int i=1; i<=N; ++i){
            int n; cin>>n;
            // n이 몇번째 수인지를 알아야되는데
            int rank=0;
            for(; rank<numbers.size(); ++rank){
                if(numbers[rank]==n) {
                    break;
                }
            }
            ret+=rank*factorials[N-i];
            numbers.erase(numbers.begin()+rank);
        }
        cout<<ret;

    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}