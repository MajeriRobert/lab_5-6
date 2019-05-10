#include "Cat.h"
#include "UI.h"

using namespace std;


int main()
{
    // DynamicVector<Cat> vec;
    // Cat c3{"Matz", "Vasi", 16, "https/dfasdf"};
    // vec = vec + c3 ;
    // vec = c3 + vec;

    Repository repo{};

    Cat c1{"British", "Tom", 7, "http://www.sblabla"};
    Cat c2{"Corcitura", "Tim", 20, "https://www.matzeurate.com"};
    repo.add(c1);
    repo.add(c2);


    Controller ctrl{repo};
    UI ui{ctrl};
    ui.run();

    return 0;
}