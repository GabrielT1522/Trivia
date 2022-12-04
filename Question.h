//
// Created by Gabriel Torres on 12/3/22.
//

#ifndef TRIVIA_QUESTION_H
#define TRIVIA_QUESTION_H

#include <iostream>
using namespace std;

class Question {
private:
    string category;
    string question;
    string answer1, answer2, answer3, answer4;
    int answerIndex;
    int pointsWorth;
public:
    Question(string c, string q, string a1, string a2, string a3, string a4, int aI, int pW){
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
        cout << "This question is worth $" << pointsWorth << endl;
        cout << question << endl;
        cout << "a. " << answer1 << endl;
        cout << "b. " << answer2 << endl;
        cout << "c. " << answer3 << endl;
        cout << "d. " << answer4 << endl;
    }

    void correctAnswer(){
        cout << "The correct answer is: ";
        switch(answerIndex){
            case 1:
                cout << "a. " << answer1 << endl;
                break;
            case 2:
                cout << "b. " << answer2 << endl;
                break;
            case 3:
                cout << "c. " << answer3 << endl;
                break;
            case 4:
                cout << "a. " << answer4 << endl;
                break;
            default:
                break;
        }
    }
};


#endif //TRIVIA_QUESTION_H
