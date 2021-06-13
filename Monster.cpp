#include "./Monster.hpp"

void Monster::teamAttack() {
    int damage = 0;
    int nbrOfCharacters = charactersList.size();

    //rajouter une sécurité ? avec un if lenght > 0
    for(Character* character : charactersList) {

        damage = (this->physicalAttack / nbrOfCharacters) - character->getDefense();
        character->receiveDamage(damage);
    }
}

void Monster::randomAction() {
    int randomNbr = rand()%3;
    int target = rand()%3;

    if(randomNbr == 0) {
        
        this->attack(*Character::charactersList[target]);
    } else if (randomNbr == 1) {
        this->teamAttack();
    } else {
        this->increaseDefense(*Character::charactersList[target],20);
    }
}

void Monster::launchSpecialAction(Character& c) {
    randomAction();
}