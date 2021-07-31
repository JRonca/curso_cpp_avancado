#include <iostream>

void funcao(int * ptr, int x){
	if(ptr == NULL || x==0){
		throw ptr;
		//std::cout << "Erro bizaaro" << "\n";
	}else{
		std::cout << "O ponteiro e: " << *ptr << " e o numero e: " << x << "\n";
	}
}

int main( int argc, char **argv  ){
	int num = 10;
	int * pnum = &num;
	try{
		funcao(pnum, num);
		funcao(pnum, 80);
		funcao(pnum, 4);
		funcao(NULL,80);
		funcao(pnum, num);
		funcao(pnum, 80);
		funcao(pnum, 4);
	}catch( ... ){
		std::cout << "Erro identificado" << "\n";
	}
	return 0;
}
