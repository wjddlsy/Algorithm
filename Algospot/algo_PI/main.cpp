#include <iostream>
#include <string.h>
using namespace std;

int cache[10002];

//a~b까지 점수계산하깅
int score(string &s, int a, int b){
    int flag=1;
    //1. 다 같은 경우
    for(int i=a; i<b; ++i){
        if(s[i]!=s[i+1]) {
            flag=2;
            break;
        }
    }
    if(flag==1)
        return flag;
        //2. 단조 증가 단조 감소


    for (int i = a; i < b; ++i) {
        if (s[i] - s[i + 1] != s[0]-s[1]) {
            flag = 3;
            break;
        }
    }

    if(flag==2){
        if(s[1]-s[0]==1 || s[1]-s[0]==-1)
            return 2;
        else
            return 5;
    }

    for(int i=a; i<b-1; ++i){
        if(s[i]!=s[i+2])
            flag=4;
    }

    if(flag==3)
        return 4;

    return 10;


}

int cal(string &s, int begin){
    if(begin==s.size()) return 0;
    int& ret=cache[begin];
    if(ret!=-1) return ret;

    ret=987654321;
    for(int i=3; i<=5; ++i){
        if(begin+i<=s.size())
            ret=min(ret, cal(s, begin+i)+score(s, begin, begin+i-1));
    }

    return ret;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        memset(cache, -1, sizeof(cache));
        string s;
        cin>>s;
        cout<< score(s, 0, 2);
        //cout<<cal(s, 0)<<endl;
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}