#include "./Menu.hpp"
#include <iostream>
#include <unistd.h>
#include <bits/stdc++.h>

using namespace std;

string Menu::endLine = string("\e[1A\e[K");

void Menu::refresh(){ 
    cout << Menu::endLine;
    cout << Menu::endLine;
    cout << Menu::endLine;

}

void Menu::start(){

    cout << "Welcome to the PURPL RPG" << endl;
    cout << "   by PURPL STUDIO®" << endl;
    cout << " " << endl;

    sleep(2);

    loading();

}

void Menu::toScreen(string line1, string line2, string line3) {
    Menu::devToScreen(
    line1,
    line2,
    line3);

    sleep(2);
    
}

void Menu::devToScreen(string line1, string line2, string line3) {
    refresh();
    
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

int Menu::ask(string line1, string line2) {
    
    int answer;

    devToScreen(
    line1,
    line2 + " :",
    " ");

    cout << Menu::endLine;
    cin >> answer;

    return answer;

};

void Menu::turn() {

    vector<Character*> charactersList = Character::charactersList;
    vector<int> speedList;
    vector<Character*> charactersOrdered;


    for (Character* c : Character::charactersList) {
        speedList.push_back(c->speed);

    }

    sort(speedList.begin() , speedList.end(), greater<int>());

    for (int speed : speedList) {

        for (Character* c : Character::charactersList) {

            if (c->speed == speed ) {

                charactersOrdered.push_back(c);

            }
        }

    }  

    for (Character* c : charactersOrdered) {

        if (!isEndOfCombat() && c->getCurrentHp() != 0) {
            actions(*c);
        } else {
            return;
        }       
    }
    return;
}

string Menu::targetListing() {
    string buffStr = "";
    int buffInt = 0;

    for (Character* c : Character::charactersList) {

        if(c->getCurrentHp() != 0) {
            buffStr += to_string(buffInt) + ". " + c->name + " | ";
        }

        buffInt++;

    }

    return buffStr;
}

void Menu::actions(Character& character) {


    toScreen(
    " ",
    "c'est au tour de " + character.name + " de jouer",
    " ");

    if (character.getJob() != 7 ){

        int awnser = ask("| 1. attaquer | 2. " + character.getSpecialActionName() + " | 3. boire une potion |", "quel action souhaitez vous effectuer ?");
        int subAwnser;

        string targetList = targetListing();

        if (awnser == 1) {
            subAwnser = ask(
            targetList,
            "quel personnage souhaitez vous attaquer ?");


            character.attack(*Character::charactersList[subAwnser]);

        } else if (awnser == 2) {

            if (character.getJob() != 3) {
                subAwnser = ask(
                targetList,
                "quel personnage voulez vous viser ?");

                character.launchSpecialAction(*Character::charactersList[subAwnser]);
            } else {
                character.launchSpecialAction(character);
            }

        } else if (awnser == 3) {

            subAwnser = ask("| 0. Grande potion | 1. Moyenne potion | 2. Petite potion |", "choisissez une potion");

            character.drink(*Character::potionsList[subAwnser]);

        } else {
            toScreen(
            " ",
            "Action inconnu",
            " ");

            actions(character);

        }


    } else {
        character.launchSpecialAction(character);
    }
}

bool Menu::isEndOfCombat(){

    int deadGoodGuys = 0;
    int deadMonsters = 0;
    string awnser = "none";

    for (Character* c : Character::charactersList) { //for every characters
        
        if(c->getCurrentHp() <= 0 && c->getJob() != 7) {
            deadGoodGuys++;

        } else if(c->getCurrentHp() <= 0 && c->getJob() == 7) {
            deadMonsters++;

        }

        if (deadMonsters == 3) {
            end("win");
            return true;

        } else if (deadGoodGuys == 3) {
            end("defeat");
            return true;
        }

    }

    return false;
}

void Menu::end(string endtype){

    if ( endtype == "win") {
        toScreen(
        "",
        "you won mate, well done !",
        "");
        sleep(1);

    } else if ( endtype == "defeat") {
        toScreen(
        "",
        "you failed poor noob...",
        "");
        sleep(1);
    }

}
