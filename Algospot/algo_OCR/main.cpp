#include <iostream>
#include <math.h>
#include <map>
using namespace std;

int m, q, n; //m: 원문에 출현할 수 있는 단어의 수, q: 처리할 문장 수
string W[501]; //단어고
double B[501]; //첫 단어에 나올 확률
double T[501][501]; // i-1번 단어다음 i번 단어가 나올 확률
double M[501][501]; //i번 단어가 적힌 조각을 j번 단어로 분류할 확률
int R[101];
double cache[102][502]; // index-1이 p일때 최댓값
int choice[102][502];
map<string, int> words;
string word;

double recognize(int index, int p) {
    if(index==n)
        return 0;
    double& ret=cache[index][p];
    if(ret!=1.0)
        return ret;
    int& choose = choice[index][p];
    ret=-1e200;
    for(int i=1; i<=m; ++i){
        double cand=T[p][i]+M[i][R[index]]+recognize(index+1, i);
        if(ret<cand){
            ret=cand;
            choose=i;
        }
    }
    return ret;
}

string reconstruct(int index, int p){
    int choose=choice[index][p];
    string ret = W[choose];
    if(index<n-1)
        ret = ret+" "+reconstruct(index+1, choose);
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>m>>q;
    for(int i=1; i<=m; ++i){
        cin>>word;
        words[word]=i;
        W[i]=word;
    }
    for(int i=1; i<=m; ++i){
        cin>>B[i];
        B[i]=log(B[i]);
    }
    for(int i=0; i<=m; ++i){
        for(int j=1; j<=m; ++j){
            if(i==0)
                T[i][j]=B[j];
            else {
                cin >> T[i][j];
                T[i][j] = log(T[i][j]);
            }
        }
    }

    for(int i=1; i<=m; ++i){
        for(int j=1; j<=m; ++j){
            cin>>M[i][j];
            M[i][j]=log(M[i][j]);
        }
    }




    for(int i=0; i<q; ++i) {

        for(int i=0; i<102; ++i){
            for(int j=0; j<502; ++j)
                cache[i][j]=1.0;
        }
        for(int i=0; i<102; ++i){
            for(int j=0; j<502; ++j)
                choice[i][j]=0;
        }
        cin >>n;
        for(int i=0; i<n; ++i){
            cin>>word;
            R[i]=words[word];
        }

        recognize(0, 0);
        cout<<reconstruct(0, 0)<<endl;
    }





    //std::cout << "Hello, World!" << std::endl;
    return 0;
}