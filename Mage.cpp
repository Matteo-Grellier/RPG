#include "./Mage.hpp"
#include "./Menu.hpp"

bool Mage::tryUsingMp(int mp){
    if(this->mp < mp){
        return false;
    }
    this->mp -= mp;
    return true;
}

void Mage::fireball(Character& other){
    if(!tryUsingMp(this->maxMp*0.10f)){
        return;
    }
    int randomNumber = rand() % 10;
    if(randomNumber == 0){

        Menu::toScreen(
            "",
            this->name + " lance une boule de feu sur " + other.name + " mais trébuche sur un tronc d'arbre et loupe la cible..." ,
            ""
        );
        return;
    }
    other.receiveDamage(this->magicAttack);

    Menu::toScreen(
        "",
        this->name + " lance une boule de feu sur " + other.name + " et lui inflige " + to_string(magicAttack) + " de dégats" ,
        other.name + " est à " + to_string(other.getCurrentHp()) + " pv."
    );
}

string Mage::getSpecialActionName() {
    if(tryUsingMp(0)) {
        return "Lancez une boule de feu";
    } else {
        return "Lancez une boule de feu (plus assez de point magique...)";
    }
}

void Mage::launchSpecialAction(Character& target) {
    fireball(target);
}