#ifndef PLAYER_H
#define PLAYER_H

#include "deck.h"

class Player {

private:
    vector<int>hand;

public:
    // Public C++ Function Prototypes

    void Hit();         //take card
    void Stand();       //Stop
    //void Double();
    //void Split();
    int CheckHand();    //check sum
    char choice();      //H or S

};


#endif // PLAYER_H
