#include "iostream"
using namespace std;
#define ll long long
template <typename T> class vectors {
private :
T* arr;
ll capacity;
ll size;
public :
    vectors();
    vectors(const vectors& rhs);
    void push(T data);

    void pop();
    ll Size() const;

    T& operator[](ll);

    ll getCapacity();
    void print();
    class iterator{
        private :
            T* ptr;
        public :
            explicit iterator():ptr(nullptr){}
            explicit iterator(T* p):ptr(p){}
            bool operator == (const iterator& rhs) const{
                return ptr == rhs.ptr;
            }
            bool operator != (const iterator& rhs) const{
                return !(*this == rhs);
            }
            T operator*()const{
                return *ptr;
            }
            iterator& operator++(){
                ++ptr;
                return *this;
            }
            iterator& operator++(int){
                iterator temp(*this);
                ++*this;
                return *temp;
            }
    };
    iterator begin()const;
    iterator end()const;
};