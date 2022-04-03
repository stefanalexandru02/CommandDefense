#include <iostream>

using namespace std;

float operator"" _Kelvin(const char *f)
{
    return atof(f) + 273.15;
};

float operator"" _Fahrenheit(const char *f)
{
    return (atof(f) * 1.8) + 32;
};

int main() {
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;
    std::cout<<"300 C in Kelvin is "<<a<<std::endl;
    std::cout<<"120 C in Fahrenheit is "<<b<<std::endl;
    return 0;
}
