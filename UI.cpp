#include "UI.h"
#include <string>

using namespace std;

void UI::printMenu(){
    cout << endl;
    cout << "1 - Admin." << endl;
    cout << "2 - User." <<endl;
    cout << "0 - Exit." <<endl;

}

void UI::printAdminMenu(){
    cout << endl;
    cout << "1.Add a cat." << endl;
    cout << "2.Show all cats." << endl;
    cout << "3.Remove a cat." << endl;
    cout << "4.Update a cat's info." << endl;
    cout << "0.Return." << endl;
}


void UI::printUserMenu(){
    cout << endl;
    cout << "1.Show cats." << endl;
    cout << "2.Next cat." <<endl;
}

void UI::addCatUI(){

    cout <<"Enter the breed: ";
    string breed;
    getline(cin, breed);

    cout << "Enter its name: ";
    string name;
    getline(cin, name);

    cout << "Enter its age: ";
    double age = 0;
    cin >> age;

    cout << "Attach its photo: ";
    string photo;
    cin >> photo;

    this->ctrl.addCat(breed, name, age, photo);
}

void UI::removeCatUI(){
    cout <<"Enter its name: " <<endl;
    string name;
    getline(cin, name);
    if(this->ctrl.removeCat(name) != 0)
        cout<<"Cat removed." << endl;
    else
        cout << "No such cat." <<endl ;
}

void UI::updateCatUI(){
    cout << "Enter the cat's name: ";
    string _name;
    getline(cin, _name);
    // if(this->ctrl.findCat(_name) == -1)
    //     cout<<" There is no cat with this name in the shelter." << endl;


    cout << "Enter the new breed: ";
    string breed;
    getline(cin, breed);

    cout << "Enter its new name: ";
    string name;
    getline(cin, name);

    cout << "Enter its new age: ";
    double age = 0;
    cin >> age;
    cout << "Attach its photo: ";
    string photo;
    cin >> photo;


    if(this->ctrl.updateCat(_name, breed, name, age, photo) == 0)
        cout<<"Cat updated." << endl;
    else
        cout<<" There is no cat with this name in the shelter." << endl;

}

void UI::showAll(){
    DynamicVector<Cat> list = this->ctrl.getRepo().getCats();
     Cat* cats = list.getElems();

     // if(list.size() == 0)
    //     return;
    if(list.getSize() == 0){
        cout << "There is no cat here." << endl;
        return;
    }
    cout << endl;
    cout << "These are the available cats: "<< endl;
    for(int i = 0; i < list.getSize(); i++){
        Cat c = list[i];
        cout << endl ;
        cout<< "Breed: " <<c.getBreed() <<endl;
        cout << "Name: " <<c.getName() <<endl;
        cout << "Age: " << c.getAge() <<endl;
        cout << "Photograph link: " <<c.getPhoto() << endl;

    }
}

void UI::getOne(){
    DynamicVector<Cat> cats = ctrl.getRepo().getCats();
    int i;
    for(i=0; i < cats.getSize(); i++){
        string str;
        str = cats[i].toString();
        cout << str << endl;
    }

}

void UI::nextCatUI(){
    this->ctrl.nextCat();
}

void UI::getCurrentCat(){
    Cat cat = this->ctrl.getCurrentCtrl();
    string str;
    str = cat.toString();
    cout << str << endl;
}

void UI::run(){
    while (true){
        UI:printMenu();
        int choice{0};
        cout << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        if(choice == 0)
            break;

        if(choice == 1)
        {
            while (true){
                UI::printAdminMenu();
                int adminChoice{0};
                cout << endl;
                cout << "Enter your choice: ";
                cin >> adminChoice;
                cin.ignore();
                if(adminChoice == 0)
                    break;
                switch(adminChoice){
                    case 1:
                        this->addCatUI();
                        break;
                    case 2:
                        this->showAll();
                        break;
                    case 3:
                        this->removeCatUI();
                        break;
                    case 4:
                        this->updateCatUI();
                        break;

                }
            }
        }
        if(choice == 2){
            while(true){
                UI::printUserMenu();
                int userChoice{0};
                cout << endl;
                cout << "Enter your choice: ";
                cin >> userChoice;
                cin.ignore();
                if(userChoice == 0)
                    break;
                switch(userChoice){
                    case 1:
                        this->getCurrentCat();
                        cout << endl;
                        break;
                    case 2:
                        this->nextCatUI();
                        this->getCurrentCat();

                        cout << endl;
                }
            }
        }
    }
}