#include <iostream>
#include <vector>
#include <map>

using namespace std;

int solution(string s) {
    int answer = 987654321;

    for(int len=1; len<=s.size(); ++len) {
        int sum = 0;
        string prev=""; int freq=0;
        for(int i=0; i<s.size(); i+=len) {
            string cur="";
            if(i+len > s.size()) {
                sum += s.size() - i;
                //cur = s.substr(i, s.size() - i);
            }
            else {
                cur = s.substr(i, len);
                if (cur == prev) {
                    freq ++;
                    if (freq == 2) sum++;
                    if (freq == 10 || freq == 100 || freq == 1000) sum++;
                } else {
                    freq = 1;
                    sum += len;
                }
                prev = cur;
            }
        }
        answer = min(answer, sum);
    }
    return answer;
}

int main() {
    string s;
    cin >> s;

    cout<<solution(s);

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}