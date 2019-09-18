#include "Animal.h"
#include <string>

using namespace std;

Animal::Animal() {
	type_ = "cat";
	food_ = "fish";
}

Animal::Animal(string type, string food) {
	type_ = type;
	food_ = food;
}

string Animal::getType() {
	return type_;
}

void Animal::setType(string type) {
	type_ = type;
}

string Animal::getFood() {
	return food_;
}

void Animal::setFood(string food) {
	food_ = food;
}

string Animal::print() {
	return "I am a " + type_;
}// Animal.cpp
