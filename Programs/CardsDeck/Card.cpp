#include "Card.h"

//Set default value of Class Card

Card::Card(){ //Constructors with no datatype don't return anything!!
    suit = 'c'; //For str var it is "" for char var it is ' ' 
    rank = 2;
}

//In this constructor we are only, creating the failsafe
Card::Card(char s, int r){ 
    if (s != 'c' && s != 'd' && s != 'h' && s != 's' &&
        s != 'C' && s != 'D' && s != 'H' && s != 'S') 
    {
        s = 'c';
    }
    if (r < 1 || r > 13) {
        r = 2;
    }

    suit = tolower(s);
    rank = r;
}

//make sure that you but the class name after the datatype decleration
char Card::getSuit() const{ //Constructor with dataty[pe returns
    return suit;
}

int Card::getRank() const{
    return rank;
}

ostream & operator<<(ostream & out, const Card & crd){
    string suitName, rankName;

    if(crd.rank == 1){
        out << "Ace of ";
    }
    if(crd.rank == 11){
        out << "Jack of ";
    }
    if(crd.rank == 12){
        out << "Queen of ";
    }
    if(crd.rank == 13){
        out << "King of ";
    }
    if((crd.rank > 1 ) && (crd.rank < 11)){
        out << crd.rank << " of ";
    }
    if(crd.suit == 'c'){
        out << "Clubs";
    }
    if(crd.suit == 'd'){
        out << "Diamonds";
    }
    if(crd.suit == 'h'){
        out << "Hearts";
    }
    if(crd.suit == 's'){
        out << "Spades";
    }
    return out;


    /*if (crd.suit == 'c') {
        suitName = "Clubs";
    }
    else if (crd.suit == 'd') {
        suitName = "Diamonds";
    }
    else if (crd.suit == 'h') {
        suitName = "Hearts";
    }
    else if (crd.suit == 's') {
        suitName = "Spades";
    }

    if (crd.rank == 1) {
        rankName = "Ace";
    }
    else if (crd.rank == 11) {
        rankName = "Jack";
    }
    else if (crd.rank == 12) {
        rankName = "Queen";
    }
    else if (crd.rank == 13) {
        rankName = "King";
    }
    else if (crd.rank == 2) {
        rankName = "2";
    }
    else if (crd.rank == 3) {
        rankName = "3";
    }
    else if (crd.rank == 4) {
        rankName = "4";
    }
    else if (crd.rank == 5) {
        rankName = "5";
    }
    else if (crd.rank == 6) {
        rankName = "6";
    }
    else if (crd.rank == 7) {
        rankName = "7";
    }
    else if (crd.rank == 8) {
        rankName = "8";
    }
    else if (crd.rank == 9) {
        rankName = "9";
    }
    else if (crd.rank == 10) {
        rankName = "10";
    }

    out << rankName << " of " << suitName;
    return out;*/

    /*if (crd.suit == 'c'){
        suitName = "Clubs";
    }
    if (crd.suit == 'd'){
        suitName = "Diamonds";
    }
    if (crd.suit == 'h'){
        suitName = "Hearts";
    }
    if (crd.suit == 's'){
        suitName = "Spades";
    }

    if (crd.getRank() >= 1 && crd.getRank() <= 13){
        rankName = rank[crd.getRank() - 1];
    }

    //the outstream is basically like cout that is overloading the extraction operator and outputing objects to user
    //Also assigns all the extracted objects into the outStream, and by overloading the paramater, we can force the output
    outStream << rankName << " of " << suitName;
    return outStream; */

}
