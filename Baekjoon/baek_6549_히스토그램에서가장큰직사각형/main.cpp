#include <iostream>
#include <vector>
long long bruteForce(const std::vector<long long>& h){
    long long ret=0;
    long long N=(long long)h.size();
    for (long long left=0; left<N; ++left){
        long long minheight=h[left];
        for (long long right=left; right<N; ++right) {
            minheight= std::min(minheight, h[right]);
            ret = std::max(ret, (right-left + 1) * minheight);
        }
    }
    return ret;

}

std::vector<long long> h;
long long solve(long long left, long long right){
    // 분할정복
    // 기저사례: 판자가 하나밖에 없는 경우.
    if (left==right) return h[left];

    long long mid = (left+right) / 2; // 문제 분할
    long long ret = std::max(solve(left, mid), solve(mid+1, right));

    //부분 문제 3
    long long lo=mid, hi=mid+1;
    long long height=std::min(h[lo], h[hi]);
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
    long long N ,input;
    while(std::cin>>N) {
        if(N==0)
            break;
        h.clear();
        for (long long i = 0; i < N; ++i) {
            std::cin >> input;
            h.push_back(input);
        }
        std::cout << solve(0, N - 1)<<'\n';
    }
    return 0;
}



