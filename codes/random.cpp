#include <iostream>
#include <random>
#include <string>

int main( int argc, char **argv  ){

	std::random_device rd;
	std::mt19937 gen( rd() );
	std::uniform_int_distribution<> dis (0,9);
	
	int max_rd = 11;
	if(argc > 1){
		max_rd = atoi(argv[1]);
	}
	if(max_rd==0){
		std::cerr << "Use: " << argv[0] << " [digitos]\n";
	}
	std::string y {};
	for(int i = 0; i< max_rd; i++){
		y+=std::to_string( dis(gen) );
	}
	std::cout << y << "\n";
	return 0;
}
