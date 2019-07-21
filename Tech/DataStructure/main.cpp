#include <iostream>
using namespace std;

/*
 * Stack
 */
template<class T> class Stack {
private:
    const int MAX_SIZE=1000;
    int _top;
    T* values;
public:
    Stack(){
        _top=-1;
        values=new T[MAX_SIZE];
    }
    ~Stack(){
        delete[] values;
    }
    void push(T value){
        if(isFull()) {
            cerr << "Stack is Full"<<endl;
            return;
        }
        value[++_top]=value;
    }
    void pop(){
        if(isEmpty()){
            cerr<<"Stack is Empty"<<endl;
            return;
        }
        _top--;
    }
    T top(){
        if(isEmpty()){
            cerr<<"Stack is Empty"<<endl;
            return NULL;
        }
        return values[_top];
    }
    bool isEmpty(){
        return _top<0;
    }
    bool isFull(){
        return _top+1==MAX_SIZE;
    }
};

/*
 * Queue
 */
template <class T> class Queue {
private:
    const int MAX_SIZE=1000;
    int _head, _tail;
    T* queue;
public:
    Queue(){
        _head=_tail=-1;
        queue=new T[MAX_SIZE];
    }
    bool isEmpty(){
        return _head==_tail;
    }
    bool isFull(){
        return _head=_tail+1 || (_head==0 && _tail=MAX_SIZE-1);
    }
    void enqueue(T x){
        if(isFull())
            return;
        queue[_tail]=x;
        if(_tail==MAX_SIZE-1)
            _tail=0;
        else
            _tail++;
    }
    T dequeue(){
        if(isEmpty())
            return NULL;
        T x=queue[_head];
        if(_head==MAX_SIZE-1)
            _head=1;
        else
            _head++;
        return x;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}