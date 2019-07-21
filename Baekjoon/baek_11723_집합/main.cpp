#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int M;
    cin>>M;
    int status=0;
    for(int i=0; i<M; ++i){
        string command;
        int x=0;
        cin>>command;
        if(command=="add"){
            cin>>x; x--;
            status |=(1<<x);
        }
        else if(command=="remove"){
            cin>>x; x--;
            status &= ~(1<<x);
        }
        else if(command=="check"){
            cin>>x; x--;
            cout<<((status & (1<<x))?1:0)<<'\n';
        }
        else if(command=="toggle"){
            cin>>x; x--;
            status ^= (1<<x);
        }
        else if(command=="all"){
            status=1;
            status=(status<<20)-1;
        }
        else if(command=="empty"){
            status=0;
        }

    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}