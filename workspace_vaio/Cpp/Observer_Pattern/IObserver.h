#pragma once
class IObserver
{
public:
    IObserver()=default;
    virtual ~IObserver(){}
    virtual void update(int, int, int)=0;
};
