#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> slice(const vector<int> &v, int s, int e) {
    return vector<int>(v.begin() + s, v.begin() + e);
}

void printPostOrder(const vector<int> &preorder, const vector<int> &inorder) {
    const int N = preorder.size();
    if (preorder.empty())
        return;
    const int root = preorder[0];
    const int L = find(inorder.begin(), inorder.end(), root) - inorder.begin();
    const int R = N - L - 1;
    printPostOrder(slice(preorder, 1, L + 1), slice(inorder, 0, L));
    printPostOrder(slice(preorder, L + 1, N), slice(inorder, L + 1, N));
    cout << root << " ";
}

int main() {
    int T;
    cin >> T;
    while(T--){
        int N, node;
        cin >> N;

        vector<int> preorder, inorder;
        for (int i = 0; i < N; ++i) {
            cin >> node;
            preorder.push_back(node);
        }
        for (int i = 0; i < N; ++i) {
            cin >> node;
            inorder.push_back(node);
        }
        printPostOrder(preorder, inorder);
        cout << endl;
    }
    return 0;
}