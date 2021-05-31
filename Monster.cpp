#include "./Monster.hpp"

void Monster::teamAttack() {
    int damage = 0;
    int nbrOfCharacters = characterList.size();

    //rajouter une sécurité ? avec un if lenght > 0
    for(Character* character : characterList) {

        damage = (this->physicalAttack / nbrOfCharacters) - character->getDefense();
        character->receiveDamage(damage);
    }
}

void Monster::randomAction(Character& target) {
    int randomNbr = rand()%3;

    if(randomNbr == 0) {
        this->attack(target);
    } else if (randomNbr == 1) {
        this->teamAttack();
    } else {
        this->increaseDefense(target,20);
    }
}