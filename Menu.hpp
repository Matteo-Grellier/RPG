#ifndef MENU_HPP
#define MENU_HPP
#include "./Character.hpp"

class Menu {
    private:
    // int remainingCharges;
    // string endLine = string("\e[1A");
    string endLine = string("\e[1A\e[K");

    public :
    Menu(){}
    void refresh();
    void loading();
    void start();
    void simpleText(string text);
    void toScreen(string line1, string line2, string line3);
    void devToScreen(string line1, string line2, string line3);
    int ask(string line1, string line2);
    // void turn(vector<Character*>  arrayOfCharacters);
    void turn();
    void actions(Character& character);
    bool isEndOfCombat();
    void end(string endtype);
    string targetListing();

};

#endif


