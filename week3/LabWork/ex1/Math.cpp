//
//  Math.cpp
//  w3
//
//  Created by Stefan Alexandru on 12.03.2022.
//

#include "Math.hpp"

int Math::Add(int num1, int num2)
{
    return num1 + num2;
}

int Math::Add(int num1, int num2, int num3)
{
    return num1 + num2 + num3;
}

int Math::Add(double num1, double num2)
{
    return (int)(num1 + num2);
}

int Math::Add(double num1, double num2, double num3)
{
    return (int)(num1 + num2 + num3);
}

int Math::Mul(int num1, int num2)
{
    return num1 * num2;
}

int Math::Mul(int num1, int num2, int num3)
{
    return num1 * num2 * num3;
}

int Math::Mul(double num1, double num2)
{
    return (int)(num1 * num2);
}

int Math::Mul(double num1, double num2, double num3)
{
    return (int)(num1 * num2 * num3);
}

int Math::Add(int count,...) {
    va_list valist;
    double sum = 0.0;
    int i;
    va_start(valist, count); //initialize valist for num number of arguments
    for (i = 0; i < count; i++) { //access all the arguments assigned to valist
       sum += va_arg(valist, int);
    }
    va_end(valist); //clean memory reserved for valist
    return sum;
}

char* Math::Add(const char *str1, const char *str2)
{
    if (str1 == nullptr || str2 == nullptr) return nullptr;
    int size1 = strlen(str1);
    int size2 = strlen(str2);
    Allocator alloc(500);
    char* full_str = alloc.alloc(str1, str2);
    full_str[size1 + size2] = 0;
    return full_str;
}
