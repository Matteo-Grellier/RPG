#ifndef MENU_HPP
#define MENU_HPP
#include "./Character.hpp"

class Menu {

    public :
    Menu(){}

    static string endLine;

    static void refresh();
    static void loading();
    static void start();
    static void simpleText(string text);
    static void toScreen(string line1, string line2, string line3);
    static void devToScreen(string line1, string line2, string line3);
    static int ask(string line1, string line2);

    static void turn();
    static void actions(Character& character);
    static bool isEndOfCombat();
    static void end(string endtype);
    static string targetListing();

};

#endif


