#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "./Potion.hpp"
#include <string>
#include <vector>

using namespace std;

enum Job {
    FreelancerJob,
    MageJob,
    WarriorJob,
    BarbarianJob,
    DruidJob,
    PriestJob,
    PaladinJob,
    MonsterJob
};

class Character
{

    public:
    string name;
    static vector<Character*> charactersList;
    static vector<Potion*> potionsList;
    int speed;


    protected:
    
    int physicalAttack;
    int magicAttack;
    int defense;
    int maxHp;
    int hp;


    private:
    Job job;

    public:
    Character() : Character("John Doe",FreelancerJob,100,100,50,1000,100){}

    Character(string name, Job job, int pAtt, int mAtt, int def, int maxHp, int speed);

    void heal(unsigned int healingValue);

    void drink(Potion& p);

    Character& operator+=(Potion& p);

    void attack(Character& defender);

    void increaseDefense(Character& defender, int valueToIncrease);

    int getCurrentHp();

    int getDefense();

    int getJob();

    public:
    void receiveDamage(int damage);

    virtual string getSpecialActionName();

    virtual void launchSpecialAction(Character& target);

};

#endif