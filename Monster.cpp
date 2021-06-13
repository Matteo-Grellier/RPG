#include "./Monster.hpp"
#include "./Menu.hpp"

void Monster::teamAttack() {
    int damage = 0;
    int nbrOfCharacters = charactersList.size();

    Menu::toScreen(
        "",
        this->name + " attaque le groupe...",
        ""
    );

    for(Character* character : charactersList) {

        if (character->getJob() != 7) {
            damage = (this->physicalAttack / nbrOfCharacters) - character->getDefense();
            character->receiveDamage(damage);
        }

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
        this->increaseDefense(*Character::charactersList[target+3],20);
    }
}

void Monster::launchSpecialAction(Character& c) {
    randomAction();
}