// CSCE 3301 - Algorithms and Data Structures
// Sorting.h
// Sorting
//
// Created by Gabriel Torres on 11/1/22.

#ifndef SORTING_SORTING_H
#define SORTING_SORTING_H


class Sorting {
private:
    // Initialize max size of sortingArray
    const static int MAX = 22;
    int sortingArray[MAX];
    int size;

public:
    Sorting(int *dataArray, int n) {
        size = n;
        for (int i = 0; i < n; i++) {
            sortingArray[i] = dataArray[i];
        }
    };
    ~Sorting(void) { std::cout << "\nSorting class has been deconstructed.\n"; };

    void bubbleSort(int n) {
        for (int i=0;i<n-1;i++){
            for(int j=0; j<n-i-1;j++){
                if (sortingArray[j] > sortingArray[j+1])
                    swap(sortingArray[j], sortingArray[j+1]);
            }
        }
    };

    int *sortedArray(){
        return sortingArray;
    }

    void printSortedArray() {
        for (int i = 0; i < size; i++) {
            std::cout << sortingArray[i] << " ";
        }
        std::cout << std::endl;
    }

};


#endif //SORTING_SORTING_H
