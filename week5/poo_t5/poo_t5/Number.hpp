#ifndef Number_hpp
#define Number_hpp

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <stdexcept>

class Number
{
private:
    char *value;
    unsigned long value_size;
    int base = 10;
    
    static int toBase10(const char* value, int base);
    static const char* fromBase10(int inputNum, int base);
    static int getNumericVal(const char c);
    static char getCharacterValue(int num);
    
public:
    Number(const char * value, int base); // where base is between 2 and 16
    Number(const char * value);
    Number(int value);
    ~Number();
    
    char& operator[](int);
    Number& operator--();
    Number& operator--(int);
    
    Number& operator+=(const Number& second);
    friend Number operator+(Number first,
                       const Number& second)
    {
      first += second;
      return first;
    }
    
    Number& operator-=(const Number& second);
    friend Number operator-(Number first,
                       const Number& second)
    {
      first -= second;
      return first;
    }
    
    Number& operator=(const Number& other);
    
    friend bool operator < (Number const& lhs, Number const& rhs)
    {
        int num1 = toBase10(lhs.value, lhs.base);
        int num2 = toBase10(rhs.value, rhs.base);
        return num1 < num2;
    }
    friend bool operator > (Number const& lhs, Number const& rhs)
    {
        int num1 = toBase10(lhs.value, lhs.base);
        int num2 = toBase10(rhs.value, rhs.base);
        return num1 > num2;
    }
    friend bool operator <= (Number const& lhs, Number const& rhs)
    {
        int num1 = toBase10(lhs.value, lhs.base);
        int num2 = toBase10(rhs.value, rhs.base);
        return num1 <= num2;
    }
    friend bool operator >= (Number const& lhs, Number const& rhs)
    {
        int num1 = toBase10(lhs.value, lhs.base);
        int num2 = toBase10(rhs.value, rhs.base);
        return num1 >= num2;
    }
    friend bool operator == (Number const& lhs, Number const& rhs)
    {
        int num1 = toBase10(lhs.value, lhs.base);
        int num2 = toBase10(rhs.value, rhs.base);
        return num1 == num2 && lhs.base == rhs.base;
    }
    friend bool operator != (Number const& lhs, Number const& rhs)
    {
        int num1 = toBase10(lhs.value, lhs.base);
        int num2 = toBase10(rhs.value, rhs.base);
        return !(num1 == num2 && lhs.base == rhs.base);
    }

    void SwitchBase(int newBase);
    void Print();
    int  GetDigitsCount(); // returns the number of digits for the current number
    int  GetBase(); // returns the current base
};

#endif /* Number_hpp */
