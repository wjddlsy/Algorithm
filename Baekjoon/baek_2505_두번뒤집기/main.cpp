#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 이 배열이 오름차순 수열인지 반환
bool isRight(vector<int> &arr) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] != i)
            return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int> origin(n);
    for (auto &a:origin) {
        cin >> a;
        a--;
    }
    vector<int> arr = origin;
    vector<pair<int, int>> ret;
    for (int i = 0; i < n; ++i) {
        auto it = find(arr.begin(), arr.end(), i);
        if (distance(arr.begin(), it) != i) {
            int first = i, last = distance(arr.begin(), it);
            if (first > last)
                swap(first, last);
            reverse(next(arr.begin(), first), next(arr.begin(), last+1));
            ret.emplace_back(first, last);
        }
        if (ret.size() == 1 || ret.size() == 2) {
            if (isRight(arr)) {
                for (auto &p:ret) {
                    cout << p.first+1 << " " << p.second+1 << '\n';
                }
                if(ret.size()==1)
                    cout << 1 << " " << 1 << '\n';
                return 0;
            }
        }
        if(ret.size()==2)
            break;
    }
    arr = origin;
    ret.clear();
    for (int i = n-1; i >=0; --i) {
        auto it = find(arr.begin(), arr.end(), i);
        if (distance(arr.begin(), it) != i) {
            int first = i, last = distance(arr.begin(), it);
            if (first > last)
                swap(first, last);
            reverse(next(arr.begin(), first), next(arr.begin(), last+1));
            ret.emplace_back(first, last);
        }
        if (ret.size() == 1 || ret.size() == 2) {
            if (isRight(arr)) {
                for (auto &p:ret) {
                    cout << p.first+1 << " " << p.second+1 << '\n';
                }
                if(ret.size()==1)
                    cout << 1 << " " << 1 << '\n';
                return 0;
            }
            if(ret.size()==2)
                break;
        }
    }

    for(int i=0; i<2; ++i) {
        cout << 1 << " " << 1 << '\n';
    }
    return 0;
}