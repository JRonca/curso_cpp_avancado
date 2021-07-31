#include <iostream>

class Hello{
	public:
		void helloworld(){
			std::cout << "Hello, World!" << "\n";
		}
};

int main( int argc, char **argv  ){
	Hello hello;
	hello.helloworld();
	//OU tu pode fazer assim:
	//Hello * hello;
	//hello->helloworld();
	return 0;
}
