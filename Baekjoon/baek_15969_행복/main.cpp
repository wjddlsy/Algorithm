#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, in;
    vector<int> student;
    cin>>N;
    for(int i=0; i<N; ++i){
        cin>>in;
        student.push_back(in);
    }
    sort(student.begin(), student.end());
    cout<<student[student.size()-1]-student[0];
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}