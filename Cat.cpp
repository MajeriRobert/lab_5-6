#include "Cat.h"
#include<iostream>
#include<string>
using namespace std;

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

string Cat::toString(){

    string str = "";
    str += "Breed: ";
    str += this->breed;
    str += ", Name: ";
    str += this->name;
    str += ", Age: ";
    str += to_string(this->age);
    str += ", Photo:";
    str += this->photo;

    return str;
}


