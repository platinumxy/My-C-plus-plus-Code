#include "Header.h"


std::string getPath();//FileManager.cpp

std::vector<std::string> filesInFolder(const std::string& path); // FileManager.cpp



int main() {

	const std::string saveFilePath = getPath();
	
	std::vector<std::string> users = filesInFolder(saveFilePath);
	
	
	return 0;
}


