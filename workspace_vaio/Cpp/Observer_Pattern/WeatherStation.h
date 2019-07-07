#pragma once
#include "ISubject.h"
#include "IObserver.h"
#include <vector>

class WeatherStation: public ISubject
{
    int temperature;
    int pressure;
    int humidity;
    void getTemperature();
    void getPressure();
    void gethumidity();
    std::vector<IObserver*> Observers;
    void NotifyObserver() override;
public:
  WeatherStation(){
  }
  ~WeatherStation(){}
  void SetMeasurements(int, int, int);
  void RegisterObserver(IObserver* O) override;
  void DeRegisterObserver(IObserver* O) override;
};

