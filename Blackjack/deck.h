#ifndef DECK_H
#define DECK_H

#include<iostream>
#include<vector>
#include<stdlib.h>
#include<time.h>

using namespace std;

// Public C++ Function Prototypes
void init_deck();
void shuffler();
void print_deck();
int  getCard();
bool is_deck_empty();


#endif // DECK_H
