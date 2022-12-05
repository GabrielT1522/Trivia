// CSCE 3301 - Algorithms and Data Structures
// main.cpp
// Trivia
//
// Created by Gabriel Torres on 11/20/22.
#include <iostream>
#include "Trivia.h"

using namespace std;

int main() {
    cout << "Welcome to Trivia!\n";
    cout << "The rules are simple:\n";
    cout << "1. Set up the game by entering the amount of players (2-4).\n";
    cout << "\t- A dice roll will determine the order of players (largest to smallest dice roll).\n";
    cout << "2. Choose a question based on the category (A1, C3, etc.).\n";
    cout << "3. The first player who earns $1200 or the player with the most money once the board is empty wins.\n";

    Trivia trivia;
    trivia.setNumOfPlayers();
    trivia.setPlayers();
    trivia.queuePlayers();
    trivia.gameSequence();
    cout << "\n\n\n\nThank you for playing!\n";

    return 0;
}
