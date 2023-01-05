#include "Header.h"
#include <filesystem> 
#include <algorithm> 
#include <cmath>

namespace fs = std::filesystem;

bool decryptData(const std::string& key, const std::string& data, std::string& output); //Encryption.cpp
void encryptData(const std::string& key, std::string& data); //Encryption.cpp

std::string open(const std::string& path); // FileManager.cpp
void write(const std::string& data, const std::string& path); // FileManager.cpp
std::vector<std::string> vectOpen(const std::string& path); // FileManager.cpp
std::string open(const std::string& path); // FileManager.cpp
void printFile(const std::vector<std::string>& lineBrokenFileData); // FileManager.cpp

void getAction(const std::vector<std::string>& options, unsigned int& action, const std::string& message); //Main.cpp


void removePathAndFileExtention(std::string& userName, const std::string& fileExtention); // Self.cpp

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


int unlockedFileManager(const std::string& unlockedFilePath) {
	std::vector<std::string> lineBrokenFileData, strVecTmp;
	std::string userName = unlockedFilePath, rawData, strTmp;
	int intTmp;
	removePathAndFileExtention(userName , unlockeduserExt);

	unsigned action = 0;
	getAction({ "Read File", "Lock File", "Append new line", "Overwrite File", "Delete File", "Quit"}, action, "What do you want to do " + userName);
	switch (action)
	{
	case 0:
		lineBrokenFileData = vectOpen(unlockedFilePath);
		std::cout << "\n" << "Contents of " << unlockedFilePath << " :\n";
		printFile(lineBrokenFileData);
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
		std::cin >> strTmp;
		std::transform(strTmp.begin(), strTmp.end(), strTmp.begin(), ::toupper);
		if (strTmp == "Y") return 1;
	}
	return 0;
}

void removePathAndFileExtention(std::string& userName, const std::string& fileExtention)
{
	int currentSlash = 0; // to get just the file name
	userName.erase(userName.find(fileExtention), fileExtention.size());
	while (true) {
		currentSlash = userName.find("\\");
		if (currentSlash != -1) userName.erase(0, currentSlash + 1);
		else break;
	}
	while (true) {
		currentSlash = userName.find("/");
		if (currentSlash != -1) userName.erase(0, currentSlash + 1);
		else break;
	}
}