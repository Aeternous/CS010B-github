/*int main() {
    srand(2222);
    string response;
    string outputFileName;
    ofstream fileStream;
    unsigned int cardsInHand;
    double totalSimulations;
    double totalPairs = 0;
    double pairChance;
    unsigned int index;

    Deck cardDeck;
    vector<Card> playerHand;

    cout << "Do you want to output all hands to a file? (Yes/No) " << endl;
    cin >> response;

    if (response == "Yes" || response == "yes") { // Asking about outputting to file
        cout << "Enter name of output file: " << endl;
        cin >> outputFileName;
        fileStream.open(outputFileName);
        if (!fileStream.is_open()) {
            cout << "Error opening " << outputFileName << endl;
            return 1;
        }
    }

    cout << "Enter number of cards per hand: " << endl;
    cin >> cardsInHand;

    cout << "Enter number of deals (simulations): " << endl;
    /*if (response == "Yes" || response == "yes") {
        cout << "WARNING: Every simulation outputs the deck of cards to " << 
        outputFileName << " on a separate line. Be careful about how many simulations you run!" << endl;
    }
    cin >> totalSimulations;

    for (index = 0; index < totalSimulations; ++index) { 
        cardDeck.shuffleDeck();
        playerHand.clear();

        for (unsigned int j = 0; j < cardsInHand; ++j) { // Putting cards into the vector playerHand
            playerHand.push_back(cardDeck.dealCard());
        }

        if (hasPair(playerHand)) {
            if (response == "Yes" || response == "yes") {
                fileStream << "Found Pair!! ";
                fileStream << playerHand << endl;
            }
            totalPairs++;
        }
        else {
            if (response == "Yes" || response == "yes") {
                fileStream << "             " << playerHand << endl;
            }
        }
    }

    pairChance = totalPairs / totalSimulations * 100.0;

    cout << "Chances of receiving a pair in a hand of " << cardsInHand << " cards is: " << pairChance << "%" << endl;

    // Outputting pairChance only if there was at least one hand processed
    if (totalSimulations > 0) {
        fileStream << "Chances of receiving a pair in a hand of " << cardsInHand << " cards is: " << pairChance << "%" << endl;
    }

    return 0;
}*/
#/*include <iostream>
#include <cstdlib>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

#include "Deck.h"
#include "Card.h"

// Returns true if vector of Cards passed in contains at least 2 Cards with the same rank.
bool hasPair(const vector<Card> &playerHand);

// Sends to output stream a hand of Cards on a single line, 
// each Card separated by a comma.
// If the vector is empty, do not output anything.
// Example (vector size of 3): Ace of Spades, Two of Hearts, King of Clubs 
ostream & operator<<(ostream &, const vector<Card> &);

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
    srand(2222);
    string response;
    string outputFileName;
    ofstream fileStream;
    unsigned int cardsInHand;
    double totalSimulations;
    double totalPairs = 0;
    double pairChance;
    unsigned int index;

    Deck cardDeck;
    vector<Card> playerHand;

    cout << "Do you want to output all hands to a file? (Yes/No) " << endl;
    cin >> response;

    if (response == "Yes" || response == "yes") { // Asking about outputting to file
        cout << "Enter name of output file: " << endl;
        cin >> outputFileName;
        fileStream.open(outputFileName);
        if (!fileStream.is_open()) {
            cout << "Error opening " << outputFileName << endl;
            return 1;
        }
    }
    
    cout << "Enter number of cards per hand: " << endl;
    cin >> cardsInHand;

    cout << "Enter number of simulations (no commas): " << endl;
    if (response == "Yes" || response == "yes") {
        cout << "WARNING: Every simulation outputs the deck of cards to " << 
        outputFileName << " on a separate line. Be careful about how many simulations you run!" << endl;
    }
    cin >> totalSimulations;

    for (index = 0; index < totalSimulations; ++index) { 
        cardDeck.shuffleDeck();
        playerHand.clear();

        for (unsigned int j = 0; j < cardsInHand; ++j) { // Putting cards into the vectors dealtCards and playerHand
            playerHand.push_back(cardDeck.dealCard());
        }

        if (hasPair(playerHand)) {
            if (response == "Yes" || response == "yes") {
                fileStream << "Found Pair!! ";
                fileStream << playerHand << endl;
            }
            totalPairs++;
        }
        else {
            if (response == "Yes" || response == "yes") {
                fileStream << "             " << playerHand << endl;
            }
        }
    }

    pairChance = totalPairs / totalSimulations * 100.0;

    cout << "Chances of receiving a pair in a hand of " << cardsInHand << " cards is: " << pairChance << "%" << endl;

    if (hasPair(playerHand)) {
        fileStream << "Chances of receiving a pair in a hand of " << cardsInHand << " cards is: " << pairChance << "%" << endl;
    }

    return 0;
}


bool hasPair(const vector<Card> &playerHand) {
    for (unsigned int i = 0; i < playerHand.size(); ++i) {
        for (unsigned int j = i + 1; j < playerHand.size(); ++j) {
            if (playerHand[i].getRank() == playerHand[j].getRank()) {
                return true;
            }
        }
    }
    return false;
}

