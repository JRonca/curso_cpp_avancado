#include <iostream>

enum class Colors {
	blue,
	purple
};

enum class Fruits{
	orange,
	peach
};

int main( int argc, char **argv  ){
	Colors colors;
	Fruits fruits;
	
	colors = Colors::purple;
	std::cout << "O número de cores e: " << static_cast<int>(colors) << "\n";
	std::cout << "O número de cores e: " << static_cast<int>(Colors::blue) << "\n";
	return 0;
}
