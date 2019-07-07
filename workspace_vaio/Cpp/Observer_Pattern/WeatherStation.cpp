#include "WeatherStation.h"
#include "algorithm"


void WeatherStation::RegisterObserver(IObserver* O){
      Observers.emplace_back(O);
  }

void WeatherStation::DeRegisterObserver(IObserver* O){
      auto observerToBeRemoved = std::find(Observers.begin(),Observers.end(), O);
      Observers.erase(observerToBeRemoved);
  }

void WeatherStation::NotifyObserver() {
      for (auto it=Observers.begin(); it<Observers.end(); it++) {
          (*it)->update(temperature, pressure,humidity);
      }
}

void WeatherStation::SetMeasurements(int temperature, int pressure, int humidity){
          this->temperature=temperature;
          this->pressure=pressure;
          this->humidity=humidity;
          NotifyObserver();
 }
