#include "exemplo.hh"


typedef std::string STR;

template<typename T>
Exemplo<T>::Exemplo(){
	std::cout << "Iniciando o nosso exemplo" << "\n";
}
template<typename T>
Exemplo<T>::Exemplo(T x, T * y){
	std::cout << "A soma de " << x << " mais " << *y << " e igual a " << x+(*y) << "\n";
}

template<typename T>
Exemplo<T>::~Exemplo(){
	std::cout << "Fechando o projeto" << "\n";
}

template<typename T>
void Exemplo<T>::lista_array(STR array[]){
	std::cout << "Ainda sendo implementada" << "\n";
}

template<typename T>
STR Exemplo<T>::mostra(STR new_pass){
	senha = new_pass;
	return senha;
}

