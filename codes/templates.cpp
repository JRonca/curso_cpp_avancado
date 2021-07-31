#include <iostream>

template <class T>

class Stack {
	public:
		void pilha(T array, int max){
			int i={0};

			while(i<max){
				std::cout << "Os elementos do array sao: " << array[i] << "\n";
				i++;
			}
		}
};

int main( int argc, char **argv  ){
	Stack<const char*> s;
	char marray[]={'A','B','C','D'};
	int max = sizeof(marray)/sizeof(marray[0]);
	char * pmarray = marray;
	s.pilha(marray,max);
	std::cout << "=================================================" << "\n";
	Stack<const std::string*> string;
	std::string strarray[] = {"Alucard", "Kirby", "Sonic", "Mario"};
	int max2 = sizeof(strarray)/sizeof(strarray[0]);
	string.pilha(strarray,max2);
	std::cout << "=================================================" << "\n";
	Stack<const int*> integer;
	int intarray[] = {1,3,11,17,13};
	int max3 = sizeof(intarray)/sizeof(intarray[0]);
	integer.pilha(intarray,max3);
	return 0;
}
