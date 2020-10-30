#include "game.h"
#include<string>

/* Public Global Variables *********************************************/
vector<Dealer*>dealerSet;
vector<Player*>playerSet;
/* End Public Global Variables *****************************************/

// Begin Function:addDealer = Add a Dealer to the game.

void addDealer() {
    Dealer* d = new Dealer();
    dealerSet.push_back(d);
}


// Begin Function:addPlayer = Add a Player to the game.
void addPlayer() {
    Player* d = new Player();
    playerSet.push_back(d);
}

// Begin Function:start = Start game, config deck and players.
void start() {
    cout << "******Game Start!******"<<endl;
    init_deck();
    print_deck();
    shuffler();
    print_deck();
    Dealer* d = dealerSet.front();
    d->setPlayerSet(playerSet);
    d->Distribute();
}


// Begin Function:checkWin = Check who wins in a round.
void checkWin() {
    cout << "\n******Check Win****** \n" << endl;
    Dealer* d = dealerSet.front();
    int dealerHand=d->CheckHand();
    int player = 0;

    string res = "";
    for (auto p : d->getPlayerSet()) {
        player++;
        cout << "\nPlayer" << player << "'s Hand\n" << endl;
        int playerHand = p->CheckHand();
        if (playerHand == 21 && dealerHand == 21) {
            res += "Player";
            res += (char)(player + '0');
            res+=" Blackjack Push!\n";
        }else
        if (playerHand == 21 && dealerHand != 21) {
            res += "Player";
            res += (char)(player + '0');
            res += " Wins, Blackjack!\n";
        }else
        if(playerHand != 21 && dealerHand == 21) {
            res+= "Dealer Wins, Blackjack!\n";
        }else
        if (playerHand <21 && playerHand > dealerHand) {
            res+= "Player";
            res+= (char)(player + '0');
            res += " Wins!\n";
        }else
        if (playerHand > 21) {
            res+= "Player";
            res+= (char)(player + '0');
            res += " Bust, you lose!\n";
        }else
        if (dealerHand > 21) {
            res+= "Dealer Bust, Player Wins!\n";
        }else
        if (playerHand == dealerHand) {
            res += "Player";
            res += (char)(player + '0');
            res+= " Push!\n";
        }else
        if (playerHand < dealerHand) {
            res += "Player";
            res += (char)(player + '0');
            res += " lose!\n";
        }
    }
        cout << res << endl;
}


/* Begin Function:turn = Take turns, each non-blackjack player can choose to Hit or Stand,
if hand>21, Bust!
After all players' turn end, Dealer must Hit until hand>17,
if hand>21, Bust, else, checkWin().*/

void turn() {
    Dealer* d = dealerSet.front();
    int player = 0;
    for (auto p : d->getPlayerSet()) {
        player++;
        cout << endl;
        cout << "******Player" << player << "'s move*******" << endl;
        cout << "Player" << player << "'s Hand \n" << endl;
        int playerHand = p->CheckHand();
        char c = ' ';
        while (c != 's' && playerHand < 21) {
            c = p->choice();
            if (c == 'h')
                p->Hit();
            else if (c == 's')
                /*Stand, do nothing*/;
            else
                cout << "Invalid input, try again." << endl;
            playerHand = p->CheckHand();
        }
    }
    cout << "\n******Turns end!******\n" << endl;
    while (d->CheckHand() < 17)
        d->Hit();
}

