#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin>>N;
    vector<pair<int, int>> points(N);

    for(auto &point:points) {
        cin>>point.second>>point.first;
    }
    sort(points.begin(), points.end());

    for(auto &point:points) {
        cout<<point.second<<" "<<point.first<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}