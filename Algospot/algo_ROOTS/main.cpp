#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<double> differentiate(const vector<double>& poly) {
    vector<double> ret;
    for(int i=1; i<poly.size(); ++i) {
        ret.emplace_back(i*poly[i]);
    }
    return ret;
}
vector<double> solveNaive(const vector<double>& poly) {
    vector<double> ret;
    if(poly.size()-1==1) {
        ret.emplace_back(-poly[0]/poly[1]);
    } else {
        double discriminant=poly[1]*poly[1]-4*poly[2]*poly[0];
        if(discriminant>0) {
            double sol1=(-poly[1]-sqrt(poly[1]*poly[1]-4*poly[2]*poly[0]))/(2*poly[2]);
            double sol2=(-poly[1]+sqrt(poly[1]*poly[1]-4*poly[2]*poly[0]))/(2*poly[2]);
            ret.emplace_back(sol1);
            ret.emplace_back(sol2);
        } else if (discriminant<0) {
            ;
        } else {
            ret.emplace_back(-poly[1]/(2*poly[2]));
        }
    }
    return ret;
}

double evaluate(const vector<double>& poly, double x0) {
    double ret=0;
    for(int i=0; i<poly.size(); ++i) {
        ret+=pow(x0, i)*poly[i];
    }
    return ret;
}

const double L=25;

vector<double> solve(const vector<double>& poly) {
    int n=poly.size()-1;
    if(n<=2) return solveNaive(poly);
    vector<double> derivative = differentiate(poly);
    vector<double> sols=solve(derivative);
    sols.insert(sols.begin(), -L-1);
    sols.insert(sols.end(), L+1);
    vector<double> ret;
    for(int i=0; i<sols.size()-1; ++i) {
        double x1=sols[i], x2=sols[i+1];
        double y1=evaluate(poly, x1), y2=evaluate(poly ,x2);
        if(y1*y2>0) continue;
        if(y1>y2) {
            swap(y1, y2);
            swap(x1, x2);
        }
        for(int j=0; j<100; ++j) {
            double mx=(x1+x2)/2;
            double my=evaluate(poly, mx);
            if(y1*my>0) {
                y1=my;
                x1=mx;
            } else {
                y2=my;
                x2=mx;
            }
        }
        ret.emplace_back((x1+x2)/2);
    }
    sort(ret.begin(), ret.end());
    return ret;
}

int main() {
    int T;
    cin>>T;
    while(T--) {
        int n;
        cin>>n;
        vector<double> poly;
        for(int i=0; i<n+1; ++i) {
            double coef;
            cin>>coef;
            poly.emplace(poly.begin(), coef);
        }
        vector<double> ret=solve(poly);
        for(auto &r:ret) {
            printf("%.9f ", r);
        }
        cout<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}