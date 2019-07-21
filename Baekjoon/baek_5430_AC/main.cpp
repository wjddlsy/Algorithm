#include <iostream>
#include <deque>

using namespace std;
int main(){
    int t, n;
    string p,s;
    cin>>t;
    while(t--){
        bool dir=true, error=false;
        cin>>p>>n>>s;
        int pos=0;
        string tmp="";
        deque<int> dq;
        if(n!=0){
            while(true){
                if(s[pos]=='['){
                    pos++;
                }
                else if(s[pos]==','|| s[pos]==']'){
                    dq.push_back(stoi(tmp));
                    if(s[pos]==']')
                        break;

                    pos++;
                    tmp="";
                }
                tmp+=s[pos];
                pos++;
            }
        }

        int nn=p.size();
        for(int i=0; i<nn;++i){
            if(p[i]=='R')
                dir=!dir;
            else {
                if(n==0){
                    error=true;
                }
                else if(dir){
                    n--;
                    dq.pop_front();
                }
                else{
                    n--;
                    dq.pop_back();
                }
            }
        }

        if(error)
            cout<< "error" << endl;
        else {
            if(n==0)
                cout<<"[]"<<endl;
            else{
                int size = dq.size();
                cout << "[";
                for (int i = 0; i < size; ++i) {
                    if (dir) {
                        cout << dq.front();
                        dq.pop_front();

                    }
                    else {
                        cout << dq.back();
                        dq.pop_back(); }
                    if (!dq.empty()) cout << ","; }
                cout << "]" << endl;

            }

        }
    }
}
