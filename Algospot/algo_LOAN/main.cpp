#include <iostream>

using namespace std;

double balance(double amount, int duration, double rates, double monthlyPayment) {
    double balance=amount;
    for(int i=0; i<duration; ++i) {
        balance *= (1.0 + (rates/12.0)/100.0);
        balance-=monthlyPayment;
    }
    return balance;
}

double payment(double amount, int duration, double rates) {
    double lo=0, hi=amount*(1.0 + (rates/12.0)/100.0);
    for(int i=0; i<100; ++i) {
        double mid=(lo+hi)/2;
        if(balance(amount, duration, rates, mid)<=0) {
            hi=mid;
        } else {
            lo=mid;
        }
    }
    return hi;
}
int main() {
    int T;
    cin>>T;
    while(T--) {
        double N, P;
        int M;
        cin>>N>>M>>P;
        printf("%.8f\n", payment(N, M, P));
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}