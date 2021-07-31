#include <iostream>

inline int p_mais_dois(int * x){
	*x= *x + 2;
	return *x;
}
inline int mais_dois(int x){
	x= x + 2;
	return x;
}

int main( int argc, char **argv  ){
	int x= 9;
	std::cout << "o valor de x antes e: " << x << "\n";
	std::cout << "o valor de 9 + 2 e: " << p_mais_dois(&x) << "\n";
	std::cout << "o valor de x meio e: " << x << "\n";
	std::cout << "o valor de 9 + 2 e: " << mais_dois(x) << "\n";
	std::cout << "o valor de x depois e: " << x << "\n";

	return 0;
}
