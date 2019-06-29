#pragma once
#include <memory>
class FlyBehavior
{
public:
	virtual ~FlyBehavior() = default;
	virtual void fly() =0;
};
