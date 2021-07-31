#include <iostream>

class Mae{
	public:
		virtual void mensagem(){
			std::cout << "Sua Mae" << "\n";
		}
};

class Filha : public Mae{
	public:
		void mensagem(){
			std::cout << "Sua Filha" << "\n";
		}
};

class Neta : public Filha {
	public:
		void mensagem(){
			std::cout << "Sua Neta" << "\n";
		}
};

void responde(Mae * mae){
	mae->mensagem();
}

int main( int argc, char **argv  ){
	Mae m;
	Filha f;
	Neta n;

	m.mensagem();
	f.mensagem();
	n.mensagem();

	std::cout << "\n----------------------------\n";
	
	responde(&m);
	responde(&f);
	responde(&n);
	return 0;
}
