#include "Cat.h"
#include<iostream>
#include<string>

Cat::Cat(string breed , string name , double age , string photo): breed(breed), name(name), age(age), photo(photo){ }

Cat::Cat(const Cat& c){
    this->breed      = c.breed;
    this->name       = c.name;
    this->age        = c.age;
    this->photo = c.photo;
}

Cat::~Cat(){
    // delete this;
}

