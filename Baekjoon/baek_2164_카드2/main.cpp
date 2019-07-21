#include <iostream>
#include <deque>
using namespace std;

int main() {
    int N;
    cin>>N;
    deque<int> cards;
    for(int i=1; i<=N; ++i){
        cards.emplace_back(i);
    }
    while(cards.size()>1){
        cards.pop_front();
        int card=cards.front();
        cards.pop_front();
        cards.emplace_back(card);
    }
    cout<<cards.front();
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}