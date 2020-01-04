#include <iostream>
#include <vector>

using namespace std;

int main() {
    string document, word;
    getline(cin, document);
    getline(cin, word);

    int pos = 0, ans = 0;
    while (pos < document.size()) {
        bool flag = true;
        for (int i = 0; i < word.size(); ++i) {
            if (document[pos + i] == word[i]) { ;
            } else {
                flag = false;
                break;
            }
        }
        if (flag) {
            pos += word.size();
            ans++;
        } else {
            pos++;
        }
    }

    cout << ans;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
