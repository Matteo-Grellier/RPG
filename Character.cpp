#include "./Character.hpp"
#include "./Menu.hpp"

Character::Character(string name, Job job, int pAtt, int mAtt, int def, int maxHp, int speed){
    this->name = name;
    this->job = job;
    this->physicalAttack = pAtt;
    this->magicAttack = mAtt;
    this->defense = def;
    this->maxHp = maxHp;
    this->hp = maxHp;
    this->speed = speed;
    charactersList.push_back(this);
}


void Character::heal(unsigned int healingValue) {
    if( hp + healingValue > maxHp){
        hp = maxHp;
    }
    else {
        hp += healingValue;
    }
}

void Character::drink(Potion& p){
    this->heal(p.getHealedHp());

    Menu::toScreen(
        "",
        this->name + " a bu une potion qui lui a redonné " + to_string(p.getHealedHp()) + " pv.",
        this->name + " est à " + to_string(this->getCurrentHp()) + " pv."
    );
}

Character& Character::operator+=(Potion& p){
    this->drink(p);
    return *this;
}

void Character::attack(Character& defender) {
    int damage = this->physicalAttack - defender.defense;
    defender.receiveDamage(damage);

    Menu::toScreen(
        "",
        this->name + " attaque " + defender.name + " et lui inflige " + to_string(damage) + " de dégats" ,
        defender.name + " est à " + to_string(defender.getCurrentHp()) + " pv."
    );
}

void Character::increaseDefense(Character& other, int valueToIncrease) {
    other.defense += valueToIncrease;

    Menu::toScreen(
        "",
        this->name + " donne de la défense à " + other.name + " et ajoute " + to_string(valueToIncrease),
        other.name + " est à " + to_string(other.defense) + " de defense."
    );
}

int Character::getCurrentHp(){
    return this->hp;
}

int Character::getDefense() {
    return this->defense;
}

int Character::getJob(){
    return this->job;

}

void Character::receiveDamage(int damage){
    if(damage < 0) {
        damage = 0;
    }
    if(this->hp - damage < 0){
        this->hp = 0;
    }
    else {
        this->hp -= damage;
    }
}

string Character::getSpecialActionName() {
    return "Action spéciale";
}

void Character::launchSpecialAction(Character& target) {
    this->attack(target);
}