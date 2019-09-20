// Pet.h
#pragma once
#include "Animal.h"
class Pet : public Animal {
    private:
        std::string name_;
        std::string owner_name_;
    public:
        Pet();
        void setFood(std::string n);
        std::string getFood();
        void setName(std::string n);
        std::string getName();
        void setOwnerName(std::string n);
        std::string getOwnerName();
        std::string return_name();
        Pet(std::string type, std::string food, std::string name, std::string owner_name);








};