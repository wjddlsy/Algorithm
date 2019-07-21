//
//  main.cpp
//  baek_11279
//
//  Created by 윤정인 on 2018. 6. 1..
//  Copyright © 2018년 윤정인. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


inline int PARENT(int i){
    return (i+1)/2 - 1;
}
inline int LEFT(int i){
    return (i<<1)+1;
}
inline int RIGHT(int i){
    return (i<<1)+2;
}

void swap(int &a, int &b){
    int temp=a;
    a=b;
    b=temp;
}
void min_heapify(vector<int> &a, int i){
    int l=LEFT(i);
    int r=RIGHT(i);
    int smallest;
    
    if (l<a.size() && a[l] < a[i])
        smallest=l;
    else
        smallest=i;
    
    if(r<a.size() && a[r]<a[smallest])
        smallest=r;
    
    if (smallest!=i){
        swap(a[i], a[smallest]);
        min_heapify(a, smallest);
    }
    
    return;
    
}

void build_min_heap(vector<int> &a){
    int heap_size=a.size();
    for (int i=a.size()/2-1; i>=0; i--){
        min_heapify(a, i);
    }
}

int heap_extract_min(vector<int> &a){
    if(a.size()<1)
        return 0;
    int max=a[0];
    a[0]=a[a.size()-1];
    a.pop_back();
    min_heapify(a,0);
    
    return max;
}

void heap_increase_key(vector<int> &a, int i, int key){
    if(key>a[i])
        return;
    a[i]=key;
    while(i>0 && a[PARENT(i)] > a[i]){
        swap(a[i], a[PARENT(i)]);
        i=PARENT(i);
    }
}
void max_heap_insert(vector<int> &a, int key){
    int heap_size=a.size()+1;
    a.push_back(999999999);
    heap_increase_key(a, heap_size-1, key);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int n, in;
    vector<int> min_heap;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> in;
        if(!in)
            cout << heap_extract_min(min_heap) << endl;
        else
            max_heap_insert(min_heap, in);
    }
    return 0;
}


