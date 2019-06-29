	#include <iostream>

class Box {
   public:
	  // Constructor definition
	  Box(double l = 2.0, double b = 2.0, double h = 2.0) {
		 std::cout <<"Constructor called." <<'\n';
		 length = l;
		 breadth = b;
		 height = h;
	  }
	  double Volume() {
		 return length * breadth * height;
	  }

   private:
	  double length;     // Length of a box
	  double breadth;    // Breadth of a box
	  double height;     // Height of a box
};
	class Fred {
	public:
	static void staticMemberFn(){
			std::cout<<"Static Function"<<'\n';
		};// A static member function can usually handle it
	void memberFn();
	// ...
	};
	// Wrapper function uses a global to remember the object:
	void Fred::memberFn(){
		std::cout<<"Member Function"<<'\n';
	}

//	void Fred_memberFn_wrapper()
//	{
//		object_which_will_handle_signal->memberFn();
//	}
	int main()
	{
		Box* box;
		std::cout<<box->Volume()<<'\n';
	  /* signal(SIGINT, Fred::memberFn); */   // Can NOT do this
		Fred One;
		Fred* object_which_will_handle_signal;
		object_which_will_handle_signal->memberFn();
	//	Fred::memberFn();
		//Fred_memberFn_wrapper();  // Okay
		Fred::staticMemberFn();   // Okay usually; see below
	  // ...
	}
