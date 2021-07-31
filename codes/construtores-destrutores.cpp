#include <iostream>

class Qualquer{
	public:
		Qualquer(){
			std::cout << "Iniciando..." << "\n";
		}

		Qualquer(int x, int y){
			std::cout << "A soma de x e y e: " << x+y << "\n";
		}
		
		void uma_funcao(){
			std::cout << "Uma funcao" << "\n";
		}
		
		void outra_funcao(){
			std::cout << "Outra funcao" << "\n";
		}

		~Qualquer(){
			std::cout << "Finalizando..." << "\n";
		}
};

int main( int argc, char **argv  ){
	Qualquer q(5,4);
	q.uma_funcao();
	q.outra_funcao();
	return 0;
}
