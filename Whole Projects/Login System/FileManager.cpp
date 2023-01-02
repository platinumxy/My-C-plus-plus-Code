#include "Header.h" 
#include <sys/stat.h>
#include <filesystem> 

namespace fs = std::filesystem;
bool pathExits(const std::string& path)
{
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

