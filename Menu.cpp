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

}


void Menu::simpleText(string text){ 
    refresh();
    cout << text << endl;
    cout << " " << endl;
    cout << " " << endl;

}

void Menu::toScreen(string line1, string line2, string line3) {
    refresh();

    string lines[] {line1, line2, line3};

    // for (int i = 0; i < 3; i++) {
    //     string space = i + " ";

    //     for (int ii = lines[i].length() ; ii < 50; ii++) {
    //         space += " ";
    //     }

    //     cout << lines[i] << space << endl;
        
    // }

    cout << line1 << endl;
    cout << line2 << endl;
    cout << line3 << endl;


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

string Menu::ask(string line1, string line2) {
    
    string awnser;

    toScreen(
    line1,
    line2 + " :",
    " ");

    cout << endLine;
    cin >> awnser;

    return awnser;

};

void Menu::actions(Character& character) {

    toScreen(
    " ",
    "c'est au tour de " + character.name + " de jouer",
    " ");

    sleep(1);

    if (character.getJob() != "MonsterJob" ){

        string awnser = ask("| attaquer (\"attaquer\") | action de classe (\"classe\") | boire une potion (\"potion\") |", "quel action souhaitez vous effectuez ?");

        if (awnser == "attaquer") {
            ask(
            " ",
            "quel personnage souhaitez vous attaquer ?");

            // character.attack();


        } else if (awnser == "classe") {
            ask(
            " ",
            "quel personnage voulez vous viser ?");

            // character.

        } else if (awnser == "potion") {
            ask(
            " ",
            "quel personnage voulez vous viser ?");

            // character.drink();

        } else {
            toScreen(
            " ",
            "Action inconnu",
            " ");

            actions(character);

        }


    } else {
        





    }


}