#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>

std::vector<std::string> getDoc(std::string path); 

int main( int argc, char **argv  ){
	std::string file="/etc/apache2/mods-available/cgi.load";
	//system("sudo chown -R $USER:$USER /var/www/html/");
	std::vector<std::string> v;
	v=getDoc(file);
	for(int i=0;i<v.size();i++){
                 std::cout << v[i] << "\n";
        }
	return 0;
}

std::vector<std::string> getDoc(std::string path){
	std::string line;
	std::vector<std::string> arrFile;
	std::fstream file(path);
	if(file.is_open()){
		while(std::getline(file,line)){
			arrFile.push_back(line);
		}
	}else{
		std::cout << "Can't open the file" << "\n";
	}
	return arrFile;
}
