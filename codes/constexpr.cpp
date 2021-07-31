#include <iostream>

constexpr long int fib (int n){
	return (n<=1) ? n : fib(n-1) + fib(n-2);
}

int main( int argc, char **argv  ){
	long int z=fib(30);
	std::cout << "O numero fibonacci e: " << z << "\n";
	return 0;
}
