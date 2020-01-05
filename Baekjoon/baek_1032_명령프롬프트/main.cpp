#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<string> strings;
    for(int i=0; i<N; ++i) {
        string s;
        cin >> s;
        strings.emplace_back(s);
    }

    string ret;
    int n = strings[0].size();

    for(int i=0; i<n; ++i) {
        bool flag = true;
        for(int j=1; j<strings.size(); ++j) {
            if(strings[j][i] != strings[j-1][i]) {
                flag = false;
                break;
            }
        }
        if(flag)
            ret += strings[0][i];
        else
            ret += '?';
    }

    cout << ret;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
