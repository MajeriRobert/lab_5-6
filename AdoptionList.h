#pragma once
#include"Cat.h"
#include"DynamicVector.h"

class AdoptionList
{
private:
    DynamicVector<Cat> cats;
    int current;
public:
    AdoptionList();
    ~AdoptionList();

    void add(const Cat& c);

    Cat getCurrentCat();

    void next();

    bool isEmpty();

};