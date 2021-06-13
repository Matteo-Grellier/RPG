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

    devToScreen(
    "Welcome to the PURPL RPG",
    "   by PURPL STUDIO®",
    "");

    sleep(3);

    loading();

}

void Menu::toScreen(string line1, string line2, string line3) {
    devToScreen(line1, line2, line3);
    sleep(1);
}

void Menu::devToScreen(string line1, string line2, string line3) {
    refresh();

    string lines[] {line1, line2, line3};
    
    cout << line1 << endl;
    cout << line2 << endl;
    cout << line3 << endl;
}


void Menu::loading(){

    devToScreen("","    .","");
    usleep(300000);

    devToScreen("","    ..","");
    usleep(300000);

    devToScreen("","    ...","");
    usleep(300000);
    
    devToScreen("","","");

}

string Menu::ask(string line1, string line2) {
    
    string awnser;

    devToScreen(
    line1,
    line2 + " :",
    " ");

    cout << endLine;
    cin >> awnser;

    return awnser;

};

void Menu::turn(vector<Character*> arrayOfCharacters) {

    for (int i = 0; i < arrayOfCharacters.size(); i++ ) { //for every characters
        actions( *arrayOfCharacters[i] );

    }

}

void Menu::actions(Character& character) {

    string isEndCombat = isEndOfCombat(character.charactersList);

    if ( isEndCombat == "win") {
        end("win");

    } else if ( isEndCombat == "defeat") {
        end("defeat");

    } else {

        devToScreen(
        " ",
        "c'est au tour de " + character.name + " de jouer",
        " ");

        sleep(1);

        if (character.getJob() != "MonsterJob" ){

            string awnser = ask("| attaquer (\"attaquer\") | action de classe (\"classe\") | boire une potion (\"potion\") |", "quel action souhaitez vous effectuez ?");
            string subAwnser;

            if (awnser == "attaquer") {
                subAwnser = ask(
                " ",
                "quel personnage souhaitez vous attaquer ?");


                // character.attack();


            } else if (awnser == "classe") {
                subAwnser = ask(
                " ",
                "quel personnage voulez vous viser ?");

                // character.launchSpecialAction();

            } else if (awnser == "potion") {
                subAwnser = ask(
                " ",
                "quel personnage voulez vous viser ?");

                // character.drink();

            } else {
                devToScreen(
                " ",
                "Action inconnu",
                " ");

                actions(character);

            }


        } else {
            

        }
    }
}

string Menu::isEndOfCombat(vector<Character*>  arrayOfCharacters){

    int deadGoodGuys = 0;
    int deadMonsters = 0;
    string awnser = "none";

    for (int i = 0; i < arrayOfCharacters.size(); i++ ) { //for every characters
        
        if(arrayOfCharacters[i]->getCurrentHp() <= 0 && arrayOfCharacters[i]->getJob() != "Monster") {
            deadGoodGuys++;

        } else if(arrayOfCharacters[i]->getCurrentHp() <= 0 && arrayOfCharacters[i]->getJob() == "Monster") {
            deadMonsters++;

        }

        if (deadMonsters == 3) {
            awnser = "win";

        } else if (deadGoodGuys == 3) {
            awnser = "defeat";
        }

        return awnser;

    }

}

void Menu::end(string endtype){

    if ( endtype == "win") {
        toScreen(
        "",
        "you won mate, well done !",
        "");

    } else if ( endtype == "defeat") {
        toScreen(
        "",
        "you failed poor noob...",
        "");

    }

}
