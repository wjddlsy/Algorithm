#include <iostream>
#include <vector>
using namespace std;

int n, k, length[50];
double T[50][50];

class SquareMatrix{
private:
    int msize;
    vector<vector<double>> T;
public:
    SquareMatrix(int n):msize(n){
        T.resize(msize, vector<double>(msize, 0));
    }

    int size(){
        return msize;
    }
    SquareMatrix identity(int n){
        SquareMatrix ret=SquareMatrix(n);
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                if(i==j)
                    ret.T[i][j]=1;
                else
                    ret.T[i][j]=0;
            }
        }
        return ret;
    }
    SquareMatrix operator*(SquareMatrix &a){
        SquareMatrix ret=SquareMatrix(msize);
        for(int i=0; i<msize; ++i){
            for(int j=0; j<msize; ++j){
                for(int k=0; k<msize; ++k)
                    ret.T[j][k]+=T[j][i]*a.T[i][k];
            }
        }
        return ret;
    }
    SquareMatrix pow(int k){
        if(k==0)
            return identity(msize);
        if(k%2>0) return pow(k-1)**this;
        SquareMatrix half=pow(k/2);
        return half*half;

    }
    double *operator[](int i){
        return &T[i][0];
    }
};

//k분 30초 후에 각 곡이 재생되고 있을 확률을 반환
vector<double> getProbe2(){
    SquareMatrix W(4*n);
    // 첫 3*n개의 원소는 그대로 복사
    for(int i=0; i<3*n; ++i)
        W[i][i+n]=1.0;
    //마지막 n개의 원소는 이전 원소들의 선형 결합으로 이루어짐
    for(int i=0; i<n; ++i){
        //C[time+1][i]=C[time+1-length[j]][j]*T[j][i]
        for(int j=0; j<n; ++j)
            W[3*n+i][(4-length[j])*n+j]=T[j][i];
    }
    SquareMatrix Wk=W.pow(k);
    vector<double> ret(n);
    //song 번 노래가 재생되고 있을 확률 계산
    for(int song=0; song<n; ++song){
        for(int start=0; start<length[song]; ++start){
            ret[song]+=Wk[(3-start)*n+song][3*n];
        }
    }
    return ret;
}

int main() {
    int c;
    cin>>c;
    while(c--){
        int m;
        cin>>n>>k>>m;
        for(int i=0; i<n; ++i){
            cin>>length[i];
        }
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j)
                cin>>T[i][j];
        }
        vector<double> ret=getProbe2();
        for(int i=0; i<m; ++i){
            int in;
            cin>>in;
            cout.precision(8);
            cout<<ret[in]<<" ";
        }
        cout << endl;

    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}