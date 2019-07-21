#include <iostream>

using namespace std;


int main() {
    int numbers[10]={0,};
    string s;
    cin >> s;
    auto it=s.begin();
    while(it!=s.end()){
        if(*it=='9')
            numbers[6]++;
        else
            numbers[*it-'0']++;
        ++it;
    }
    numbers[6]=numbers[6]/2 + numbers[6]%2;

    int ret=0;
    for(int i=0; i<10; ++i){
        ret=std::max(ret,numbers[i]);
    }
    cout << ret;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}