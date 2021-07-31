#include <iostream>
#include <regex>

bool inicia_com_letra(std::string str){
	std::regex re("^[a-zA-Z]");
	std::smatch match;
	return std::regex_search(str, match, re);
}

int main( int argc, char **argv  ){
	std::string str = argv[1];
	std::cout << inicia_com_letra(str) << "\n";
	return 0;
}
