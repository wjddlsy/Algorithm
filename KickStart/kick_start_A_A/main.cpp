#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
    int T;
    cin>>T;
    for(int t=1; t<=T; ++t){
        int N, P;
        cin>>N>>P;
        vector<int> scores;
        //memset(scores, 0, sizeof(scores));
        for(int i=0; i<N; ++i){
            int s;
            cin>>s;
            scores.push_back(s);
        }
        sort(scores.begin(), scores.end());

        int ret=987654321;

        int partSum[100000]={0,};

        partSum[0]=scores[0];

        for(int i=1; i<scores.size(); ++i){
            partSum[i]=partSum[i-1]+scores[i];
        }


        for(int i=0; i<=N-P; ++i){
            int sum;
            if(i==0)
                sum=partSum[i+P-1];
            else
                sum=partSum[i+P-1]-partSum[i-1];
            int scoreSum=scores[i+P-1]*P;
            ret=min(ret, scoreSum-sum);
        }


//        for(int i=0; i<=N-P; ++i){
//            int maxScore=scores[i+P-1];
//            int sum=0;
//            for(int j=0; j<P; ++j){
//                sum+=maxScore-scores[i+j];
//            }
//            ret=min(ret, sum);
//        }

        cout<<"Case #"<<t<<": "<<ret<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}