#pragma once
#include "IObserver.h"
class ISubject
{
public:
    ISubject() = default;
    virtual ~ISubject(){}
    virtual void RegisterObserver(IObserver*)=0;
    virtual void DeRegisterObserver(IObserver*)=0;
    virtual void NotifyObserver()=0;
};
