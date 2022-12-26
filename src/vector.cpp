#include "vector.h"
template <class T>
vectors<T> ::vectors(){
    arr = new T[1];
    capacity = 1;
    size = 0;
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
template <class T>
typename vectors<T>::iterator
vectors <T>::begin()const{
    return iterator(arr);
}
template <class T>
typename vectors<T>::iterator
vectors<T> :: end()const{
    return iterator(arr + size);
}

template <class T>
void print(T& v){
    typename T::iterator ptr;
    for(ptr = v.begin(); ptr!= v.end(); ptr++){
        cout << *ptr << ' ';
    }
    cout << '\n';
}
