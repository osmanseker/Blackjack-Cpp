#include "dealer.h"

// Begin Function:setPlayerSet = Initialize player set.
void Dealer::setPlayerSet(vector<Player*>& playerSet) {
    this->playerSet = playerSet;
}

// Begin Function:getPlayerSet = Get player set.
vector<Player*> Dealer::getPlayerSet() {
    return this->playerSet;
}

// Begin Function:Hit = Take another card from top of the deck.
void Dealer::Hit() {
    this->hand.push_back(getCard());
}

// Begin Function:Distribute = The player or players are dealt a two-card hand.
void Dealer::Distribute() {

    this->Hit();
    this->Hit();

    for (auto p : this->playerSet) {
        p->Hit();
        p->Hit();
    }
}

// Begin Function:CheckHand = Check the sum of Dealer's cards.
int Dealer::CheckHand() {
    int sum = 0;
    cout << "\nDealer Hand:\n" << endl;
    for (auto i : this->hand) {
        if (i == 1 && sum + 11 <= 21) i = 11;
        cout << "Card: " << i << endl;
        sum += i;
    }
    return sum;
}
