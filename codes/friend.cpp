#include <iostream>

class Casa {
	public:
		std::string comp="123";
	protected:
		char essid[5] = {'H','o','m','e','\0'};
	private:
		std::string passwd = "abc"+comp;
	friend class Vizinho;
};

class Vizinho{
	public:
		void controller(){
			Casa c;
			std::cout << "A internet e: " << c.essid << " e a senha e: " << c.passwd << "\n";
		}
};

int main( int argc, char **argv  ){
	Vizinho viz;
	viz.controller();
	return 0;
}
