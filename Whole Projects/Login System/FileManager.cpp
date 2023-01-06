#include "Header.h" 
#include <sys/stat.h> // for checking pathExists 
#include <filesystem> 
#include <fstream>

namespace fs = std::filesystem;


void encryptData(const std::string& key, std::string& data); // Encryption.cpp
bool decryptData(const std::string& key, const std::string& data, std::string& output); // Encryption.cpp

bool ValidLogIn(const std::string& path, const std::string& decriptionKey, std::string& output); // LoginManager.cpp


bool pathExits(const std::string& path){
	struct stat buffer;
	return (stat(path.c_str(), &buffer) == 0);
}

std::string getPath() {
	std::string path = "";
	while (!pathExits(path)) {
		std::cout << "Please Enter Path To The Save Files :" << std::endl;
		std::getline(std::cin, path);
	}
	return path;
}

bool extIsLockedUser(const fs::path& path) {
	return path == lockeduserExt;
}
bool extIsUnlockedUser(const fs::path& path) {
	return path == unlockeduserExt;
}
bool nonApplicationFile(const std::string& path) {
	auto extention = fs::path(path).extension();
	return !(extIsLockedUser(extention) || extIsUnlockedUser(extention));
}
bool nonUnlockedFile(const std::string& path) {
	return !(extIsUnlockedUser(fs::path(path).extension()));
}
void stripInvalidFilesAndPaths(std::vector<std::string>& files) {
	std::erase_if(files, nonApplicationFile);
}

std::vector<std::string> filesInFolder(const std::string& path) {
	std::vector<std::string> files;
	
	for (const std::filesystem::directory_entry& entry : fs::directory_iterator(path))
		files.push_back(entry.path().string());
	
	return files; 
}
std::vector<std::string> filteredFilesInFolder(const std::string& path) {
	std::vector<std::string> files;

	for (const std::filesystem::directory_entry& entry : fs::directory_iterator(path)) {
		std::string file = entry.path().string();
		if (!nonApplicationFile(file))
			files.push_back(file);
	}
	return files;
}
std::vector<std::string> unlockedFiles(std::vector<std::string> files) {
	std::erase_if(files, nonUnlockedFile);
	return files;
}

std::string open(const std::string& path) {
	std::ifstream targetFile(path);
	std::string output = "", line;

	if (!targetFile.is_open()) {
		std::error_code errorCode ;
		throw fs::filesystem_error::filesystem_error("Error Opening Target Path", errorCode);
	}

	while (getline(targetFile, line))
		output += line + "\n";

	return output;
}
std::vector<std::string> vectOpen(const std::string& path) {
	std::ifstream targetFile(path);
	std::string line;
	std::vector<std::string> output;

	if (!targetFile.is_open()) {
		std::error_code errorCode;
		throw fs::filesystem_error::filesystem_error("Error Opening Target Path", errorCode);
	}
	while (getline(targetFile, line)) {
		output.push_back(line);
	}
	return output;
}

void write(const std::string& data, const std::string& path) {
	std::ofstream targetFile(path);
	if (!targetFile.is_open()) {
		std::error_code errorCode;
		throw fs::filesystem_error::filesystem_error("Error Opening Target Path", errorCode);
	}

	targetFile << data;

	targetFile.close();
}

bool unlockFile(const std::string& path, const std::string& decriptionKey) {
	std::string fileContent;
	std::string newPath = path;

	newPath.erase(newPath.find(lockeduserExt), lockeduserExt.size()); // remove the file extention
	newPath += unlockeduserExt;

	if (!ValidLogIn(path, decriptionKey, fileContent)) {
		std::cout << "Unable to log in password may be wrong" << std::endl;
		return false;
	}
	try {
		write(fileContent, path);
		if (std::rename(path.c_str(), newPath.c_str()) != 0) {
			std::cout << "Contents was unlocked But Was unable to change file extention\n"; return false;
		}
		return true;
	}
	catch (...) {
		std::cout << "Unable to unlock file" << "\n"
			<< "File may be open in other another apllication" << "\n"
			<< "Aplication may not have high enough privlages to write to the file" << "\n";
		return false;
	}
}

bool lockFile(const std::string& path, const std::string& key) {
	std::string encryptedContent;
	std::string newPath = path;

	newPath.erase(newPath.find(unlockeduserExt), unlockeduserExt.size()); // remove the file extention
	newPath += lockeduserExt;

	try {
		encryptedContent = open(path);
		encryptData(key, encryptedContent);
	}
	catch (...) {
		std::cout << "Unable to open locked file reasons may be :" << "\n"
			<< "File is open in another apllication" << "\n"
			<< "Aplication may not have high enough privlages to write to the file" << "\n";
		return false;
	}
	try {
		write(encryptedContent, path);
		if (std::rename(path.c_str(), newPath.c_str()) != 0) {
			std::cout << "Contents was unlocked But Was unable to change file extention\nPlease Manualy change the extention"; 
			return false;
		}
	}
	catch (...) {
		std::cout << "Unable to lock file" << "\n"
			<< "File may be open in other another apllication" << "\n"
			<< "Aplication may not have high enough privlages to write to the file" << "\n";
		return false;
	}

	return true;
}

void printFile(const std::vector<std::string>& lineBrokenFileData) {
	struct local {
		static void numSpacesForEverypowerOfTen(int size, std::vector<std::string>& numSpaces) {
			size = std::to_string(size).length();
			for (int i = size; i > 0; i--) {
				std::string tmp = " ";
				for (int j = 0; j < i; j++) tmp += " ";
				numSpaces.push_back(tmp);}}

		static void numSpacesShow(const int& rowNum, const std::vector<std::string>& spacesPerPowerOfTen, std::string& spaces) 
			{ spaces = spacesPerPowerOfTen[std::to_string(rowNum).length() - 1]; }};

	std::vector<std::string> spaceForEachPwTen;
	local::numSpacesForEverypowerOfTen(lineBrokenFileData.size() + 1, spaceForEachPwTen);

	for (unsigned i = 0; i < lineBrokenFileData.size(); i++) {
		std::string spaces;
		local::numSpacesShow(i + 1, spaceForEachPwTen, spaces);
		std::cout << i + 1 << spaces << "- " << lineBrokenFileData[i] << "\n"; }
}