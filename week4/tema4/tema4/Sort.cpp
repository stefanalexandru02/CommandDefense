//
//  Sort.cpp
//  tema4
//
//  Created by Stefan Alexandru on 18.03.2022.
//

#include "Sort.hpp"
#include <iostream>
#include <cstdarg>
#include <sstream>
#include <string.h>

using namespace std;

Sort::Sort(int number_of_elements, int min, int max)
{
    this->count = number_of_elements;
    this->list = new int[number_of_elements];
    this->min = min;
    this->max = max;
}

Sort::Sort(Sort *initialList)
{
    this->count = initialList->count;
    this->list = initialList->list;
    this->min = initialList->min;
    this->max = initialList->max;
}

Sort::Sort(int *vector, int n)
{
    this->count = n;
    if(n > 0)
    {
        this->max = vector[0];
        this->min = vector[0];
    }
    this->list = new int[n];
    for(int i = 0; i < n; i++)
    {
        this->list[i] = vector[i];
        if(vector[i] < this->min)
            this->min = vector[i];
        if(vector[i] > this->max)
            this->max = vector[i];
    }
}

Sort::Sort(int n, ...)
{
    this->count = n;
    std::va_list args;
    va_start(args, n);
    int x;
    this->list = new int[n];
    this->min = 10000000;
    this->max = -10000000;
    for (int i = 0; i < n; i++)
    {
        x = va_arg(args, int);

        this->list[i] = x;
        if(x < this->min)
            this->min = x;
        if(x > this->max)
            this->max = x;
    }
    va_end(args);
}

Sort::Sort(char* text)
{
    unsigned long string_length = strlen(text);
    int numbers = 1;
    for(int i = 0; i < string_length; i++)
        if(text[i] == ',')
            numbers++;
    this->count = numbers;
    this->list = new int[numbers];
    this->min = 10000000;
    this->max = -10000000;
    char *p = strtok(text, ",");
    int i = 0;
    while(p!=NULL)
    {
        int num = atoi(p);
        this->list[i++] = num;
        if(num < this->min)
            this-> min = num;
        if(num > this-> max)
            this-> max = num;
        p = strtok(NULL, ",");
    }
}

void Sort::Print()
{
    for(int i = 0 ; i < this->count; i++)
    {
        cout<<this->list[i];
        if(i != this->count - 1)
            cout<<", ";
    }
    cout<<endl;
}

int Sort::GetElementsCount()
{
    return this->count;
}

int Sort::GetElementFromIndex(int index)
{
    return this->list[index];
}

void Sort::swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int Sort::partition(int *arr, int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void Sort::quickSort(int *arr, int low, int high, bool ascendant)
{
    if (ascendant ? low < high : low > high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1, ascendant);
        quickSort(arr, pi + 1, high, ascendant);
    }
}

void Sort::InsertSort(bool ascendent)
{
    int i, key, j;
    for (i = 1; i < this->count; i++)
    {
        key = this->list[i];
        j = i - 1;
        while (j >= 0 && (ascendent ? this->list[j] > key : this->list[j] < key))
        {
            this->list[j + 1] = this->list[j];
            j = j - 1;
        }
        this->list[j + 1] = key;
    }
}

void Sort::QuickSort(bool ascendent)
{
    quickSort(this->list, this->min, this->max, ascendent);
}

void Sort::BubbleSort(bool ascendent)
{
    int i, j;
    for (i = 0; i < this->count-1; i++)
        for (j = 0; j < this->count-i-1; j++)
            if (ascendent ? this->list[j] > this->list[j+1] : this->list[j] < this->list[j+1])
                swap(&this->list[j], &this->list[j+1]);
}
