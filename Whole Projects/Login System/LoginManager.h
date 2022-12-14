#pragma once
#include <fstream>
#include <filesystem> 
#include <algorithm> 
#include <cmath>

namespace fs = std::filesystem;

bool decryptData(const std::string& key, const std::string& data, std::string& output); //Encryption.cpp
void encryptData(const std::string& key, std::string& data); //Encryption.cpp

bool pathExits(const std::string& path); //FileManager.cpp
std::string open(const std::string& path); // FileManager.cpp
void write(const std::string& data, const std::string& path); // FileManager.cpp
std::vector<std::string> vectOpen(const std::string& path); // FileManager.cpp
std::string open(const std::string& path); // FileManager.cpp
void printFile(const std::vector<std::string>& lineBrokenFileData); // FileManager.cpp
bool lockFile(const std::string& path, const std::string& key); // FileManager.cpp
bool unlockFile(const std::string& path, const std::string& decriptionKey); // FileManager.cpp
bool deleteFile(const std::string& filePath); // FileManager.cpp
bool deleteLine(const std::string& filePath, const unsigned int& row); //FileManager.cpp


void getAction(const std::vector<std::string>& options, unsigned int& action, const std::string& message); //Main.cpp

int unlockedFileManager(const std::string& unlockedFilePath); // Self
bool lockAndCloseFile(const std::string unlockedFilePath, const std::string& fileName); // Self
void removePathAndFileExtention(std::string& userName, const std::string& fileExtention); // Self
std::string getPword(const std::string& fileName); // Self
void userDeleteLine(std::vector<std::string>& lineBrokenFileData, const std::string& unlockedFilePath); //Self