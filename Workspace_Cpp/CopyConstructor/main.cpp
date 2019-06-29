#include <iostream>
#include <string.h>
using namespace std;
class MyString
{
private:
	char* buffer;
public:
	MyString(const char* initString) // constructor
	{
		buffer = NULL;
		cout << "Default constructor: creating new MyString" << endl;
		if(initString != NULL)
		{
			buffer = new char [strlen(initString) + 1];
			strcpy(buffer, initString);
			cout << "buffer points to: 0x" << hex;
			cout << (unsigned int*)buffer << endl;
		}
	}
	MyString(const MyString& copySource) // Copy constructor
	{
		buffer = NULL;
		cout << "Copy constructor: copying from MyString" << endl;
		if(copySource.buffer != NULL)
		{
			// allocate own buffer
			buffer = new char [strlen(copySource.buffer) + 1];
			// deep copy from the source into local buffer
			strcpy(buffer, copySource.buffer);
			cout << "copy buffer points to: 0x" << hex;
			cout << (unsigned int*)buffer << endl;
		}
	}

//	MyString(MyString&& moveSource) // Copy constructor
//	{
//		cout << "Move constructor: Moving from MyString" << endl;
//		if(moveSource.buffer != NULL)
//		{
//		buffer = moveSource.buffer; // take ownership i.e. 'move'
//		moveSource.buffer = NULL;
//		// set the move source to NULL
//		}
//		cout << "Move buffer points to: 0x" << hex;
//		cout << (unsigned int*)buffer << endl;
//		moveSource.buffer=NULL;
//	}
	// Destructor
	~MyString()
	{
		cout << "Invoking destructor, clearing up" << endl;
		delete [] buffer;
		buffer=NULL;
	}
	int GetLength()
	{ return strlen(buffer); }
	const char* GetString()
	{ return buffer; }
};

MyString Copy(MyString& source) // function
{
	MyString copyForReturn(source.GetString()); // create copy
	cout<<"break"<<endl;
	return copyForReturn; // return by value invokes copy constructor
}



int main()
{

	MyString sayHello ("Hello World of C++");
	MyString sayHelloAgain(Copy(sayHello)); // invokes 2x copy constructor
	cout<<sayHello.GetString()<<endl;
	//MyString sayHelloAgain(std::move(sayHello));
	return 0;
}
