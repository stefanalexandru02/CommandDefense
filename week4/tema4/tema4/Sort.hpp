//
//  Sort.hpp
//  tema4
//
//  Created by Stefan Alexandru on 18.03.2022.
//

#ifndef Sort_hpp
#define Sort_hpp

#include <stdio.h>

using namespace std;

class Sort
{
private:
    int count;
    int* list;
    int min;
    int max;
    
    void swap(int *xp, int *yp);
    int partition (int *arr, int low, int high);
    void quickSort(int *arr, int low, int high, bool ascendant);
public:
    Sort(int number_of_elements, int min, int max);
    Sort(Sort *initialList);
    Sort(int *vector, int n);
    Sort(int n, ...);
    Sort(char* text);
    
    void InsertSort(bool ascendent=false);
    void QuickSort(bool ascendent=false);
    void BubbleSort(bool ascendent=false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};

#endif /* Sort_hpp */
