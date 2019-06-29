#include "MallardDuck.h"
#include <memory>
int main()
{
 auto mallard = std::make_unique<MallardDuck>();
 mallard->fly();
 mallard->Sound();
}
