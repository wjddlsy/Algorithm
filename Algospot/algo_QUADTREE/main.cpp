#include <iostream>

using namespace std;


// string을 넘기지 않고 iterator를 넘김
//코드 미ㅕㅊㅅ다..
string reverse(string::iterator& it){
    char head = *it; // head!!
    ++it; //head 다음꺼 보기
    if(head=='b' || head=='w') //내 다음꺼가 b나 w라면 나 자신 리턴
        return string(1, head);
    string upperLeft = reverse(it); //그게 아니면 x라는 거니까 다뒤집기
    string upperRight = reverse(it);
    string lowerLeft = reverse(it);
    string lowerRight = reverse(it);
    // 각각 위와 아래 조각들의 위치를 바꾼다.
    return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}

int main() {
    int C;
    cin>>C;
    while(C--){
        string s;
        cin>>s;
        auto it=s.begin();
        cout<<reverse(it)<<endl;
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}