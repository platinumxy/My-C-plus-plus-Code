#include "Header.h" 
#include <sys/stat.h> // for checking pathExists 
#include <filesystem> 
#include <fstream>

namespace fs = std::filesystem;

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


std::vector<std::string> filesInFolder(const std::string& path) {
	std::vector<std::string> files;
	
	for (const std::filesystem::directory_entry& entry : fs::directory_iterator(path))
		files.push_back(entry.path().string());
	
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
std::vector<std::string> unlockedFiles(std::vector<std::string> files) {
	std::erase_if(files, nonUnlockedFile);
	return files;
}