#include"AdoptionList.h"

AdoptionList::AdoptionList(){
    this->current = 0;
}

void AdoptionList::add(const Cat& cat){
    this->cats.add(cat);
}

Cat AdoptionList::getCurrentCat(){
    if(this->current == this->cats.getSize())
        this->current = 0;
    return this->cats[this->current];
}

void AdoptionList::next(){
    if(this->cats.getSize() == 0)
        return;
    this->current++;
    Cat currentCat = this->getCurrentCat();
}

bool AdoptionList::isEmpty(){
    return this->cats.getSize() == 0;
}