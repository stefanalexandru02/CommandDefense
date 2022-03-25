#ifndef Mazda_hpp
#define Mazda_hpp

#include "Car.hpp"
#include <stdio.h>

class Mazda : public Car
{
private:
    virtual int GetRemainingFuel();    
    virtual int GetCurrentSpeed(Weather weather);
public:
    Mazda();
    virtual void RunEpisode(Weather weather, int track_distance);
    virtual CarStatus GetStatus();
    virtual const char* GetName();
    virtual int GetAverageSpeed(Weather weather) { return average_speed[weather]; }
    virtual int GetCurrentEpisode() {return current_episode; }
    virtual int GetElapsedDistance() {return elapsed_distance; }
};

#endif
