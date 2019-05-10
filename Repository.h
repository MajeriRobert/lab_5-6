#pragma once
#include "Cat.h"
#include "DynamicVector.h"
// #include<vector>
#include<cstring>
using namespace std;


class Repository
{
public:
    Repository();
    // ~Repository();
private:
    DynamicVector<Cat> cats;
    int current;
public:
    Cat getCurrent();
    /*
    Adds a cat in the repository
    In: a cat
    Out: -
    */
    void add(const Cat& cat);

    /*
    Removes a cat from the repository.
    In: a string "name"
    Out: 0-not removed
         1-removed
    */
    int remove(const string& name);

    /*
    Checks by name if a cat is in the repository.
    In: string name
    Out: its index if a cat with the given name is found
         -1 - if there is no cat with the given name
    */
    int findCat(const string name);


    /*
    Updates a cat's information
    In: string name
    Out:-
    */
    int update(const string& name, const Cat& cat);
    DynamicVector<Cat> getCats() const{ return this->cats; }

    void nextCat();

    bool isEmpty();

    int getPos();
};