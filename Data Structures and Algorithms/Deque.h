// CSCE 3301 - Algorithms and Data Structures
// Deque.h
// Deques and Doubly Linked Lists
//
// Created by Gabriel Torres on 9/23/22.

// Define Node Class
template <class Type> class Node {
public:
    Node *prev, *next;
    Type element;

    Node(Type o){
        element = o;
        next = nullptr;
        prev = nullptr;
    }
};

#ifndef DEQUE_H
#define DEQUE_H
#include <iostream>
using namespace std;

template <class Type>
class Deque {
private:
    Node<Type> *front, *rear;
    int count;

public:
    Deque(){
        count = 0;
        front = NULL;
        rear = NULL;
    };
    ~Deque() = default;;
    bool isEmpty() {
        if (size() == 0) {
            return true;
        } else {
            return false;
        }
    };
    int size() { return count; };
    Type first(){
        if (isEmpty()) {
            cout << "Deque is empty\n";
        } else {
            return front->element;
        }
    };
    Type last(){
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return -1;
        } else {
            return rear->element;
        }
    };
    void insertFirst(Type o){
        auto *newNode = new Node<Type>(o);
        if (front == NULL){
            front = newNode;
            rear = newNode;
        }else{
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        count++;

    };
    void insertLast(Type o){
        auto *newNode = new Node<Type>(o);
        if (rear == NULL){
            front = newNode;
            rear = newNode;
        }else{
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }
        count++;

    };
    Type removeFirst(){
        if (isEmpty()){
            cout << "Deque is empty.\n";
        }else{
            auto *tempNode = front;
            front = front->next;
            if (front == NULL) {
                rear = NULL;
            }else {
                front->prev = NULL;
            }
            free(tempNode);
            count--;
        }
        return front->element;
    };
    Type removeLast() {
        if (isEmpty()){
            cout << "Deque is empty.\n";
        }else{
            auto *tempNode = rear;
            rear = rear->prev;
            if (rear == NULL) {
                front = NULL;
            }else {
                rear->next = NULL;
            }
            free(tempNode);
            count--;
        }
        return rear->element;
    };
};
#endif
