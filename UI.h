#pragma once
#include "Controller.h"

class UI
{
private:
    Controller ctrl;

public:
    UI(const Controller& c): ctrl(c) {}
    void run();
    // ~UI();
private:
    static void printMenu();
    static void printAdminMenu();
    static void printUserMenu();

    void addCatUI();
    void showAll();
    void removeCatUI();
    void updateCatUI();
    void adopt();

    void getOne();

    void nextCatUI();

    void getCurrentCat();

    void showAdopted();

    void showByBreed();

    void firstBreed();


};