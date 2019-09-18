#include <string>
#pragma once
using namespace std;

class Animal {
	public:
		Animal();
		Animal(string type, string food);

		string getType();
		void setType(string type);
		string getFood();
		void setFood(string food);
		virtual string print();

	private:
		string type_;
		string food_;
};
