#include <iostream>
#include <algorithm>
#include <utility>


using namespace std;

int main()
{

    //Calculating fibnocci series through lambda

    auto fib = [i=0, j=1]() mutable {
        i= exchange(j,j+i);
        return i;
    };
    for(int count=0; count<10; count++)
    {
        int u=fib();
        std::cout<<u<<std::endl;
    }
    return 0;
}
