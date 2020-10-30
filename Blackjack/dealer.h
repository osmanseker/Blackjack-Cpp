#ifndef DEALER_H
#define DEALER_H

#include "deck.h"
#include "player.h"


class Dealer {

private:
    vector<int>hand;
    vector<Player*>playerSet;

public:
    // Public C++ Function Prototypes
    void setPlayerSet(vector<Player*>& playerSet);
    vector<Player*> getPlayerSet();
    void Distribute();
    void Hit();
    int CheckHand();

};



#endif // DEALER_H


