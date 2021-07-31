#include <iostream>

class Pessoa{
	private:
		int idade = 21;
	protected:
		double altura = 1.65;
	public:
		void nome(){
			std::cout << "Ronca" << "\n";
		}
		int display_idade(){
			return idade;
		}

};

class Habilidades : public Pessoa{
	public:
		void idioma(){
			std::cout << "Ingles" << "\n";
		}

		double display_altura(){
			return altura;
		}
};

class Dados : public Habilidades{

};

int main( int argc, char **argv  ){
	Dados dados;
	std::cout << "Nome: ";
	dados.nome();
	std::cout << "Idioma: ";
	dados.idioma();
	std::cout << "Altura: " << dados.display_altura() << "\n";
	std::cout << "Idade: " << dados.display_idade() << "\n";
	return 0;
}
