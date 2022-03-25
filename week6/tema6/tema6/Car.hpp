#ifndef Car_h
#define Car_h
#include <stdlib.h>
#include "WeatherCondition.hpp"

enum CarStatus
{
    Running,
    CompletedRace,
    OutOfFuel
};

class Car
{
private:
    // In mod normal ar trebui implementate in baza,
    // dar le voi implementa in clasele aferent deoarece
    // asa specifica cerinta
    
    // Completate deoarece o implementare de tip placeholder este
    // necesara pentru compilare
    virtual int GetRemainingFuel() { return fuel_capacity; }
    virtual int GetCurrentSpeed(Weather weather) {return average_speed[weather]; }
protected:
    int fuel_capacity;
    int fuel_consumption;
    int average_speed[3];
    
    // The current episode of the car
    int current_episode = 0;
    int elapsed_distance = 0;
    CarStatus current_status = CarStatus::Running;
public:
    virtual void RunEpisode(Weather weather, int track_distance) { }
    virtual CarStatus GetStatus() { return current_status; }
    virtual const char* GetName() { return "Car"; }
    virtual int GetAverageSpeed(Weather weather) { return average_speed[0]; }
    virtual int GetCurrentEpisode() {return current_episode; }
    virtual int GetElapsedDistance() {return elapsed_distance; }
};

#endif
