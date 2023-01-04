#include "Header.h"
#include <filesystem> 
#include <algorithm> 

namespace fs = std::filesystem;

bool decryptData(const std::string& key, const std::string& data, std::string& output); //Encryption.cpp
void encryptData(const std::string& key, std::string& data); //Encryption.cpp

std::string open(const std::string& path); // FileManager.cpp
void write(const std::string& data, const std::string& path); // FileManager.cpp

void getAction(const std::vector<std::string>& options, unsigned int& action); //Main.cpp

bool ValidLogIn(const std::string& path, const std::string& decriptionKey, std::string& userData) {
	std::string fileData;

	try { fileData = open(path); }
	catch (const fs::filesystem_error) {
		std::cout << "WARNING ERROR OPENING => " << path << std::endl;
		return false; }

	if (decryptData(decriptionKey, fileData, userData))
		return true;
	
	userData = "";
	return false;
}


int unlockedFileManager(const std::string& unlockedFilePath){
	unsigned int action; 
	std::string fileContents, tmp; //accout for needing any needed vars

	getAction({ "Read File", "Lock File", "Append to file", "Overwrite File", "Delete File", "Quit"}, action);
	switch (action)
	{
	case 0:
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		std::cout << "Are you sure you want to quit without saving file THIS WILL LEAVE YOUR FILE EXPOSED\n" << "(y/n)" << std::endl;
		std::cin >> tmp;
		std::transform(tmp.begin(), tmp.end(), tmp.begin(), ::toupper);
		if (tmp == "Y") return 1;
	}
	return 0;
}
