#include "Header.h"
#include "Main.h"


int main() {
	const std::string saveFilePath = getPath();
	
	std::vector<std::string> users = filesInFolder(saveFilePath);
	
	stripInvalidFilesAndPaths(users);
	
	do {
		std::cout << std::endl; //DRY way to loop over main action loop and add a line break before hand
	} while (mainActionLoop(users, saveFilePath) == 0);

	return 0;
}

int mainActionLoop(std::vector<std::string>& users, const std::string& savePath)
{
	std::vector<std::string> unlockedUsers(0); //insilisd incase needed in switch   
	unsigned int action = 0;
	getAction(action);
	switch (action) {
	case 1:

		break;
	case 2:
		break;
	case 3:
		unlockedUsers = unlockedFiles(users);
		if (unlockedUsers.size() == 0) {
			std::cout << "No Unlocked Users" << "\n";
			break;
		}
		
		for (std::string& user : unlockedUsers) {
			std::string tmpUser = user;
			tmpUser.erase(0, savePath.size()); // remove save file path
			tmpUser.erase(tmpUser.find(unlockeduserExt), unlockeduserExt.size()); // remove save file extention 
			std::cout << tmpUser << "\n";
		}
		break;
	case 4:
		return 1;
	}
	return 0;
}

void getAction(unsigned int& action)
{
	while (action == 0) {
		std::cout << "Select a option from the bellow list :\n"
			<< "1. Login \n"
			<< "2. Sign up \n"
			<< "3. Open Unlocked files \n"
			<< "4. Quit" << std::endl;
		std::cin >> action;
		if (action > 4 || action < 1) {
			action = 0;
		}
	}
}


