#include "Header.h"
#include "LoginManager.h"

void getInput(std::string& string) {
	std::getline(std::cin, string);
	string.erase(std::remove(string.begin(), string.end(), ' '), string.end());
	std::transform(string.begin(), string.end(), string.begin(), ::tolower);
}

bool validLogIn(const std::string& filePath, const std::string& decriptionKey, std::string& output) {
	std::string fileData;

	try { fileData = open(filePath); }
	catch (const fs::filesystem_error) {
		std::cout << "WARNING ERROR OPENING => " << filePath << std::endl;
		return false; }

	if (decryptData(decriptionKey, fileData, output))
		return true;
	
	output = "";
	return false;
}

void login(const std::string& path) {
	std::string pswrd, username, userData;
	std::cout << "Enter Username :\n";
	getline(std::cin, username);
	username = path + "\\" +  username + lockeduserExt;

	std::cout << "Enter Password :\n";
	getline(std::cin, pswrd);


	if (!pathExits(username)) {
		std::cout << "Invalid username\n";
		return;
	}

	if (unlockFile(username, pswrd)) {
		do {
			std::cout << std::endl;
		} while (unlockedFileManager(username) == 0);
	}
}

int unlockedFileManager(const std::string& unlockedFilePath) {
	std::vector<std::string> lineBrokenFileData, strVecTmp;
	std::string userName = unlockedFilePath, strTmp;
	removePathAndFileExtention(userName , unlockeduserExt);

	unsigned action = 0;
	getAction({ "Read File", "Lock File", "Append new line", "Delete line", "Overwrite File", "Delete File", "Quit"}, action, "What do you want to do " + userName);
	switch (action)
	{
	case 0: // Read File
		lineBrokenFileData = vectOpen(unlockedFilePath);
		std::cout << "\n" << "Contents of " << unlockedFilePath << " :\n";
		printFile(lineBrokenFileData);
		break;
	case 1: // LockFile
		if (lockAndCloseFile(unlockedFilePath, userName)) 
			return 1;
		else 
			break;
	case 2: // Append new Line 
		break;
	case 3: // Delete line
		std::cout << std::endl;
		userDeleteLine(lineBrokenFileData, unlockedFilePath);
		break;
	case 4: // OverWrite File
		break;
	case 5: // Delete File 
		std::cout << "Are you sure you want to delete " << userName << "(y/n)";
		getInput(strTmp);
		if (!(strTmp == "y")) break;

		std::cout << "ALL DATA WILL BE LOST FOREVER continue (y/n)" << std::endl;
		getInput(strTmp);
		if (!(strTmp == "y")) break;

		if (deleteFile(unlockedFilePath)) {
			return 1;
		}
		break;
	case 6: // Quit
		std::cout << "Are you sure you want to quit without saving file THIS WILL LEAVE YOUR FILE EXPOSED\n" << "(y/n)" << std::endl;
		getInput(strTmp);
		if (strTmp == "y") return 1;
	}
	return 0;
}

void userDeleteLine(std::vector<std::string>& lineBrokenFileData, const std::string& unlockedFilePath)
{
	unsigned int targetLine = 0;
	std::string yn;
	lineBrokenFileData = vectOpen(unlockedFilePath); printFile(lineBrokenFileData);
	std::cout << "Which line would you like to remove ? :\n";

	std::getline(std::cin, yn);
	try { targetLine = std::stoi(yn); }
	catch (...) { targetLine = 0; }

	if (targetLine < 1 || targetLine > lineBrokenFileData.size()) {
		std::cout << "Invalid Line\n";
		return;
	}
	targetLine--;
	std::cout << "Are you sure you want to delete the following line (y/n):\n"
		<< targetLine + 1 << " - " << lineBrokenFileData[targetLine] << "\n";
	getInput(yn);
	if (yn == "y") {
		if (deleteLine(unlockedFilePath, targetLine))
			std::cout << "Deletion sucessful\n";
		else std::cout << "An error occoured try again later";
	}
	else std::cout << "Deletion canceld\n";
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

bool lockAndCloseFile(const std::string unlockedFilePath, const std::string& fileName) {
	std::string password, fileContent, yn;
	std::cout << "Are you sure you want to close and lock " << fileName << "(y/n)" << std::endl;
	std::getline(std::cin, yn);
	
	yn.erase(std::remove(yn.begin(), yn.end(), ' '), yn.end());
	if (!(yn == "y" || yn == "yes")) return false;

	password = getPword(fileName);
	return lockFile(unlockedFilePath, password);
}

std::string getPword(const std::string& fileName) {
	std::string pword, pwordReEnter;
	std::cout << "Enter the password you want to use to lock " << fileName << " :" << std::endl;
	std::getline(std::cin, pword);
	std::cout << "Re-enter the password :" << std::endl;
	std::getline(std::cin, pwordReEnter);
	if (!(pword == pwordReEnter)) {
		std::cout << "Passowords do not match" << std::endl;
		return getPword(fileName);
	}
	return pword;
}

bool signUp(const std::string& basePath, std::string& newName ) {
	std::cout << "Enter your username :" << std::endl;
	std::getline(std::cin, newName);
	newName = basePath + "\\" + newName;
	if (pathExits(newName + lockeduserExt) || pathExits(newName + unlockeduserExt)) {
		std::cout << "Username Already Taken";
		return false;
	} 
	newName = newName + unlockeduserExt;
	try { // create the file extention 
		std::ofstream newFile (newName);
		newFile.close();
	}
	catch (...) {
		std::cout << "Unable to create file try agian later";
		return false;
	}
	return true;
}