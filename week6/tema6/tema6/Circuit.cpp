#include "Circuit.hpp"
#include "Car.hpp"

Circuit::~Circuit() { this->cars.clear(); }

void Circuit::SetLength(int length) { this->lenght = length; }

void Circuit::SetWeather(Weather weather) { this->weather = weather; }

void Circuit::AddCar(Car *car) { this->cars.push_back(car); }

void Circuit::Race(bool print_logs)
{
    bool should_run = true;
    while(should_run)
    {
        should_run = false;
        for(int i = 0; i < this->cars.size(); i++)
        {
            CarStatus status = cars[i]->GetStatus();
            if(status == CarStatus::Running)
            {
                cars[i]->RunEpisode(this->weather, this->lenght);
                status = cars[i]->GetStatus();
                if(status == CarStatus::Running)
                    should_run = true;
                else if(print_logs)
                {
                    std::cout<<cars[i]->GetName()<<" - "<<(status == CarStatus::CompletedRace ? "Completed" : "Out of fuel")<<std::endl;
                }
            }
        }
    }
}

bool comparator(Car *lhs, Car *rhs) {
    return lhs->GetCurrentEpisode() < rhs->GetCurrentEpisode();
}

void Circuit::ShowFinalRanks()
{
    sort(this->cars.begin(), this->cars.end(), comparator);
    std::cout<<"-RANKS-------------"<<std::endl;
    for(int i = 0; i < this->cars.size(); i++)
    {
        if(cars[i]->GetStatus() == CarStatus::CompletedRace)
        {
            std::cout<<cars[i]->GetName()<<std::endl;
        }
    }
    std::cout<<"-------------------"<<std::endl;
}

void Circuit::ShowWhoDidNotFinish()
{
    std::cout<<"-OUT-OF-FUEL-------"<<std::endl;
    for(int i = 0; i < this->cars.size(); i++)
    {
        if(cars[i]->GetStatus() == CarStatus::OutOfFuel)
        {
            std::cout<<cars[i]->GetName()<<std::endl;
        }
    }
    std::cout<<"-------------------"<<std::endl;
}
