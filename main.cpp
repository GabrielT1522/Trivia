#include <iostream>
#include "Trivia.h"

using namespace std;

int main() {
    cout << "Welcome to Trivia!" << endl;
    // Insert rules and stuff here

    Trivia trivia;
    trivia.setNumOfPlayers();
    trivia.setPlayers();

    trivia.showBoard();
    trivia.queuePlayers();
    trivia.gameSequence();


    return 0;
}
