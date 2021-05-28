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
    cout << "                                                "  << endl;
    sleep(3);

    loading();

    string name1;
    string name2;
    string name3;

    toScreen(
    "1",
    "Please select a name for your first character :",
    " ");
    cin >> name1;

    toScreen(
    "2",
    "Please select a name for your second character :",
    " ");
    cin >> name2;

    toScreen(
    "3",
    "Please select a name for your third character :",
    " ");
    cin >> name3;

}


void Menu::simpleText(string text){ 
    refresh();
    cout << text << "                                                " << endl;
    cout << "                                                " << endl;
    cout << "                                                " << endl;

}

void Menu::toScreen(string line1, string line2, string line3) {
    refresh();

    string lines[] {line1, line2, line3};

    for (int i = 0; i < 3; i++) {
        string space = i + " ";

        for (int ii = lines[i].length() ; ii < 50; ii++) { 
            space += "|";
        }

        cout << lines[i] << space << endl;
        
    }
    sleep(1);
}


void Menu::loading(){

    simpleText(".");
    usleep(300000);

    simpleText("..");
    usleep(300000);

    simpleText("...");
    usleep(300000);
    
    simpleText("");

}