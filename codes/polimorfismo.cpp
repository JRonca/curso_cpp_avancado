#include <iostream>

class Pessoa{
	public:
		int num(){
			return 10;
		}

		int num (int num){
			return num;
		}
};

class Turma : public Pessoa{
	public:
		int num(){
			return 50;
		}

		int num(int num){
			return num;
		}
};

int main( int argc, char **argv  ){
	Pessoa pessoa;
	Turma turma;
	std::cout << "Pessoa num(): " << pessoa.num() << "\n";
	std::cout << "Pessoa num(int num): " << pessoa.num(90) << "\n";

	std::cout << "Turma num(): " << turma.num() << "\n";
	std::cout << "Turma num(int num): " << turma.num(75) << "\n";
	return 0;
}
