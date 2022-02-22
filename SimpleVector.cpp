//
// Created by Olena Yarmoshenko on 22.02.22.
//

#include "SimpleVector.h"

SimpleVector::SimpleVector() {
arr=new int[1];

_capasity=1;  //capasity
_size=0;   //size

}

SimpleVector::SimpleVector(int num, int value) {
arr = new int [num];
    for (int i = 0; i < num; ++i) {
        arr[i]=value;    //copy values
    }
    _size=num;  //Created new size
    reserve(num*2);  //reserve _capasity
}

void SimpleVector::push_back(int value) {
    if (_size > 0 && _size == _capasity)  //if size equal capacity
        reserve(_size * 2);   //reserve capacity (size*2)
    arr[_size++]=value;

}

void SimpleVector::reserve(int n_capasity) //reserve capacity
{

if(n_capasity<=_capasity) return;  //if reserve smallest real size


       int *tmp= reinterpret_cast<int*>(new int8_t[n_capasity*sizeof(int)]); //Created temporary array

    try  //try exception
    {
        std::uninitialized_copy(arr, arr+ _size,tmp); //copy for diapazone values with start vector to end

    }
    catch(...)
    {
        delete[]reinterpret_cast<int8_t*>(arr); //if have exception - delete vector memory
        throw; //continue
    }
    delete[]reinterpret_cast<int8_t*>(arr);
    arr=tmp;
    _capasity=n_capasity;
}

int &SimpleVector::operator[](int index) //overload operator brackets
{
    return arr[index];  //return element
}

const int &SimpleVector::operator[](int index) const ////overload const operator brackets
{
    return arr[index];  //return element
}

int SimpleVector::size() //get size of simple vector
{
    return _size;
}

int SimpleVector::capacity()  //get capasity for simple vector
{
    return _capasity;
}

bool SimpleVector::isEmpty()  //if vector is empty
{
    return _size==0;
}

void SimpleVector::clear() {
delete []arr; //clear array
_size=0;  //size equal zero
}

int SimpleVector::begin() {
    return arr[0];    //return begin array
}

int SimpleVector::end() {
    return arr[_size-1];  //return end of array
}

int SimpleVector::pop_back() //delete last elelment
{
    int pop=arr[_size-1];
    arr[_size--];
    return pop;
}
/*  don't work
void SimpleVector::erase(int index) {
    if(index>=_size||_size==0)return;
    int *tmp=new int [_size-1];
    for (int i = 0; i < index; ++i) {
        tmp[i]=arr[i];
    }
    for (int i = index,j=index+1; i <_size-1 ; ++i) {
        tmp[i]=arr[j++];
    }
    delete[]arr;
    arr=tmp;
    --_size;
}
*/