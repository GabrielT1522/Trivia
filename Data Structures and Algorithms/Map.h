//C SCE 3301 - Algorithms and Data Structures
// Map.h
// Map
//
// Created by Gabriel Torres on 11/18/22.

#ifndef MAP_H
#define MAP_H
#include <iostream>
#include <vector>
using namespace std;

template <class keyType, class valueType> class Entry {
private:
    keyType key;
    valueType value;

public:
    Entry(keyType k, valueType v) {
        key = k;
        value = v;
    }
    void setKey(keyType k) { key = k; }
    void setValue(valueType v) { value = v; }
    keyType getKey() {
        return key;
    }
    valueType getValue() { return value; }
};

template <class keyType, class valueType> class Map {
private:
    vector< Entry<keyType, valueType> >mapList;
    int count;

public:
    Map() {
        count = 0;
    };
    // Performs an insertion of "n" items from dataArray
    // into the priority queue
    Map(string *dataArray, int n) {
        count = 0;
        for (int i = 0; i < n; i++) {
            put(dataArray[i], "t");
        }
    };
    ~Map() { cout << "\nMap has been deconstructed.\n"; };
    bool isEmpty() {
        if (size() == 0)
            return true;
        else
            return false;
    };
    int size() { return count; };

    void put(keyType key, valueType value) {

        // Entry with the same key exists.
        // Update new value
        for (Entry<keyType, valueType> entry : mapList) {
            if (entry.getKey() == key) {
                entry.setValue(value);
                return;
            }
        }

        // Entry with the same key does not exist.
        // Create a new entry
        mapList.push_back(Entry<keyType, valueType>(key, value));
        count++;
    };

    void changeKey(keyType key, keyType newKey) {
        for (Entry<keyType, valueType> entry : mapList) {
            if (entry.getKey() == key) {
                entry.setKey(newKey);
                return;
            }
        }
    };

    void remove(keyType key){
        if(isEmpty()){
            cout << "The map is empty.\n";
            return;
        }
        int itr = 0;
        for (Entry<keyType, valueType> entry : mapList) {
            if (entry.getKey() == key) {
                mapList.erase(mapList.begin()+itr);
                count--;
                return;
            }
            itr++;
        }
    };

    keyType key(keyType key, valueType value) {
        for (Entry<keyType, valueType> entry : mapList) {
            if (entry.getValue() == value) {
                return entry.getKey();
            }
        }
        return NULL;
    };

    valueType value(keyType key, valueType value) {
        for (Entry<keyType, valueType> entry : mapList) {
            if (entry.getKey() == key) {
                return entry.getValue();
            }
        }
        return NULL;
    };

    keyType getMapListKey(int i){
        return mapList.at(i).getKey();
    }

    void printMap(){
        if(isEmpty()){
            cout << "The map is empty.\n";
            return;
        }
        int itr = 0;
        for (Entry<keyType, valueType> entry : mapList) {
            cout << "\nEntry " << itr << ":"<< endl;
            cout << "Key: " << entry.getKey() << endl;
            cout << "Value: " << entry.getValue() << endl;
            itr++;
        }
    };
};
#endif