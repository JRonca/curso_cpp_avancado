#ifndef EXEMPLO_H
#define EXEMPLO_H
#include <iostream>

template<typename T>
class Exemplo{
	public:
		typedef std::string STR;
		Exemplo();
		Exemplo(T, T *);
		~Exemplo();
		void lista_array(STR array[]);
		STR mostra(STR new_pass);

	private:
		const double pi = 3.14;

	protected:
		STR senha = {"naosei"};
};

#include "exemplo.cpp"
#endif
