// CSCE 3301 - Algorithms and Data Structures
// Question.h
// Trivia
//
// Created by Gabriel Torres on 11/20/22.
#ifndef TRIVIA_QUESTION_H
#define TRIVIA_QUESTION_H

#include <iostream>
using namespace std;

class Question {
private:
    string category;
    string question;
    string answer1, answer2, answer3, answer4;
    char answerIndex;
    int pointsWorth;
public:
    Question(string c, string q, string a1, string a2, string a3, string a4, char aI, int pW){
        category = c;
        question = q;
        answer1 = a1;
        answer2 = a2;
        answer3 = a3;
        answer4 = a4;
        answerIndex = aI;
        pointsWorth = pW;
    };
    void printQuestion(){
        cout << "\n(This question is worth $" << pointsWorth << ")" <<endl;
        cout << "a. " << answer1 << endl;
        cout << "b. " << answer2 << endl;
        cout << "c. " << answer3 << endl;
        cout << "d. " << answer4 << endl;
    }

    void correctAnswer(){
        cout << "The correct answer was: ";
        switch(answerIndex){
            case 'a':
                cout << "a. " << answer1 << endl;
                break;
            case 'b':
                cout << "b. " << answer2 << endl;
                break;
            case 'c':
                cout << "c. " << answer3 << endl;
                break;
            case 'd':
                cout << "a. " << answer4 << endl;
                break;
            default:
                break;
        }
    }

    bool isCorrect(char a){
        if (a == answerIndex){
            cout << "You are correct! You have gained $" << pointsWorth << "!\n";
            return true;
        }else {
            cout << "WRONG! You gain nothing!\n";
            correctAnswer();
            return false;
        }
    }
    string getCateogry(){
        return category;
    }
    int getPointsWorth(){
        return pointsWorth;
    }
};


#endif //TRIVIA_QUESTION_H
