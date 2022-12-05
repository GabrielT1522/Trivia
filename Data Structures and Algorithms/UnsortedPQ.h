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
template <class keyType, class elementType> struct PQNode {
public:
    PQNode *next, *prev;
    keyType key;
    elementType element;
};

template <class keyType, class elementType> class UnsortedPQ {
private:
    PQNode<keyType, elementType> *front, *rear;
    int count;

public:
  UnsortedPQ(void) {
    count = 0;
    front = NULL;
    rear = NULL;
  };
  // Performs an insertion of "n" items from dataArray
  // into the priority queue
  UnsortedPQ(int *dataArray, int n) {
    count = 0;
    front = NULL;
    rear = NULL;
    for (int i = 0; i < n; i++) {
      insertItem(dataArray[i]);
    }
  };
  ~UnsortedPQ() = default;;
  bool isEmpty() {
    if (size() == 0)
      return true;
    else
      return false;
  };
  int size() { return count; };
  // inserts a piece of data into the priority queue
  void insertItem(keyType key, elementType element) {
    auto *newNode = new PQNode<keyType, elementType>();
    newNode->key = key;
    newNode->element = element;
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
  keyType removeMin(void){

    if (isEmpty()) {
      cout << "Prority Queue is Empty.";
      return 0;
    }

    int min = 100;
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
  keyType minValue(void){

    if (isEmpty()) {
      cout << "Prority Queue is Empty.\n";
      return 0;
    }

    int min = 100;
    auto *itr = front;

    while (itr != NULL) {
      if (min > itr->element) {
        min = itr->element;
      }
      itr = itr->next;
    }
    return min;
  };

    int maxValue(){
        if (isEmpty()) {
            cout << "Prority Queue is Empty.\n";
            return 0;
        }
        int max = 0;
        auto *itr = front;
        while (itr != NULL) {
            if (max < itr->element) {
                max = itr->element;
            }
            itr = itr->next;
        }
        return max;
    };

    void updateElement(keyType k, int v){
        if (isEmpty()) {
            cout << "Prority Queue is Empty.\n";
            return;
        }
        auto *itr = front;
        while (itr != NULL) {
            if(k==itr->key){
                itr->element = v;
            }
            itr = itr->next;
        }
    };

    keyType getKey(){
        auto *itr = front;
        while (itr != NULL) {
            if(maxValue()==itr->element){
                return itr->key;
            }
            itr = itr->next;
        }
        return NULL;
    }

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