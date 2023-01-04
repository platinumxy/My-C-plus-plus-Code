#include "Header.h"
#include <filesystem> 
namespace fs = std::filesystem;

bool decryptData(const std::string& key, const std::string& data, std::string& output); //Encryption.cpp

std::string open(const std::string& path); // FileManager.cpp


bool ValidLogIn(const std::string& path, const std::string& decriptionKey, std::string& output) {
	std::string fileData;

	try { fileData = open(path); }
	catch (const fs::filesystem_error) {
		std::cout << "WARNING ERROR OPENING => " << path << std::endl;
		return false; }

	if (decryptData(decriptionKey, fileData, output)) 
		return true;
	
	output = "";
	return false;
}

