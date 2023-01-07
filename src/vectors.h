#ifndef vectors_h
#define vectors_h 1
#include "iostream"
using namespace std;
#define ll int
template <class T> 
class vectors {
private :
T* arr;
ll capacity = 1;
ll size = 0;
public :
    vectors();
    vectors(const vectors& rhs);

    void push(T data);
    void setMem(ll ukuran);
    void pop();
    void remove(int index);
    ll Size() const;

    T& operator[](ll);

    ll getCapacity();
    void print();
    
};

template <class T>
vectors<T> :: vectors():capacity(1),size(0),arr(new T[1]){}

template <class T>
void vectors<T> :: setMem(ll ukuran){
    capacity = ukuran;
}
template <class T>
void vectors<T> ::  remove(int index){
    arr[index] = arr[size-1];
    size--;
} 
template <class T>
vectors<T> :: vectors(const vectors& rhs): size(rhs.size), capacity(rhs.capacity), arr(new T[capacity]){
    for(ll i = 0; i < rhs.Size(); i++){
        arr[i] = rhs.arr[i];
    }
}
template <class T>
void vectors<T> :: push(T data){

    if(size == capacity){
        T *temp = new T[2*capacity];
        for(ll i = 0; i < capacity; i++){
            temp[i] = arr[i];
        }
        delete []arr;
        capacity *=2;
        arr = temp;
    }
    arr[size] = data;
    size++;
}
template <class T>
void vectors<T> :: pop(){
    size--;
}
template <class T>
ll vectors<T> :: Size()const{
    return size;
}
template <class T>
T& vectors<T> :: operator[](ll index){
    if(index >= size){
        cout << "Error: Vectors out of bound";
        exit(0);
    }
    return *(arr+index);
}


#endif