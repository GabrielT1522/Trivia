// CSCE 3301 - Algorithms and Data Structures
// Trivia.h
// Trivia
//
// Created by Gabriel Torres on 11/20/22.
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <random>
#include <algorithm>

#include "Question.h"
#include "Player.h"
#include "Data Structures and Algorithms/Map.h"
#include "Data Structures and Algorithms/Deque.h"
#include "Data Structures and Algorithms/Sorting.h"
#include "Data Structures and Algorithms/UnsortedPQ.h"

#ifndef TRIVIA_TRIVIA_H
#define TRIVIA_TRIVIA_H

using namespace std;

class Trivia {
private:
    int numOfPlayers{};
    int diceResult[5];
    vector<Question*> questionVector;
    vector<Player*> playerVector;
    Map<string, string> board;
    Deque<Player*> playerQueue;
    UnsortedPQ<Player* , int> playerPQ;

public:
    Trivia(){
        string category;
        string question;
        string answer1, answer2, answer3, answer4;
        char answerIndex;
        int pointsWorth;

        ifstream inFile("/Users/gabrieltorres/CLionProjects/Trivia/trivia.txt");
        string line;
        while (getline(inFile, line)){
            category = line;
            istringstream str(line);

            if (!getline(inFile, line) )
                break;
            question = line;

            if (!std::getline(inFile, line) )
                break;
            answer1 = line;

            if (!getline(inFile, line) )
                break;
            answer2 = line;

            if (!getline(inFile, line) )
                break;
            answer3 = line;

            if (!getline(inFile, line) )
                break;
            answer4 = line;

            if (!getline(inFile, line) )
                break;
            answerIndex = line[0];

            if (!getline(inFile, line) )
                break;
            pointsWorth = stoi(line);

            auto *questions = new Question(category, question, answer1, answer2, answer3, answer4, answerIndex, pointsWorth);
            questionVector.push_back(questions);
            board.put(category, question);

        }
        inFile.close();
    };

    void setPlayers(){
        string name;
        rollDice();
        cout << endl;
        for (int i=0;i<getNumOfPlayers();i++){
            cout << "Enter the name for Player " << i+1 << ": ";
            cin >> name;
            auto *players = new Player(name);
            players->setOrder(diceResult[i]);
            cout << "Your dice rolled a " << players->getOrder() << endl << endl;
            playerVector.push_back(players);
        }
    };

    void setNumOfPlayers(){
        int players;
        bool approved;
        do{
            cout << "Enter the number of players to begin: ";
            cin >> players;
            if (players == 2 || players == 3 || players == 4){
                approved = true;
                numOfPlayers = players;
            }else{
                cout << "There should only be either 2, 3, or 4 players.\n";
                approved = false;
            }
        }while(!approved);
    };

    void queuePlayers(){
        Sorting sorting(diceResult, getNumOfPlayers());
        sorting.bubbleSort(getNumOfPlayers());
        int *sortedArray = sorting.sortedArray();
        for(int i=0;i<getNumOfPlayers();i++) {
            for(int j=0;j<getNumOfPlayers();j++){
               if (playerVector.at(i)->getOrder()==*(sortedArray + j)) {
                   playerQueue.insertFirst(playerVector.at(j));
                   playerPQ.insertItem(playerVector.at(j), 0);
               }
            }
        }
    }

    void gameSequence(){
        char d{};
        string key;
        while(d!='y'){
            cout << "\nIt is " << playerQueue.first()->getName() << "'s turn!"<< endl;
            showBoard();

            bool verify;
            do {
                cout << "\nPlease enter a question key: ";
                cin >> key;
                if (!board.exists(key)) {
                    cout << "The key '" << key << "' was not found, please re-enter an appropriate key.\n";
                    verify = false;
                }else
                    verify = true;
            }while(!verify);

            for (Question *question : questionVector){
                if(question->getCateogry()==key){
                    cout << "\n" << board.value(key);
                    question->printQuestion();
                    char answer;
                    cout << "Please enter your answer as a single lower-case letter: ";
                    cin >> answer;
                    if(question->isCorrect(answer)){
                        playerQueue.first()->setMoney(question->getPointsWorth());
                        playerPQ.updateElement(playerQueue.first(), playerQueue.first()->getMoney());
                    }
                }
            }
            showLeaderboard();

            board.remove(key);
            playerQueue.insertLast(playerQueue.first());
            playerQueue.removeFirst();

            if (winner()){
                break;
            }

            cout << "\nWould you like to exit the game?\n";
            cout << "Enter y to exit. Enter any other key to continue: ";
            cin >> d;
        }
    }

    bool winner(){
        if (playerPQ.maxValue() >= 1200 || board.isEmpty()){
            cout << "\nCongratulations! " << playerPQ.getKey()->getName() << " has won with $" << playerPQ.getKey()->getMoney() << "!";
            return true;
        }
        return false;
    }

    int getNumOfPlayers(){
        return numOfPlayers;
    }

    void rollDice(){
        vector<int> result;
        random_device rd; // obtain a random number from hardware
        mt19937 eng(rd()); // seed the generator
        uniform_int_distribution<> distr(1, 6); // define the range

        int i = 0;
        while(i < getNumOfPlayers()) { // loop until all players are assigned a number
            int randVal = distr(eng);
            if(std::find(std::begin(result),std::end(result),randVal) == std::end(result)) {
                result.push_back(randVal);
                diceResult[i] = result.at(i);
                ++i;
            }
        }
    }
    void showLeaderboard(){
        cout << "\n| Leaderboard |\n";
        for (Player *players : playerVector){
            cout << "| " << players->getName() << ": $" << players->getMoney() << " | ";
        }
    };

    void showBoard(){
        cout << "| Trivia Board |\n";
        cout << "| Category A: Music\n| Category B: Animals\n| Category C: Technology\n| ";
        for(int i=0;i<board.size();i++) {
            cout << board.getMapListKey(i) << " | ";
        }
    }

};


#endif //TRIVIA_TRIVIA_H
