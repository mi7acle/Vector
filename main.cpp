#include <iostream>
#include"SimpleVector.h"


int main() {
SimpleVector mam;
mam.push_back(3);
mam.push_back(3);
mam.push_back(3);
    for (int i = 0; i < mam.size(); ++i) {
        std::cout<<mam[i]<<" ";
    }
    std::cout<<std::endl;
    mam.reserve(100);
    std::cout<<"capacity-> "<<mam.capacity()<<std::endl;
    mam.clear();
    mam.push_back(135);
    mam.push_back(135);
    mam.push_back(135);
    for (int i = 0; i < mam.size(); ++i) {
        std::cout<<mam[i]<<" ";
    }
    std::cout<<std::endl;
   mam.erase(1);
    for (int i = 0; i < mam.size(); ++i) {
        std::cout<<mam[i]<<" ";
    }
}
