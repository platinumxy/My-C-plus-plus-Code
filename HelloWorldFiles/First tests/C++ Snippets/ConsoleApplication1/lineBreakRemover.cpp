#include "resource.h"

std::string lineBreakRemover(std::vector<std::string> data, std::string sep = " ") {
	std::string message = data[0];
	for (int i = 1; i < data.size(); i++)
	{
		if (data[i] != "" || data[i] != " "){
			message.append(" " + data[i]);
		}
	}
	return message;
}
	

std::string lineBreakRemover(std::string sep=" ") {
	std::cout << "Please enter your data you want to remove the line breaks from" << std::endl
		<< "End your data with '====MESSAGEOVER====' on its own line" << std::endl << std::endl;
	std::vector<std::string> data; 
	std::string tmp;
	while (true) {
		std::getline(std::cin, tmp);
		if (tmp == "====MESSAGEOVER====") {
			break;
		}
		data.push_back(tmp);
	}
	return lineBreakRemover(data, sep);
}