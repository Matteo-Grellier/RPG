#include "./Menu.hpp"
#include <iostream>
#include <unistd.h>


using namespace std;


void Menu::refresh(){ 
    cout << endLine;
    cout << endLine;
    cout << endLine;

}


void Menu::start(){

    cout << "Welcome to the PURPL RPG"  << endl;
    cout << "   by PURPL STUDIO®     "  << endl;
    cout << " "  << endl;
    sleep(3);

    loading();

}


void Menu::screenText(string text){ 
    refresh();
    cout << text << "                                                " << endl;
    cout << "                                                " << endl;
    cout << "                                                " << endl;

}


void Menu::loading(){

    screenText(".");
    usleep(300000);

    screenText("..");
    usleep(300000);

    screenText("...");
    usleep(300000);
    
    screenText("");

}