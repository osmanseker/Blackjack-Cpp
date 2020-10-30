#include "deck.h"

/* Public Global Variables ***************************************************/
vector<int>deck;
/* End Public Global Variables ***********************************************/

// Begin Functnion:init_deck = Iintialize a classic 52-Card deck.
void init_deck() {
    deck = { 1,2,3,4,5,6,7,8,9,10,10,10,10,
             1,2,3,4,5,6,7,8,9,10,10,10,10,
             1,2,3,4,5,6,7,8,9,10,10,10,10,
             1,2,3,4,5,6,7,8,9,10,10,10,10};
}

// Begin Function:shuffler = Shuffle a classic 52-Card deck.
void shuffler() {
    srand((unsigned)time(0));
    for (int i = 0; i < 52; i++)
        swap(deck[i], deck[rand() % 52]);
    cout << "\n******Deck Shuffled!******" << endl;
}

// Begin Function:print_deck =  Print the deck.
void print_deck() {
    cout << "deck: " << endl;
    int t=0;
    for (auto i : deck) {
        cout << i << " ,";
        t++;
        if (t % 13 == 0) cout << endl;
    }
}


// Begin Function:getCard = Draw a card from deck.
int getCard() {
    int card=deck.front();
    deck.erase(deck.begin());
    return card;
}

// Begin Function:is_deck_empty =  Check if the deck is empty.
bool is_deck_empty() {
    return deck.empty();
}
