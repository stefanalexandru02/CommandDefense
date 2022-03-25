#include "Mazda.hpp"
#include "WeatherCondition.hpp"

Mazda::Mazda() {
    this->fuel_capacity = 15;
    this->fuel_consumption = 5;
    this->average_speed[Weather::Snow] = 25;
    this->average_speed[Weather::Rain] = 33;
    this->average_speed[Weather::Sunny] = 90;
    
    this->current_episode = 0;
    this->elapsed_distance = 0;
    this->current_status = CarStatus::Running;
};

int Mazda::GetRemainingFuel() {
    return this->fuel_capacity;
}

int Mazda::GetCurrentSpeed(Weather weather) {
    return this->average_speed[weather];
}

void Mazda::RunEpisode(Weather weather, int track_distance) {
    if(this->current_status != CarStatus::Running) return;
    
    this->current_episode++;
    
    // Add various technical problems to differentiate the car classes
    bool engine_failure = (rand() % 100) < 15;
    if(engine_failure) { return; }
    
    this->fuel_capacity -= this->fuel_consumption;
    if(this->fuel_capacity >= 0)
        this->elapsed_distance += GetCurrentSpeed(weather);
    else
        this->elapsed_distance += (GetCurrentSpeed(weather) * this->fuel_capacity * (-1) / this->fuel_consumption);
    if(this->fuel_capacity <= 0)
        this->current_status = CarStatus::OutOfFuel;
    if(this->elapsed_distance >= track_distance)
        this->current_status = CarStatus::CompletedRace;
}

CarStatus Mazda::GetStatus() {
    return current_status;
}

const char* Mazda::GetName() { return "Mazda"; }
