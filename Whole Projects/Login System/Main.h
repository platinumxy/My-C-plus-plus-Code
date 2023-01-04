#pragma once

void getAction(unsigned int& action); // Main.cpp
int mainActionLoop(std::vector<std::string>& users, const std::string& savePath); // Main.cpp


std::string getPath(); // FileManager.cpp

std::vector<std::string> filesInFolder(const std::string& path); // FileManager.cpp
void stripInvalidFilesAndPaths(std::vector<std::string>& files); // FileManager.cpp 
std::vector<std::string> unlockedFiles(std::vector<std::string> files); //FileManager.cpp

void encryptData(const std::string& key, std::string& data); // Encryption.cpp
bool decryptData(const std::string& key, const std::string& data, std::string& output); // Encryption.cpp

bool ValidLogIn(const std::string& path, const std::string& decriptionKey, std::string& output); // LoginManager.cpp
