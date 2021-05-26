#include "./Character.hpp"

Character::Character(string name, Job job, int pAtt, int mAtt, int def, int maxHp){
    this->name = name;
    this->job = job;
    this->physicalAttack = pAtt;
    this->magicAttack = mAtt;
    this->defense = def;
    this->maxHp = maxHp;
    this->hp = maxHp;
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
}

Character& Character::operator+=(Potion& p){
    this->drink(p);
    return *this;
}

void Character::attack(Character& defender) {
    int damage = this->physicalAttack - defender.defense;
    defender.receiveDamage(damage);
}

int Character::getCurrentHp(){
    return this->hp;
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