#pragma once
#include<iostream>
using namespace std;


class Cat{
private:
    string breed;
    string name;
    double age;
    string photo;
public:
    Cat(string breed = "", string name = "", double age = 0, string photo = "" );

    Cat(const  Cat& c);

    ~Cat();

    string getBreed() const { return this->breed; }
    string getName() const { return this->name; }
    double getAge() const { return this->age; }
    string getPhoto() const { return this->photo; }

    void setBreed(string newBreed){ this->breed = newBreed; }
    void setName(string newName){ this->name = newName; }
    void setAge(double newAge){ this->age = newAge; }
    void setPhoto(string newPhoto){ this->photo = newPhoto; }

    string toString();
};