#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--){
        int A, B;
        cin>>A>>B;
        int N;
        cin>>N;
        while(N>0){
            string s;
            int mid=(A+B+1)/2;
            cout<<mid<<endl;
            cin>>s;
            if(s=="CORRECT")
                break;
            else if(s=="TOO_SMALL"){
                A=mid;
            }
            else if(s=="TOO_BIG"){
                B=mid-1;
            }
            else if(s=="WRONG_ANSWER"){
                break;
            }
            N--;
        }
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}