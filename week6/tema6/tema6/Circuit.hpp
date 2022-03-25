#ifndef Circuit_hpp
#define Circuit_hpp

#include "Car.hpp"
#include "WeatherCondition.hpp"
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Circuit
{
private:
    int lenght;
    vector<Car*> cars;
    Weather weather;
    
public:
    ~Circuit();
    
    void SetLength(int length);
    void SetWeather(Weather weather);
    void AddCar(Car* car);
    void Race(bool print_logs=false);
    void ShowFinalRanks();
    void ShowWhoDidNotFinish();
};

#endif
