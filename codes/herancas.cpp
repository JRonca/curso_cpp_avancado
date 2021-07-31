#include <iostream>

class Pessoa{
	public:
		void nome(){
			std::cout << "Ronca" << "\n";
		}
};

class Habilidades : public Pessoa{
	public:
		void idioma(){
			std::cout << "Ingles" << "\n";
		}
};

int main( int argc, char **argv  ){
	Habilidades hab;
	std::cout << "Nome: ";
	hab.nome();
	std::cout << "Idioma: ";
	hab.idioma();
	return 0;
}
