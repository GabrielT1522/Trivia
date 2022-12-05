// CSCE 3301 - Algorithms and Data Structures
// Player.h
// Trivia
//
// Created by Gabriel Torres on 11/20/22.

#ifndef TRIVIA_PLAYER_H
#define TRIVIA_PLAYER_H

#include <iostream>
using namespace std;

class Player {
private:
    string name;
    int order;
    int money;
public:
    Player(string n){
        name = n;
        order = 0;
        money = 0;
    }
    string getName(){
        return name;
    }
    void setOrder(int o){
        order = o;
    }
    int getOrder(){
        return order;
    }
    void setMoney(int m){
        money +=m;
    }
    int getMoney(){
        return money;
    }


};


#endif //TRIVIA_PLAYER_H
