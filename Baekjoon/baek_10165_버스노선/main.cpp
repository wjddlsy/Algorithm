#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<tuple<int, int, int>> route1, route2;
    for (int i=0; i<M; ++i) {
        int a, b;
        cin >> a >> b;
        if(a < b) {
            route1.emplace_back(a, b, i);
        } else {
            route2.emplace_back(a, b + N, i);
        }
    }

    sort(route1.begin(), route1.end());
    sort(route2.begin(), route2.end(), greater<>());

    // [c, d]가 겹치지 않을 때
    int max_value = 0;
    vector<bool> flag(M, true);
    for(auto &r: route1) {
        auto [start, end, index] = r;
        if( end >= max_value ) {
            max_value = start;
        } else {
            flag[index] = false;
        }
    }

    // [c, d]가 겹칠 때
    for(auto &r: route2) {

    }

    // 포함된다는 것의 의미
    // [a, b] [c, d]

    // 1. 둘 다 안겹칠때
    // a <= c && b >= d
    // 2. 겹칠때 [a, b]가 [c,d]는 안겹칠 때
    // a >= c && b >= d
    // 3. [c, d]가 겹칠때는 존재하지 않음
    // 4. [a, b] [c, d]가 둘다 겹칠때
    // a <= c && b >= d




    std::cout << "Hello, World!" << std::endl;
    return 0;
}
