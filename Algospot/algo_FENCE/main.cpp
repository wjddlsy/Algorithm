#include <iostream>
#include <vector>
int bruteForce(const std::vector<int>& h){
    int ret=0;
    int N=(int)h.size();
    for (int left=0; left<N; ++left){
        int minheight=h[left];
        for (int right=left; right<N; ++right) {
            minheight= std::min(minheight, h[right]);
            ret = std::max(ret, (right-left + 1) * minheight);
        }
    }
    return ret;

}

std::vector<int> h;
int solve(int left, int right){
    // 분할정복
    // 기저사례: 판자가 하나밖에 없는 경우.
    if (left==right) return h[left];

    int mid = (left+right) / 2; // 문제 분할
    int ret = std::max(solve(left, mid), solve(mid+1, right));

    //부분 문제 3
    int lo=mid, hi=mid+1;
    int height=std::min(h[lo], h[hi]);
    //[mid, mid+1] 만 포함하는 너비 2인 사각형 고려.
    ret=std::max(ret, height * 2);

    while(left<lo || hi <right) {
        //항상 높이가 더 높은 쪽으로 확장
        if (hi<right && (lo==left || h[lo-1]<h[hi+1])){
            ++hi;
            height=std::min(height, h[hi]);
        }
        else {
            --lo;
            height = std::min (height, h[lo]);
        }

        ret = std::max(ret, height*(hi-lo+1));
    }
    return ret;
}

int main(int argc, const char * argv[]) {
    int C, N ,input;
    std::cin>>C;
    while(C--) {
        h.clear();
        std::cin >> N;
        for (int i = 0; i < N; ++i) {
            std::cin >> input;
            h.push_back(input);
        }
        std::cout << solve(0, N - 1) <<std::endl;
    }
    return 0;
}