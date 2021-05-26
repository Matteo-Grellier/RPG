#ifndef MENU_HPP
#define MENU_HPP
#include "./Character.hpp"

class Menu {
    // int remainingCharges;
    string endLine = string("\e[1A");

    public :
    Menu(){}
    void refresh();
    void loading();
    void start();
    void screenText(string text);
};

#endif


