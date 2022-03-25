#include "Ford.hpp"
#include "WeatherCondition.hpp"

Ford::Ford() {
    this->fuel_capacity = 60;
    this->fuel_consumption = 9;
    this->average_speed[Weather::Snow] = 45;
    this->average_speed[Weather::Rain] = 60;
    this->average_speed[Weather::Sunny] = 90;
    
    this->current_episode = 0;
    this->elapsed_distance = 0;
    this->current_status = CarStatus::Running;
};

int Ford::GetRemainingFuel() {
    return this->fuel_capacity;
}

int Ford::GetCurrentSpeed(Weather weather) {
    return this->average_speed[weather];
}

void Ford::RunEpisode(Weather weather, int track_distance) {
    if(this->current_status != CarStatus::Running) return;
    
    this->current_episode++;
    
    // Add various technical problems to differentiate the car classes
    bool engine_failure = (rand() % 100) < 9;
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

CarStatus Ford::GetStatus() {
    return current_status;
}

const char* Ford::GetName() { return "Ford"; }
