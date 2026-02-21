#include <iostream>
#include <fstream>
#include <string>


std::string getName(){
	std::string name;
	do{
		std::cout<<"\nWhat is your name: ";
		std::getline(std::cin, name);
	}while(name.empty());
	return name;
}
void checkFile(){
	std::string myText;
	std::ifstream checkExistance("users.txt");
	
	while (getline (checkExistance, myText)) {
  // Output the text from the file
   std::cout << myText << "\n";
}
}


int main(){
	std::string user;
	bool badInput = false;
	checkFile();
	
	std::cout<<"Entered App\n";
	user = getName();
	
		
	std::cout<<"\n"<< user << "\n";
}
