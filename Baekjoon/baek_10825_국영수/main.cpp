#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int main() {
    int N;
    cin >> N;
    // 국어 감소, 영어 증가, 수학 감소, 이름 증가
    vector<tuple<int, int, int, string>> students(N);
    for (int i = 0; i < N; ++i) {
        int kor, eng, math;
        string name;
        cin >> name >> kor >> eng >> math;
        students[i] = {kor, eng, math, name};
    }
    sort(students.begin(), students.end(),
         [](tuple<int, int, int, string> const &t1, tuple<int, int, int, string> const &t2) {
             if (get<0>(t1) != get<0>(t2))
                 return get<0>(t1) > get<0>(t2);
             if (get<1>(t1) != get<1>(t2))
                 return get<1>(t1) < get<1>(t2);
             if (get<2>(t1) != get<2>(t2))
                 return get<2>(t1) > get<2>(t2);
             return get<3>(t1) < get<3>(t2);
    });
    for(auto &student:students) {
        cout<<get<3>(student)<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}