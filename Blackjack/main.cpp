#include<iostream>
#include "game.h"

int main() {
    addDealer();            //Add a Dealer
    addPlayer();            //Add players
//    addPlayer();
//    addPlayer();
//    addPlayer();

    start();                //Start game
    turn();
    checkWin();

    system("pause");
}

