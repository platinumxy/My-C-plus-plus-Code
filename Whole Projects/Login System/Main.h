#pragma once

void getAction(const std::vector<std::string>& options, unsigned int& action, const std::string& message); // Main.cpp
int mainActionLoop(const std::string& savePath, std::vector<std::string>& users); // Main.cpp
void unlockedUsersAction(const std::string& genericPath, std::vector<std::string>& users); // Main.cpp

std::string getPath(); // FileManager.cpp
std::vector<std::string> filesInFolder(const std::string& path); // FileManager.cpp
std::vector<std::string> filteredFilesInFolder(const std::string& path); // FileManager.cpp
void stripInvalidFilesAndPaths(std::vector<std::string>& files); // FileManager.cpp 
std::vector<std::string> unlockedFiles(std::vector<std::string>& files); //FileManager.cpp

void encryptData(const std::string& key, std::string& data); // Encryption.cpp
bool decryptData(const std::string& key, const std::string& data, std::string& output); // Encryption.cpp

bool validLogIn(const std::string& path, const std::string& decriptionKey, std::string& output); // LoginManager.cpp
int unlockedFileManager(const std::string& unlockedFilePath); //LoginManager.cpp
void login(const std::string&); // LoginManager.cpp
bool signUp(const std::string& basePath, std::string& newName); // LoginManager.cpp