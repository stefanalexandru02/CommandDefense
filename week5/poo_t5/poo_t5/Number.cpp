#include "Number.hpp"

Number::Number(const char * value, int base)
{
    if(base >= 2 && base <= 16)
    {
        this->base = base;
        this->value_size = 10000;
        //this->value = new char[this->value_size];
        this->value = (char*)malloc(sizeof(char) * this->value_size);
        strcpy(this->value, value);
    }
    else
    {
        throw std::runtime_error("Base must be between 2 and 16");
    }
}

Number::Number(const char* value)
{
    this->value_size = 10000;
    this->value = (char*)malloc(sizeof(char) * this->value_size);
    strcpy(this->value, value);
}

Number::Number(int value)
{
    this->value_size = 10000;
    this->value = new char[this->value_size];
    strcpy(this->value, fromBase10(value, this->base));
}

Number::~Number()
{
    this->value_size = 0;
}

char& Number::operator[](int index) { return this->value[index]; }
Number& Number::operator+=(const Number& second)
{
    int max_base = this->base;
    if(second.base  > max_base)
        max_base = second.base;
    int num1 = toBase10(this->value, this->base);
    int num2 = toBase10(second.value, second.base);
    int sum = num1 + num2;
    strcpy(this->value, fromBase10(sum, max_base));
    this->base = max_base;
    return *this;
}
Number& Number::operator-=(const Number& second)
{
    int max_base = this->base;
    if(second.base  > max_base)
        max_base = second.base;
    int num1 = toBase10(this->value, this->base);
    int num2 = toBase10(second.value, second.base);
    int sum = num1 - num2;
    strcpy(this->value, fromBase10(sum, max_base));
    this->base = max_base;
    return *this;
}
Number& Number::operator--()
{
    strcpy(this->value, this->value+1);
    return *this;
}
Number& Number::operator--(int)
{
    this->value[strlen(this->value) - 1] = '\0';
    return *this;
}

Number& Number::operator=(const Number& other)
{
    this->value = other.value;
    this->base = other.base;
    return *this;
}

void Number::SwitchBase(int newBase)
{
    strcpy(this->value, fromBase10(toBase10(this->value, this->base), newBase));
    this->base = newBase;
}

void Number::Print() { std::cout<<this->value<<std::endl; }

int Number::GetDigitsCount() { return (int)strlen(this->value); }

int Number::GetBase() { return base; }

int Number::toBase10(const char* value, int base)
{
    int len = (int)strlen(value);
    int power = 1;
    int num = 0;
    
    for (int i = len - 1; i >= 0; i--)
    {
        if (getNumericVal(value[i]) >= base) {
            throw std::runtime_error("The input number is invalid.");
            return -1;
        }
        num += getNumericVal(value[i]) * power;
        power = power * base;
    }
    return num;
}

const char* Number::fromBase10(int inputNum, int base)
{
    std::string res = "";
    while (inputNum > 0)
    {
        res += getCharacterValue(inputNum % base);
        inputNum /= base;
    }
    reverse(res.begin(), res.end());
    return res.c_str();
}

int Number::getNumericVal(const char c)
{
    if (c >= '0' && c <= '9')
        return (int)c - '0';
    else
        return (int)c - 'A' + 10;
}

char Number::getCharacterValue(int num)
{
    if (num >= 0 && num <= 9)
        return (char)(num + '0');
    else
        return (char)(num - 10 + 'A');
}
