#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

string e, digits; //digit: e의 자릿수를 정렬해서 저장
int n, m;
//e의 자릿수로 만들 수 있는 숫자들을 모두 출력
//price: 지금까지 만든 가격
//token: 각 자릿수의 사용 여부
void generate(string price, bool taken[15]){
    //기저사례
    if(price.size()==n){
        if(price<e)
            cout<<price<<endl;
        return;
    }
    for(int i=0; i<n; ++i){
        if(!taken[i] && (i==0 || digits[i-1]!=digits[i] || taken[i-1])){
            taken[i]=true;
            generate(price+digits[i], taken);
        }
    }
}

const int MOD=1000000007;
int cache[1<<14][20][2];
//과거 가격을 앞자리부터 채워나가고 있다.
//index: 이번에 채울 자리의 인덱스
//taken: 지금가지 사용한 자릿수들의 집합
//mod: 지금까지 만든 가격의 m에 대한 나머지
//less: 지금까지 만든 가격이 이미 e보다 작으면 1, 아니면 0
int price(int index, int taken, int mod, int less){
    if(index== n)
        return (less&&mod==0)?1:0;
    int& ret=cache[taken][mod][less];
    if(ret!=-1) return ret;
    ret=0;
    for(int next=0; next<n; ++next){
        if((taken & (1<<next))==0){
            if(!less&&e[index]<digits[next])
                continue;
            if(next>0 && digits[next-1]==digits[next] && (taken&(1<<(next-1)))==0)
                continue;
            int nextTaken=taken | (1<<next);
            int nextMod=(mod*10+digits[next]-'0')%m;
            int nextLess=less||e[index]>digits[next];
            ret+=price(index+1, nextTaken, nextMod, nextLess);
            ret%=MOD;
        }
    }
    return ret;
}

int main() {
    int c;
    cin>>c;
    while(c--){
        cin>>e>>m;
        digits="";
        n=e.size();
        memset(cache,-1, sizeof(cache));
        vector<char> tmp;
        for(int i=0; i<n; ++i)
            tmp.push_back(e[i]);
        sort(tmp.begin(), tmp.end());
        for(int i=0; i<n; ++i){
            digits+=tmp[i];
        }
        cout<<price(0, 0, 0, 0)<<endl;

    }



    //std::cout << "Hello, World!" << std::endl;
    return 0;
}