#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int ret=1;
    int pa=0, pb=0;
    for(int i=0; i<n; ++i){
        int a, b;
        cin>>a>>b;
        if(a>b){
            swap(a,b);
        }
        if(a<pb){
            ;
        }
        else if(a>=pb){
            if(a>pa){
                if(pa==pb)
                    ret+=(a-pb);
                else
                    ret+=(a-pb+1);
            }

//            if(a==pa && b==pb){
//                ret--;
//            }
        }
        pa=a; pb=b;
    }
    cout<<ret;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}