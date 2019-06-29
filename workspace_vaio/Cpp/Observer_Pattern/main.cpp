#include "WeatherStation.h"
#include <memory>
#include <iostream>
class ConditionDisplay: public IObserver
{
    int temperature;
    int pressure;
    int humidity;
    ISubject* WeatherStation;

public:
    ~ConditionDisplay(){}
    ConditionDisplay(auto weatherStation):
    WeatherStation(weatherStation)
    {
     WeatherStation->RegisterObserver(this);
    }
    void update(int temperature, int pressure, int humidity)
    {
        std::cout<<"Received Temperature is"<<temperature<<std::endl;
        std::cout<<"Received pressure is"<<pressure<<std::endl;
        std::cout<<"Received humidity is"<<humidity<<std::endl;
    }
 };


int main()
{
// WeatherStation* weatherStation = new WeatherStation();
//ConditionDisplay* conditionDisplay = new ConditionDisplay(weatherStation);
    auto weatherStation = std::make_shared<WeatherStation>();
    auto conditiondisplay = std::make_unique<ConditionDisplay>(weatherStation.get());
    weatherStation->SetMeasurements(10,20,30);
    weatherStation->SetMeasurements(12,20,30);
}
