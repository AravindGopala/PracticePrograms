#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

decltype(auto) func1(const auto& v)
{
	for(auto i=v.begin();i<v.end();i++){
		cout<<*i<<endl;
	}
	vector<int> t{1,2,3,4,5,6,};
	return v;

}

int main()
{
	vector<int> v{1,2,3,4,5,6,};
	for(auto i=v.begin();i<v.end();i++){
		cout<<*i<<endl;
	}
	v.emplace_back();
	auto g =func1(v);
	cout << "Hello World!" << endl;
	return 0;
}
