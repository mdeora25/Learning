// Your code here
#include <string>
#include"potd.h"
string getFortune(const string &s) {
	int fortune_number = s.length() % 5; 
	if (fortune_number == 0) {
		return "Yes";
	}
	else if (fortune_number == 1) {
		return "No";
	}
	else if (fortune_number == 2) {
		return "I'm ";
	}
	else if (fortune_number == 3) {
		return "Yes, no";
	}
	return "Absolutely";
}