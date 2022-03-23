#include <iostream>

using namespace std;

class MyNumber
{
    int x;

  public:
    int GetX() const { return x; }
    MyNumber(int value) : x(value) {}        
    operator float()
    {
        return (float) this->x;
    }
    MyNumber operator++()
    {
        x++;
        return *this;
    }
    MyNumber operator ++(int)
    {
        MyNumber copy = *this;
        ++(*this);
        return copy;
    }

    MyNumber& Set(int value)
    {
        x = value;
        return *this;
    }
    MyNumber& Add(int value)
    {
        this->x += value;
        return *this;
    }
    void Print()
    {
        cout << this->x << endl;
    }

    int operator[](int index)
    {
        return (x >> (index - 1)) & 1;
    }

    MyNumber& operator=(int value)
    {
        x = value;
        return *this;
    }

    void operator()()
    {
        Print();
    }
};

MyNumber operator+(const MyNumber& stg, const MyNumber& drp)
{
    return { stg.GetX() + drp.GetX() };
}
MyNumber operator+(const int stg, const MyNumber& drp)
{
    return MyNumber(stg) + drp;
}
bool operator==(const MyNumber& stg, const MyNumber& drp)
{
    return stg.GetX() == drp.GetX();
}
bool operator!=(const MyNumber& stg, const MyNumber& drp)
{
    return !(stg == drp);
}
MyNumber& operator+=(MyNumber& stg, const int value)
{
    stg.Set(stg.GetX() + value); return stg;
}

int main()
{
    MyNumber x1(10);
    MyNumber x2(20);

    MyNumber x3 = x1 + x2;

    int my_sum = 20 + x2;   

    float value = x1;

    x1.Set(10).Add(2).Add(2).Print();

    x1();

    (x1 += 10) += 30;

    return 0;
}