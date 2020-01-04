#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        vector<int> scores;
        for (int i = 0; i < 5; ++i) {
            int score;
            cin >> score;
            scores.emplace_back(score);
        }

        sort(scores.begin(), scores.end());
        if (scores[3] - scores[1] >= 4)
            cout << "KIN" << '\n';
        else
            cout << accumulate(scores.begin() + 1, scores.end() - 1, 0) << '\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}