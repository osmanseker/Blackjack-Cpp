#include "player.h"

//Begin Function:Hit = Take another card from top of the deck.
void Player::Hit() {
    this->hand.push_back(getCard());
}

// Begin Function:Stand = Take no more cards, also known as "stand pat", "stick", or "stay".
void Player::Stand() {
 //Stand, do nothing.
}


// Begin Function:CheckHand = Check the sum of player's cards.
int Player::CheckHand() {
    int sum = 0;
    for (auto i : this->hand) {
        if (i == 1 && sum + 11 <= 21) i = 11;
        cout << "Card: " << i << endl;
        sum += i;
    }
    return sum;
}

// Begin Function:choice = In each turn, Players can choose to Hit or Stand if their hand<21.
char Player::choice() {
    cout << "\nNo Blackjack, Hit or Stand?" << endl;
    cout << "Press H to draw a card, press S to stand." << endl;
    char c = ' ';
    cin >> c;
    return c;
}





