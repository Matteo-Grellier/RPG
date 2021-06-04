#include "./Menu.hpp"
#include <iostream>
#include <unistd.h>


using namespace std;


void Menu::refresh(){ 
    cout << endLine;
    cout << endLine;
    cout << endLine;
    //just test
    cout << "R";

}


void Menu::start(){

    cout << "Welcome to the PURPL RPG"  << endl;
    cout << "   by PURPL STUDIO®     "  << endl;
    cout << "                                                "  << endl;
    sleep(3);

    loading();

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
            // for test purpose it's pipe and not space
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

string Menu::ask(string message){

    string awnser;

    toScreen(
    " ",
    message + " :",
    " ");

    cout << endLine;
    cin >> awnser;

    return awnser;
    
}

void actions(Character& character) {



}