#include <iostream>

class Primeira{
	public:
		Primeira(){
			std::cout << "Iniciando a primeira ..." << "\n";
		}

		~Primeira(){
			std::cout << "Finalizando a primeira ..." << "\n";
		}

		void fmembro1(){
			std::cout << "Fmembro da primeira" << "\n";
		}
};

class Segunda{
	public:
		Segunda(){
			std::cout << "Iniciando a segunda ..." << "\n";
		}
		
		virtual void virtual_abstrata()=0;//não pode instanciar a classe mais

		~Segunda(){
			std::cout << "Finalizando a segunda ..." << "\n";
		}

		void fmembro2(){
			std::cout << "Fmembro da segunda" << "\n";
		}
};

class Terceira : public Primeira, public Segunda{
	public:
		Terceira(){
			std::cout << "Iniciando a terceira ..." << "\n";
		}

		virtual void virtual_abstrata(){
			std::cout << "Agora pode instanciar" << "\n";
		}

		~Terceira(){
			std::cout << "Finalizando a terceira ..." << "\n";
		}

		void fmembro3(){
			std::cout << "Fmembro da terceira" << "\n";
		}
};

int main( int argc, char **argv  ){
	Terceira ter;
	ter.fmembro2();
	ter.virtual_abstrata();
	return 0;
}
