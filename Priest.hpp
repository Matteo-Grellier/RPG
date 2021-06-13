#ifndef PRIEST_HPP
#define PRIEST_HPP
#include "./Character.hpp"


using namespace std;

class Priest : public Character
{
private:
    int maxMp;
    int Mp;
    int healValue;
    bool tryUsingMp(int Mp);
public:
    Priest(string name);
    void healSpell(Character& other);

    string getSpecialActionName() override;

    void launchSpecialAction(Character& target) override;
};


#endif