#include "exemplo.hh"


int main( int argc, char **argv  ){
	int a = 30;
	Exemplo<int> exemplo(a, &a);
	return 0;
}
