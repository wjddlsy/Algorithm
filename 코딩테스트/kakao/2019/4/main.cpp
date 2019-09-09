#include <iostream>
#include <vector>
#include <regex>

using namespace std;

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    string total;
    for(auto &query:queries) {
        int cnt = 0;
        for(auto &word:words) {
            bool flag = true;
            if(query.size()!=word.size())
                continue;
            for(int i=0; i<query.size(); ++i) {
                if(query[i]!='?' && word[i]!=query[i]) {
                    flag = false;
                    break;
                }
            }
            if(flag) cnt++;
        }
        answer.emplace_back(cnt);
    }
    return answer;
}

int main() {
    vector<string> words;
    vector<string> queries;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}