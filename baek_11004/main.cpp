//
//  main.cpp
//  baek_11004
//
//  Created by 윤정인 on 2018. 6. 5..
//  Copyright © 2018년 윤정인. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <time.h>
#include <set>
#include <random>

using namespace std;

int rand(int p, int r ){
    random_device rd;
    mt19937 end(rd());
    uniform_int_distribution<> distr(p, r);
    return distr(end);
}

void swap(int &a, int &b){
    int temp=a;
    a=b;
    b=temp;
}

int partition(int A[], int p, int r){
    int x=A[r];
    int i=p-1;
    for (int j=p; j<r; j++){
        if (A[j] <= x){
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i+1], A[r]);
    return i+1;
}

int randomized_partition(int A[], int p, int r){
    srand(time(NULL));
    int i=rand(p, r);
    swap(A[r], A[i]);
    return partition(A, p, r);
}

int randomized_select(int A[], int p, int r, int i){
    if (p==r)
        return A[p];
    int q=partition(A, p, r);
    int k= q-p+1;
    if (i==k)
        return A[q];
    else if (i<k)
        return randomized_select(A,p, q-1, i);
    else
        return randomized_select(A, q+1, r, i-k);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int N, K;
    int * in = new int[N];
    std::ios_base::sync_with_stdio(false);
    cin >> N >> K;
    
    for(int i=0; i<N; ++i){
        cin >> in[i];
    }
    
    cout << randomized_select(in, 0, N-1, K);
    return 0;
}
