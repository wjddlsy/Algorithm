#include <iostream>
using namespace std;

int N, M, L, ans;
int n_arr[1010];

int decision(int d) {
    int st = 0;
    int cnt = 0;
    for (int i = 0; i < M + 1; i++) {
        if ((n_arr[i] - st) >= d)
        {
            cnt++;
            st = n_arr[i];
        }
    }
    return cnt;
}

void optimize(int cut) {
    int left, right;
    left = 0;	// 케이크 가장 앞
    right = L+1;	// 케이크 길이 즉, 케이크 끝 길이
    while (left + 1 < right) {
        int mid = (left + right) / 2;
        if (decision(mid) >= cut) {
            left = mid;
        }
        else
            right = mid;
    }
    cout << left << endl;
}

int main()
{
    int cut;
    cin >> N >> M >> L;
    for (int i = 0; i < M; i++)
        cin >> n_arr[i];
    n_arr[M] = L;
    for (int i = 0; i < N; i++) {
        cin >> cut;
        optimize(cut+1);
    }

    return 0;
}
