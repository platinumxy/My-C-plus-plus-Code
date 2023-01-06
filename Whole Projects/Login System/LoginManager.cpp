#include "Header.h"
#include "LoginManager.h"

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
		break;
	case 4: // Overview File
		break;
	case 5: // Delete File 
		std::cout << "Are you sure you want to delete " << userName << "(y/n)";
		std::getline(std::cin, strTmp);
		strTmp.erase(std::remove(strTmp.begin(), strTmp.end(), ' '), strTmp.end());
		if (!(strTmp == "y" || strTmp == "yes")) break;

		std::cout << "ALL DATA WILL BE LOST FOREVER continue (y/n)" << std::endl;
		std::getline(std::cin, strTmp);
		strTmp.erase(std::remove(strTmp.begin(), strTmp.end(), ' '), strTmp.end());
		if (!(strTmp == "y" || strTmp == "yes")) break;

		if (deleteFile(unlockedFilePath)) {
			return 1;
		}

		break;
	case 6: // Quit
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
	if (pword == pwordReEnter) {
		std::cout << "Passowords do not match" << std::endl;
		return getPword(fileName);
	}
	return pword;
}