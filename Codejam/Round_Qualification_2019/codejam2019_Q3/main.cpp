#include <iostream>
#include <vector>
#include <map>
using namespace std;


int find(int s){
    for(int i=2; i<=s/2; ++i){
        if(s%i==0)
            return i;
    }
}
int main() {
    int T;
    cin>>T;
    for(int t=1; t<=T; ++t){
        int N, L;
        cin>>N>>L;
        map<int, int> m;
        vector<int> list;
        int key=1, a, b;

        // find first !!
        int s, s2;
        cin>>s>>s2;
        a=find(s); b=s/a;
        if(s2%b!=0)
            swap(a, b);
        list.push_back(a);
        list.push_back(b);
        m[a]=1; m[b]=1;
        a=s2/b;

        for(int i=2; i<L; ++i){
            cin>>s;
            b=s/a;
            list.push_back(a);
            m[a]=1;
            m[b]=1;
            if(i!=L-1)
                a=b;
        }

        list.push_back(b);

        for(auto it=m.begin(); it!=m.end(); it++){
            it->second=key;
            key++;
        }
        string ret="";
        for(int i=0; i<list.size(); ++i){
            ret.push_back((char)(m[list[i]]-1+'A'));
        }
        cout<<"Case #"<<t<<": "<<ret<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}