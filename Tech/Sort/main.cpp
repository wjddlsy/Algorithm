#include <iostream>
#include <vector>

using namespace std;


inline unsigned int parent(unsigned int i) {
    return (i-1)>>1;
}
inline unsigned int left(unsigned int i){
    return (i<<1)+1;
}
inline unsigned int right(unsigned int i){
    return (i<<1)+2;
}

/*
 * 힙소트
 * 여러 함수들이 있다.
 * unstable sort
 */
struct HeapSort{
    void static maxHeapify(vector<int>& arr, int i, int heapSize){
        int l=left(i);
        int r=right(i);
        int largest=i;
        if(l<heapSize && arr[l]>arr[largest])
            largest=l;
        if(r<heapSize && arr[r]>arr[largest])
            largest=r;
        if(largest!=i){
            swap(arr[i], arr[largest]);
            maxHeapify(arr, largest, heapSize);
        }
    }

    void static buildMaxHeap(vector<int>& arr){
        int n=arr.size();
        for(int i=parent(n); i>=0; --i){
            maxHeapify(arr, i, n);
        }
    }

public:
    void static heapSort(vector<int>& arr){
        buildMaxHeap(arr);
        int n=arr.size();
        for(int i=n-1; i>0; --i){
            swap(arr[0], arr[i]);
            n--;
            maxHeapify(arr, 0, n);
        }

    }
};

/*
 * 최대우선순위큐
 */
struct PriorityQueue{
    int heapSize=0;
    const int INF=987654321;
    vector<int> arr;
    HeapSort hp;
    int extractMax(){
        if(heapSize==0)
            cerr<<"heap underflow";
        int max=arr[0];
        arr[0]=arr[heapSize-1];
        heapSize--;
        arr.pop_back();
        hp.maxHeapify(arr, 0, heapSize);
        return max;
    }
    void increaseKey(int i, int key){
        if(key<arr[i])
            cerr<<"The new key is smaller than this key";
        arr[i]=key;
        while(i>0 && arr[parent(i)]<arr[i]){
            swap(arr[i], arr[parent(i)]);
            i=parent(i);
        }
    }
    void maxHeapInsert(int key){
        heapSize++;
        arr.push_back(-INF);
        increaseKey(heapSize-1, key);
    }
};

/*
 * 버블 소트
 * 내 뒤에 원소와 비교해서 크면 자리를 바꾼다
 * 바뀌는 원소가 없을 때까지 지속
 * 시간복잡도: O(N^2)
 * stable sort
 */
void bubbleSort(vector<int>& arr){
    bool flag=true;
    while(flag){
        flag=false;
        for(int i=0; i<arr.size()-1; ++i){
            if(arr[i]>arr[i+1]) {
                swap(arr[i], arr[i + 1]);
                flag=true;
            }
        }
    }
}

/*
 * 삽입 정렬
 * 내 원소를 카드정렬하듯 넣는거임
 * 내 원소가 앞으로 갈 때 뒤의 원소들을 한 칸씩 뒤로 미는 작업을 해줘야한다
 * 시간복잡도: O(N^2)
 * stable sort
 */
void insertionSort(vector<int>& arr){
    for(int i=1; i<arr.size(); ++i){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

/*
 * 선택 정렬
 * 최솟값 찾아서 정렬하기
 * key! 내 위치의 값과 비교한 뒤 스왑해주자
 * unstable sort
 */
void selectionSort(vector<int>& arr){
    const int INF=987654321;
    for(int i=0; i<arr.size(); ++i){
        int index=i;
        for(int j=i+1; j<arr.size(); ++j){
            if(arr[index]>arr[j]){
                index=j;
            }
        }
        swap(arr[i], arr[index]);
    }
}


int partition(vector<int>& arr, int p, int r){
    // pivot value = x
    int x=arr[r];
    int index=p-1;
    for(int i=p; i<=r-1; ++i){
        if(arr[i]<=x){
            index=index+1;
            swap(arr[index], arr[i]);
        }
    }
    swap(arr[index+1], arr[r]);
    return index+1;
}
/*
 * 퀵소트
 * 분할정복에 기반
 * p~r 배열을 정렬한다고 볼 수 있음
 * 최악의 경우
 * O(n^2)인데 이 때는 거의 다 정렬되어 있는 상태 -> 삽입정렬의 경우 O(n) 가능
 * 최고의 경우
 * 분할을 반씩 하는 경우 O(nlogn)
 *
 * unstable sort
 */
void quickSort(vector<int>& arr, int p, int r){
    if(p<r){
        int q=partition(arr, p, r);
        quickSort(arr, p, q-1);
        quickSort(arr, q+1, r);
    }
}
void print(vector<int>& arr){
    for(auto a:arr){
        cout<<a<<" ";
    }
}

/*
 * 병합 정렬
 * stable sort
 * 분할정복에 기반하고 있다
 */
void merge(vector<int>& arr, int p, int q, int r){
    const int INF=987654321;
    int n1=q-p+1;
    int n2=r-q;
    vector<int> L, R;
    for(int i=0; i<n1; ++i){
        L.push_back(arr[p+i]);
    }
    for(int i=0; i<n2; ++i){
        R.push_back(arr[q+i+1]);
    }
    L.push_back(INF);
    R.push_back(INF);

    int i=0, j=0;
    for(int k=p; k<=r; ++k){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }
        else {
            arr[k]=R[j];
            j++;
        }
    }

}
void mergeSort(vector<int>& arr, int p, int r){
    if(p<r){
        int q=(p+r)/2;
        mergeSort(arr, p, q);
        mergeSort(arr, q+1, r);
        merge(arr, p, q, r);
    }
}

int main() {
    vector<int> test={5, 4, 3, 2, 1, 7, 9};
    //bubbleSort(test);
    //insertionSort(test);
    //selectionSort(test);
    //HeapSort hp;
    //hp.heapSort(test);
    //mergeSort(test, 0, test.size()-1);
    quickSort(test, 0, test.size()-1);
    print(test);
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}