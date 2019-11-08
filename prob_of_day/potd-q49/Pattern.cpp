#include "Pattern.h"
#include <string>
#include <iostream>
#include <vector>
#include <map>
bool wordPattern(std::string pattern, std::string str) {

    //write your code here
    std::vector<string> words;
	string curword = ""; 
	for (auto c: str) {
		if (c == ' ') {
			words.push_back(curword);
			curword = "";
		}
		else {
			curword += c;
		}
	}

	words.push_back(curword);

	if (pattern.length() != words.size()) return false;

	std::map<char, string> nicemap;
	std::map<string, char> nicemap2;
	for (size_t i = 0; i < words.size(); i++) {
		if (nicemap[pattern[i]] == "" && nicemap2[words[i]] == '\0') {
			nicemap[pattern[i]] = words[i];
			nicemap2[words[i]] = pattern[i];
		}
		else if (nicemap[pattern[i]] != words[i] || nicemap2[words[i]] != pattern[i]) 
			return false;
	}
	return true;
}

