#include "Header.h"

/*


To encode :
- Creates an extended key that can hold the hash of the key and its numecic length plus the data 
- Adds the length of the extended key and the md5 Hash of the key the start of the data 
- XORs every bite in the target file agaisnt the extended key 


To Decode :
Args :
	const std::string& key ->	key used for decription
	const std::string& data ->	data to decript
	std::string& output -> 
								AN EMPTY STRING variable that will hold the decripted data 
								WARNING will be junk bites if conversion was unsuccessfull
Output:
	bool based on if the decription created a valid variable 

- creates an extended key that can be used to decrypt the whole block of data 
- XORs the output 
*/

const int PRIME_CONST = 31;

double hashFunction(const std::string& key) {
	double hashCode = 0;
	for (size_t i = 0; i < key.length(); i++) {
		hashCode += key[i] * pow(PRIME_CONST, i);
	}
	return hashCode;
}

void encryptData(const std::string& key, std::string& data) {
	std::string extendedKey = key;
	std::string keyHash = std::to_string(hashFunction(key));

	//while the length of the extended key is to small to contain the data and the string representation of the extended keys length and the md5 length
	while (extendedKey.length() < (data + std::to_string(extendedKey.length())).length() + keyHash.length())
		extendedKey += key; 

	data = std::to_string(extendedKey.length()) + keyHash + data;

	for (size_t i = 0; i < data.length(); i++)
		data[i] = data[i] ^ extendedKey[i]; //xors every bite against its coresponding bite in the extended key
}

bool decryptData(const std::string& key, const std::string& data, std::string& output) {
	output = "";
	std::string extendedKey = key;

	while (extendedKey.length() < data.length())
		extendedKey += key;
	std::string desiredPrefix = std::to_string(extendedKey.length()) + std::to_string(hashFunction(key));

	for (size_t i = 0; i < data.length(); i++) 
		output += data[i] ^ extendedKey[i];

	for (size_t i = 0; i < desiredPrefix.length(); i++) {
		if (desiredPrefix[i] != output[i])
			return false;
	}
	output.erase(0, desiredPrefix.length());// remove the desired prefix 
	return true;
}