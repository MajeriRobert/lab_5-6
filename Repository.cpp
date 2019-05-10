#include "Repository.h"
#include <cstring>


Repository::Repository(){
    this->current = 0;

}
void Repository::add(const Cat& cat){
    this->cats.add(cat);
}

int Repository::remove(const string& name){
    if(findCat(name) == -1)
        return 0;
    this->cats.remove(findCat(name));
    return 1;
}

int Repository::findCat(const string name){
    for(int i = 0; i < this->cats.getSize(); i++){
        if(this->cats[i].getName().compare(name) == 0)
            return i;
    }
    return -1;
}

int Repository::update(const string& name, const Cat& cat){
    if(findCat(name) == -1)
        return 0;
    this->cats[findCat(name)] = cat;
    return 1;
}

int Repository::getPos(){
    return this->current;
}

int Repository::isEmpty(){
    if(this->cats.getSize() == 0)
        return 0;
    return 1;
}

void Repository::nextCat(){
    if (this->isEmpty() != 0)
        this->cu

}
