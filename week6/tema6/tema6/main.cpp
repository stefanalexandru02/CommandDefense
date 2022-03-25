#include <iostream>
#include "Car.hpp"
#include "WeatherCondition.hpp"
#include "Circuit.hpp"
#include "Dacia.hpp"
#include "Toyota.hpp"
#include "Mercedes.hpp"
#include "Ford.hpp"
#include "Mazda.hpp"

int main(int argc, const char * argv[]) {
    Circuit c;
    c.SetLength(100);
    c.SetWeather(Weather::Rain);
    c.AddCar(new Dacia());
    c.AddCar(new Toyota());
    c.AddCar(new Mercedes());
    c.AddCar(new Ford());
    c.AddCar(new Mazda());
    c.Race();
    c.ShowFinalRanks(); // it will print the time each car needed to finish the circuit sorted from the fastest car to the slowest.
    c.ShowWhoDidNotFinish(); // it is possible that some cars don't have enough fuel to finish the circuit
    return 0;
}
