#include "Controller.h"

void Controller::addCat(const string& breed, const string& name, const double age, const string& photo){
    Cat cat(breed, name, age, photo);

    this->repo.add(cat);
}

int Controller::removeCat(const string& name){
    return this->repo.remove(name);
}

int Controller::findCat(const string name){
    return this->repo.findCat(name);
}

int Controller::updateCat(const string& _name, const string& breed, const string& name, const double age, const string& photo){
    Cat cat(breed, name , age, photo);
    return this->repo.update(_name, cat);
}

void Controller::adopt(const Cat& cat){
    this->adoptlist.add(cat);

}

void Controller::nextCat(){
    this->repo.nextCat();
}

Cat Controller::getCurrentCtrl(){
    return this->repo.getCurrent();
}

DynamicVector<Cat> Controller::getByBreed(const string breed,const double age){
    DynamicVector<Cat> list;
    int i;
    for(i = 0; i < this->getRepo().getCats().getSize(); i++){
        if(this->getRepo().getCats()[i].getBreed() == breed && this->getRepo().getCats()[i].getAge() <= age)
            list.add(this->getRepo().getCats()[i]);
    }
    return list;
}