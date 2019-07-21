#include <iostream>
#include <vector>
#include <set>

using namespace std;
int main() {
    int C;
    cin>>C;
    while(C--){
        int n;
        cin>>n;
        multiset<int> words;
        long long ret=0;
        for(int i=0; i<n; ++i){
            int word; cin>>word;
            words.insert(word);
        }

        while(words.size()>1){
            int sum=0;
            sum += *words.begin();
            words.erase(words.begin());
            sum += *words.begin();
            words.erase(words.begin());

            ret+=sum;
            words.insert(sum);
        }
        cout<<ret<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}