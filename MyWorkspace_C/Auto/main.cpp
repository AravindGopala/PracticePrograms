#include <iostream>
#include <type_traits>

using namespace std;

template<typename T> struct TD;

decltype(auto) func1(const auto& i, const auto& j)
{
	return i>j?i:j;
}
template<typename U, typename V>
U max(U i, V j )
{
	return i>j?i:j;
}

int main()
{
	const auto i =0;
	//TD<decltype(i)> td;
	//cout<<<<endl;
auto max2 =func1(7.2,2);
auto max1 =max(7.2,2);
cout<<max1<<endl;
	return 0;
}
