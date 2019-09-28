# swe 5658 보물상자 비밀번호

[링크][https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRUN9KfZ8DFAUo&categoryId=AWXRUN9KfZ8DFAUo&categoryType=CODE]



# Solve

## INFO

### 16 -> 10 변환

```c++
#include <stdlib.h>
for(auto p:passwords){
            if(i==K){
                cout<<"#"<<nt<<" "<< stoul(p, nullptr, 16) << endl;
                break;
            }
            ++i;
        }
}

```



## CODE

```C++
#include <iostream>
#include <vector>
#include <set>
#include <functional>
#include <stdlib.h>

using namespace std;

int N, K;

int main() {

    int t;
    cin>>t;
    for(int nt=1; nt<=t; ++nt){
        cin>>N>>K;
        string s;
        cin>>s;
        set<string,greater<string>> passwords;

        int rotate_num=N/4, idx;

        for(int start=0; start<rotate_num; ++start){
            // rotate_num만큼 가지기
            for(idx=start; idx<N-rotate_num;) {
                string tmp=s.substr(idx, rotate_num);
                passwords.insert(tmp);
                idx+=rotate_num;
            }

            string tmp=s.substr(idx)+s.substr(0, start);
            passwords.insert(tmp);
        }

        int i=1;
        for(auto p:passwords){
            if(i==K){
                cout<<"#"<<nt<<" "<< stoul(p, nullptr, 16) << endl;
                break;
            }
            ++i;
        }

    }
    return 0;
}
```

