#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>

using namespace std;


map<string, int> itemToId;
map<int, bool> notExistBoat, notExistGround;
int boatSize = 0, driver = 0, total = 0;

void init() {
    int N;
    cin >> N;
    total = N;
    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        itemToId[s] = i;
    }

    cin >> N;

    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        int Id = itemToId[s];
        driver |= (1 << Id);
    }

    cin >> N;

    for (int i = 0; i < N; ++i) {
        int M;
        cin >> M;
        int comb = 0;
        for (int i = 0; i < M; ++i) {
            string s;
            cin >> s;
            int Id = itemToId[s];
            comb |= (1 << Id);
        }
        notExistGround[comb] = true;
    }

    cin >> N;

    for (int i = 0; i < N; ++i) {
        int M;
        cin >> M;
        int comb = 0;
        for (int i = 0; i < M; ++i) {
            string s;
            cin >> s;
            int Id = itemToId[s];
            comb |= (1 << Id);
        }
        notExistBoat[comb] = true;
    }

}

int bfs() {
    int start = (1 << total) - 1, finish = 0;
    queue<int> q;
    map<int, int> discovered;
    q.push(start);
    discovered[start] = 1;
    int turn = 0;
    if(notExistGround[start])
        return -1;
    while (!q.empty()) {
        int here = q.front();
        q.pop();
        int dist = discovered[here];
        int prevHere = here;
        turn = (((1 << total) & here) > 0);
        here &= ~(1 << total);
        if (turn && here == start) {
            return dist - 1;
        }
        for (int boat = here; boat; boat = (boat - 1) & here) {
            if (__builtin_popcount(boat) > boatSize)
                continue;
            if ((boat & driver) && !notExistBoat[boat]) {
                int left = (here & ~boat);
                if (notExistGround[left])
                    continue;
                int there = ((1 << total) - 1) & ~left;
                if(notExistGround[there])
                    continue;
                if (!turn)
                    there |= (1 << total);
                if (discovered[there] == 0) {
                    discovered[there] = discovered[prevHere] + 1;
                    q.push(there);
                }
            }
        }
    }
    return -1;

}

int main(int argc, char *argv[]) {

    cin >> boatSize;
    init();

    cout << bfs();


    return 0;
}