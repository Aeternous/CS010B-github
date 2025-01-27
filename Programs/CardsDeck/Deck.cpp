#include "Deck.h"
#include <iostream>
#include <algorithm>

using namespace std;

Deck::Deck(){ //Default Constructor
    char suit[] = {'c', 'h', 'd', 's'};
    for (unsigned int i = 0; i < 4; ++i){
        for (unsigned int k = 0; k < 13; ++k){
            //As i increases, the suits index reversed
            Card newCrd (suit[i], k);
            theDeck.push_back(newCrd);
        }
    }
}

/*
    if (i == 0){ 
        Card newCrd('s', k);
        theDeck.push_back(newCrd);
    } 
    else if (i == 1){
        Card newCrd('d', k);
        theDeck.push_back(newCrd);
    }
    else if (i == 2){
        Card newCrd('h', k);
        theDeck.push_back(newCrd);
    }
    else if (i == 3){
        Card newCrd('s', k);
        theDeck.push_back(newCrd);
    }
*/
Card Deck::dealCard(){
    if (theDeck.empty()){
        return Card();
    }
    Card topCrd = theDeck.back();/*.getSuit(), theDeck.back().getRank());*/ //Accesses the Top card through the backside of the vector(starting from ace of given suit)
    theDeck.pop_back(); //Destroys the card that was accessed recently from the undealt pile(vector)
    dealtCards.push_back(topCrd); //Move the accessed cards to a new vector as dealt card pile

    return topCrd; //Returns the pulled card
    
}

void Deck::shuffleDeck(){
    for(unsigned int i = 0;i < dealtCards.size(); ++i){
        theDeck.push_back(dealtCards[i]);
    }
    dealtCards.clear();

    //srand(static_cast<unsigned int>(time(0))); 
    random_shuffle(theDeck.begin(), theDeck.end()); 
    
}

unsigned Deck::deckSize() const{
    return theDeck.size();
}