#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

std::map<std::string, std::string> NamesNAmount;
std::string Get_Info(std::string msg){
	std::string answer;
	do{
		std::cout<<msg;
		std::getline(std::cin, answer);
	}while(answer.empty());
	return answer;
};
void Open_File_And_Get_Data(){
	std::vector<std::string> oneTwoCombine;
	std::ifstream userFile("users.txt");
	if(!userFile){return;}else{
		std::string line;
		while(std::getline(userFile, line)){
			oneTwoCombine.push_back(line);
		}
		for(int i = 0; i < oneTwoCombine.size(); i++){
			if(i != oneTwoCombine.size()-1){
				NamesNAmount.insert({oneTwoCombine.at(i),oneTwoCombine.at(i+1)});
			}
		}
	}
	return;
}
void Tell_N_Save(){
	std::ofstream userFile("users.txt");
	for(auto user:NamesNAmount){
		std::cout<< "\n Username: "<<user.first<<", Goal is: "<<user.second<<"\n";
		userFile << user.first << "\n" << user.second << "\n";
	}
	userFile.close();
}

int main(){
	std::string user;
	std::string goal;
	bool badInput = false;
	Open_File_And_Get_Data();
	std::cout<<"Entered App\n";
	user = Get_Info("\nYour name: ");
	goal = Get_Info("\nYour Goal in oz: ");
	NamesNAmount.insert({user, goal});
	Tell_N_Save();
}
