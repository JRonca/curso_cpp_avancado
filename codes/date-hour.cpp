#include <iostream>
#include <ctime>
#include <string>

int main( int argc, char **argv  ){
	time_t now = time(0);
	tm * dh = localtime(&now);
	auto formato = [] (int x) {
		return ((x>9) ? std::to_string(x) : "0" + std::to_string(x));
	};
	char * datehour = ctime(&now);
	std::cout << "A hora e a data e: " << datehour << "\n";
	std::cout << "O ano e: " << dh->tm_year+1900 << "\n";
	std::cout << "O mes e: " << dh->tm_mon+1 << "\n";
	std::cout << "O dia do mes e: " << dh->tm_mday << "\n";
	std::cout << "O dia da semana e: " << dh->tm_wday << "\n";
	std::cout << "O dia do ano e: " << dh->tm_yday << "\n";
	std::cout << "O horario e: " << formato(dh->tm_hour) << ":" << formato(dh->tm_min) << ":" << formato(dh->tm_sec) << "\n";
	return 0;
}
