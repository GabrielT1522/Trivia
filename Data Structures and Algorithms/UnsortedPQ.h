// CSCE 3301 - Algorithms and Data Structures
// UnsortedPQ.h
// Priority Queues and Heaps
//
// Created by Gabriel Torres on 10/14/22.

#ifndef UNSORTEDPQ_H
#define UNSORTEDPQ_H
#include <exception>
#include <iostream>
using namespace std;

// Define PQNode Class
template <class Type> struct PQNode {
public:
    PQNode *next, *prev;
    Type element;
};

template <class Type> class UnsortedPQ {
private:
    PQNode<Type> *front, *rear;
  int count;

public:
  UnsortedPQ(void) {
    count = 0;
    front = NULL;
    rear = NULL;
  };
  // Performs an insertion of "n" items from dataArray
  // into the priority queue
  UnsortedPQ(Type *dataArray, int n) {
    count = 0;
    front = NULL;
    rear = NULL;
    for (int i = 0; i < n; i++) {
      insertItem(dataArray[i]);
    }
  };
  ~UnsortedPQ(void) {
    cout << "\nUnsorted Priority Queue has been deconstructed.\n";
  };
  bool isEmpty() {
    if (size() == 0)
      return true;
    else
      return false;
  };
  int size() { return count; };
  // inserts a piece of data into the priority queue
  void insertItem(Type data) {
    auto *newNode = new PQNode<Type>();
    newNode->element = data;
    if (front == NULL) {
      front = rear = newNode;
    } else {
      newNode->next = front;
      front->prev = newNode;
      front = newNode;
    }
    count++;
  };
  // removes and returns the minimum value in the queue
  // throws an exception if the queue is empty
  Type removeMin(void){

    if (isEmpty()) {
      cout << "Prority Queue is Empty.";
      return 0;
    }

    Type min = 100;
    auto *itr = front;
    auto *tmp = itr;
    while (itr != NULL) {
      if (min > itr->element) {
        min = itr->element;
        tmp = itr;
      }
      itr = itr->next;
    }

    if (tmp->element == min) {
      if (front == rear) {
        front == rear == NULL;
      } else if (tmp->prev == NULL) {
        front = front->next;
        front->prev = NULL;
      } else if (tmp->next == NULL) {
        rear = rear->prev;
        rear->next = NULL;
      } else {
        (tmp->next)->prev = tmp->prev;
        (tmp->prev)->next = tmp->next;
        free(tmp);
      }
      count--;
    }

    return min;
  };

  // return the minimum value in the queue without removing it
  // throws an exception if the queue is empty
  Type minValue(void){

    if (isEmpty()) {
      cout << "Prority Queue is Empty.\n";
      return 0;
    }

    Type min = 100;
    auto *itr = front;

    while (itr != NULL) {
      if (min > itr->element) {
        min = itr->element;
      }
      itr = itr->next;
    }
    return min;
  };

  void printUnsortedPQ() {
    if (isEmpty()) {
      cout << "Prority Queue is Empty.\n";
      return;
    }
    auto *itr = front;
    while (itr != NULL) {
      cout << itr->element << " ";
      itr = itr->next;
    }
    cout << endl;
  }
};
#endif