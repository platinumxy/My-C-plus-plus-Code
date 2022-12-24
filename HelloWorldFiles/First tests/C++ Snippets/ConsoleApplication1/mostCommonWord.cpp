#include "resource.h"
#include <map>
#include <algorithm>

std::string lower(std::string str) {
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	return str;
}

std::string mostCommonWord(std::vector<std::string> words, bool strict = false) {
	struct commonWord {
		std::string word;
		int count;
	};

	std::map<std::string, int> WORDS;
	std::string word; 
	commonWord mostCommon{ "NULL", -1 };

	for (int i = 0; i < words.size(); i++) {
		if (strict) word = words[i];
		else        word = lower(words[i]);

		if (WORDS.count(word) == 1)  WORDS[word]++;
		else                         WORDS.insert(std::pair<std::string, int>(word, 1));
		
		if (WORDS[word] > mostCommon.count) mostCommon = { word, WORDS[word] };
	}
	return mostCommon.word;
}