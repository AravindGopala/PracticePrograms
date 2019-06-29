#pragma once
#include <memory>
class QuackBehavior
{
public:
	virtual ~QuackBehavior() = default;
	virtual void Sound() =0;
};
