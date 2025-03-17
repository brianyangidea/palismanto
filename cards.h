#include "gamestructures.h"
#include "abilities.h"

#include <string>
using namespace std;



//Declare Both Players:
Player p1 = {"Player 1", 1, 30, 1, {}};
Player p2 = {"Player 2", 1, 30, 1, {}};

//Declare All The Cards:
Card minion = {"Minion", 1, 1, 1, "A basic minion.", {}, ""};
Card megaminion = {"Mega Minion", 3, 4, 3, "A buffed-up beefcake of a minion.", {}, ""};
Card pyrominion = {"Pyro Minion", 3, 2, 2, "A fiery minion that burns bright, but runs out of fuel quickly.", {{"reduceAttackMinion", 1}}, "End of Turn: Reduce Attack By 1"};