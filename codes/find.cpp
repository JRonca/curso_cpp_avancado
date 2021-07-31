#include <iostream>
#include <string>


int main( int argc, char **argv  ){
	std::string frase = "dia A luz do dia @ me faz feliz todo dia .";
	//rfind() pesquisa na string de tras pra frente
	//find() pesquisa de frente pra tras
	std::cout << "A posição de 'dia' e: " << frase.find("dia") << "\n";
	std::cout << "A posição de 'rdia' e: " << frase.rfind("dia") << "\n";
	std::cout << "A posição da primeira ocorrencia de 'dia' e: " << frase.find_first_of("dia") << "\n";
	std::cout << "A posição da ultima ocorrencia de 'dia' e: " << frase.find_last_of("dia") << "\n";
	std::cout << "A posição da primeira nao ocorrencia de 'dia' e: " << frase.find_first_not_of("dia") << "\n";
	return 0;
}
