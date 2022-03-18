//
//  main.cpp
//  tema4
//
//  Created by Stefan Alexandru on 18.03.2022.
//

#include <iostream>
#include "Sort.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    Sort s(10, 1, 2, 99, 4, 5, 6, 7, 8, 9, 10);
    s.BubbleSort(false);
    s.Print();
    s.InsertSort(true);
    s.Print();
    return 0;
}
