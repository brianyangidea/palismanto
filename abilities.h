#include <string>
using namespace std;

// A collection of card abilities:


//This function reduces the attack of a minion by a set amount
void reduceAttackMinion(Card &card, int reduction){

    card.attack = card.attack - reduction;

}

//This function increases the attack of a minion by a set amount
void increaseAttackMinion(Card &card, int increase){

    card.attack = card.attack + increase;

}

