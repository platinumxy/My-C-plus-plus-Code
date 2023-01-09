#include "Header.h"
#include "Main.h"
int main() {
	const std::string saveFilePath = getPath();
	
	std::vector<std::string> users;
	do {//DRY way to loop over main action loop update variables and add line breaks 
		users = filteredFilesInFolder(saveFilePath); // update incase files have been deleted 
		std::cout << std::endl; 
	} while (mainActionLoop(saveFilePath, users) == 0);

	return 0;
}

int mainActionLoop(const std::string& savePath, std::vector<std::string>& users) {
	unsigned int action = 0;
	getAction({ "Login", 
		"Sign up", 
		"Open Unlocked files (note unlocked files can be opened outside of this aplication)", 
		"Quit" }, action, "Select a option from the bellow list :");
	switch (action) {
	case 0: // Login
		login(savePath);
		break;
	case 1: // Sign up
		{std::string newUser;
		if (signUp(savePath, newUser)) 
			{do {std::cout << std::endl;} while (unlockedFileManager(newUser) == 0);}}
		break;
	case 2: // Unlocked Users 
		unlockedUsersAction(savePath, users);
		break;
	case 3: // Quit
		return 1; // Break out of main loop
	}
	return 0;
}

void unlockedUsersAction(const std::string& genericPath, std::vector<std::string>& users) {
	std::vector<std::string> unlockedUsers = unlockedFiles(users);
	if (unlockedUsers.size() == 0) {
		std::cout << "No Unlocked Users" << "\n";
		return;
	}

	std::cout << "Select a user to open from the bellow list :\n";
	for (size_t i = 0; i < unlockedUsers.size(); i++) {
		std::string tmpUser = unlockedUsers[i];
		tmpUser.erase(0, genericPath.size()+1); // remove save file path
		tmpUser.erase(tmpUser.find(unlockeduserExt), unlockeduserExt.size()); // remove save file extention 
		std::cout << i+1 << ". " << tmpUser << "\n";
	}

	unsigned int userChoice;
	while (true) {
		std::cin.ignore();
		std::cin >> userChoice;
		if (userChoice > unlockedUsers.size() || userChoice <= 0) {
			std::cout << "Please enter a valid index :\n";// << std::endl;
		}
		else { userChoice--; break; }
	}

	do {
		std::cout << std::endl;
	} while (unlockedFileManager(unlockedUsers[userChoice]) == 0);

}

void getAction(const std::vector<std::string>& options, unsigned int& action, const std::string& message){
	std::string input;
	std::cout << message << "\n";
	for (unsigned i = 0; i < options.size(); i++)
		std::cout << i + 1 << ". " << options[i] << "\n";
	while (action == 0) {

		getline(std::cin, input); 
		input.erase(std::remove(input.begin(), input.end(), ' '), input.end());

		try  // String to int
			{ action = std::stoi(input); }
		catch (...) 
			{ action = 0; }
		
		if (action > options.size() || action < 1) {
			action = 0;
			std::cout << std::endl;
		}
	}
	action--;
}


