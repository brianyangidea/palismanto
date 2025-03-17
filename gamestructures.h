#include <string>
#include <bits/stdc++.h>
#include <map>
using namespace std;


//Defines a minion card in the game
struct Card {

    string cardname;
    int attack;
    int health;
    int cost;
    string carddescription;
    map<string, int> ability;
    string abilitydescription;

};

 //Notes: 
 //The ability fieldis a dictionary that uses key words. For example, "{reduceAttackMinion, 1}". See the cards.h file for the keyword legend.
 //An empty dictionary {} means a card has no abilities.


//Defines a player in the game
struct Player {

    string playername;
    int playerid;
    int health;
    int sparks;
    Card deck[40];
    
};


