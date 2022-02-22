
#pragma once
#include<iostream>
#include<memory>

class SimpleVector {
private:
    int *arr;  //array
    int _capasity;  // capasity
    int _size;     //size
public:
    SimpleVector();
    SimpleVector(int num,int value);
    void push_back(int value);
    int size();
    int capacity();
    bool isEmpty();
    void erase(int index);
    void clear();
    void reserve(int n_capacity);
    int&operator[](int index);
    const int&operator[](int index)const ;
    int pop_back();
    int begin();
    int end();
};



