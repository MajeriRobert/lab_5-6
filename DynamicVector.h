#pragma once
#include"Cat.h"
#include<string>

template <typename T>
class DynamicVector{
private:
    T* elems;
    int size;
    int capacity;
public:
    DynamicVector(int capacity = 10);

    DynamicVector(const DynamicVector& v);

    ~DynamicVector();

    DynamicVector& operator=(const DynamicVector& v);

    T& operator[](int pos);

    void add(const T& e);
    void remove(int pos);
    // void update(T oldT, T newT);

    int getSize() const ;
    int getCapacity() const;
    T* getElems() const;
private:
    void reSize(double factor = 2);
};

template <typename T>
DynamicVector<T>::DynamicVector(int capacity ){
    this->size = 0;
    this->capacity = capacity;
    this->elems = new T[capacity];
}


template <typename T>
DynamicVector<T>::DynamicVector(const DynamicVector<T>& v){

    this->size = v.size;
    this->capacity = v.capacity;
    this->elems = new T[v.capacity];
    for(int i = 0; i< v.capacity; i++){
        this->elems[i] = v.elems[i];
    }

}

template <typename T>
DynamicVector<T>::~DynamicVector(){
    delete[] this->elems;
}

template <typename T>
DynamicVector<T>& DynamicVector<T>::operator=(const DynamicVector<T>& v){

    if(this == &v)
        return *this;

    this->size = v.size;
    this->capacity = v.capacity;

    delete[] this->elems;
    this->elems = new T[v.capacity];
    for(int i = 0; i < v.capacity; i++){
        this->elems[i] = v.elems[i];
    }
    return *this;
}

template <typename T>
DynamicVector<T>& operator+(DynamicVector<T>& v, const T& e){
    v.add(e);
    return v;
}

template <typename T>
DynamicVector<T>& operator+(const T& e, DynamicVector<T>& v){
    v.add(e);
    return v;
}


template <typename T>
T& DynamicVector<T>::operator[](int pos){
    return this->elems[pos];
}


template <typename T>
void DynamicVector<T>::add(const T& e){
    if(this->size == this->capacity)
        reSize();
    this->elems[this->size++] = e;
}

template <typename T>
void DynamicVector<T>::remove(int pos){
   while(pos < this->size){
       this->elems[pos] = this->elems[pos + 1];
       pos++;
   }
  this->size--;
}


template <typename T>
void DynamicVector<T>::reSize(double factor){
    this->capacity *= static_cast<int>(factor);
    T* els = new T[this->capacity];
    for(int i = 0; i < this->size; i++)
        els[i] = this->elems[i];
    delete[] this->elems;
    this->elems = els;
}


template <typename T>
int DynamicVector<T>::getSize() const {
    return this->size;
}

template <typename T>
int DynamicVector<T>::getCapacity() const{
    return this->capacity;
}


template <typename T>
T* DynamicVector<T>::getElems() const {
    return this->elems;
}


