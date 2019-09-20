// Pet.cpp
#include "Pet.h"
#include "Animal.h"
Pet::Pet() : Animal() {
    name_ = "Fluffy";
    owner_name_ = "Cinda";
}
void Pet::setFood(std::string n) {
    food_ = n;
}
std::string Pet::getFood() {
    return food_;
}
std::string Pet::return_name() {
    return "My name is " + name_;
}

void Pet::setName(std::string n) {
    name_ = n;
}
std::string Pet::getName() {return name_;}
void Pet::setOwnerName(std::string n) {owner_name_ = n;}
std::string Pet::getOwnerName() {return owner_name_;}

Pet::Pet(std::string type, std::string food, std::string name, std::string owner_name)
      : Animal(type,food), name_(name), owner_name_(owner_name) { }