ostream & operator<<(ostream &fileStream, const vector<Card> &playerHand){
    for (unsigned int i = 0; i < playerHand.size(); ++i){
        fileStream << playerHand[i] << ", ";
    }
    fileStream << playerHand.back();
    return fileStream;
}*/

/*#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

#include "Deck.h"
#include "Card.h"

// Returns true if vector of Cards passed in contains at least 2 Cards with the same rank.
bool hasPair(const vector<Card> &playerHand);

// Sends to output stream a hand of Cards on a single line,
// each Card separated by a comma.
// If the vector is empty, do not output anything.
ostream &operator<<(ostream &, const vector<Card> &);

int main() {
    srand(2222);
    string userInput;
    string fileStream;
    int playerHand;
    int dealCount;

    cout << "Do you want to output all hands to a file?(Yes/No)" << endl;
    cout << "Enter name of output file:" << endl;
    if(userInput == "Yes"){
        cin >> fileStream;
    }

    cout << "Enter number of cards per hand: " << endl;
    cin >> playerHand;

    cout << "Enter number of deals (simulations): " << endl;
    cin >> dealCount;

    cout << "Chances of receiving a pair in a hand of " << playerHand << " cards is: " << "%" << endl;

    return 0;
}


bool hasPair(const vector<Card> &playerHand) {
    for (unsigned int i = 0; i < playerHand.size(); ++i) {
        for (unsigned int j = i + 1; j < playerHand.size(); ++j) {
            if (playerHand[i].getRank() == playerHand[j].getRank()) {
                return true;
            }
        }
    }
    return false;
}

ostream &operator<<(ostream &fileStream, const vector<Card> &playerHand) {
    if (!playerHand.empty()) {
        for (unsigned int i = 0; i < playerHand.size() - 1; ++i) {
            fileStream << playerHand[i] << ", ";
        }
        fileStream << playerHand.back(); // No trailing comma for the last element
    }
    return fileStream;
}*/


#/*include <iostream>
#include <cstdlib>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

#include "Deck.h"
#include "Card.h"

// Returns true if vector of Cards passed in contains at least 2 Cards with the same rank.
bool hasPair(const vector<Card> &playerHand);

// Sends to output stream a hand of Cards on a single line, 
// each Card separated by a comma.
// If the vector is empty, do not output anything.
// Example (vector size of 3): Ace of Spades, Two of Hearts, King of Clubs 
ostream & operator<<(ostream &, const vector<Card> &);

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
    srand(2222);
    string response;
    string outputFileName;
    ofstream fileStream;
    unsigned int cardsInHand;
    double totalSimulations;
    double totalPairs = 0;
    double pairChance;
    unsigned int index;

    Deck cardDeck;
    vector<Card> playerHand;

    cout << "Do you want to output all hands to a file? (Yes/No) " << endl;
    cin >> response;

    if (response == "Yes" || response == "yes") { // Asking about outputting to file
        cout << "Enter name of output file: " << endl;
        cin >> outputFileName;
        fileStream.open(outputFileName);
        if (!fileStream.is_open()) {
            cout << "Error opening " << outputFileName << endl;
            return 1;
        }
    }
    
    cout << "Enter number of cards per hand: " << endl;
    cin >> cardsInHand;

    cout << "Enter number of simulations (no commas): " << endl;
    if (response == "Yes" || response == "yes") {
        cout << "WARNING: Every simulation outputs the deck of cards to " << 
        outputFileName << " on a separate line. Be careful about how many simulations you run!" << endl;
    }
    cin >> totalSimulations;

    for (index = 0; index < totalSimulations; ++index) { 
        cardDeck.shuffleDeck();
        playerHand.clear();

        for (unsigned int j = 0; j < cardsInHand; ++j) { // Putting cards into the vectors dealtCards and playerHand
            playerHand.push_back(cardDeck.dealCard());
        }

        if (hasPair(playerHand)) {
            if (response == "Yes" || response == "yes") {
                fileStream << "Found Pair!! ";
                fileStream << playerHand << endl;
            }
            totalPairs++;
        }
        else {
            if (response == "Yes" || response == "yes") {
                fileStream << "             " << playerHand << endl;
            }
        }
    }

    pairChance = totalPairs / totalSimulations * 100.0;

    cout << "Chances of receiving a pair in a hand of " << cardsInHand << " cards is: " << pairChance << "%" << endl;

    if (hasPair(playerHand)) {
        fileStream << "Chances of receiving a pair in a hand of " << cardsInHand << " cards is: " << pairChance << "%" << endl;
    }

    return 0;
}


bool hasPair(const vector<Card> &playerHand) {
    for (unsigned int i = 0; i < playerHand.size(); ++i) {
        for (unsigned int j = i + 1; j < playerHand.size(); ++j) {
            if (playerHand[i].getRank() == playerHand[j].getRank()) {
                return true;
            }
        }
    }
    return false;
}

ostream & operator<<(ostream &fileStream, const vector<Card> &playerHand){
    for (unsigned int i = 0; i < playerHand.size(); ++i){
        fileStream << playerHand[i] << ", ";
    }
    fileStream << playerHand.back();
    return fileStream;
}*/