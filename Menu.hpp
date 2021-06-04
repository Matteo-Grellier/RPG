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
    void simpleText(string text);
    void toScreen(string line1, string line2, string line3);
    string ask(string message);
    void actions(Character& character);
};

#endif


