#pragma once
#include "Repository.h"
#include <iostream>
#include"AdoptionList.h"

using namespace std;

class Controller
{
private:
    Repository repo;
    AdoptionList adoptlist;

public:
    Controller(const Repository& repo): repo(repo) {}

    // ~Controller();

    Repository getRepo()const { return this->repo; }

    AdoptionList getAdoptionlist() const { return this->adoptlist; }

    void addCat(const string& breed, const string& name, const double age, const string& photo);

    int removeCat(const string& name);

    int findCat(const string name);

    int updateCat(const string& _name, const string& breed, const string& name, const double age, const string& photo);

    void adopt(const Cat& cat);

    void startShow();
};