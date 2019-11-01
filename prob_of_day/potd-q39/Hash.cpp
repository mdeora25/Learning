#include <vector>
#include <string>
#include "Hash.h"

using namespace std;

int hashFunction(string s, int M) {
   // Your Code Here
   //hash function to sum up the ASCII characters of the letters of the string
   int sum = 0;
   for (int i = 0; s[i] != '\0'; i++){
     sum = sum + s[i];
   }
   return sum % M;
 }

int countCollisions (int M, vector<string> inputs) {
	int collisions = 0;
	// Your Code Here


  int filled_array[M + 1];  //default to 0
  for(unsigned long i = 0; i < inputs.size(); i++){
    int key = hashFunction(inputs[i], M);
    if(filled_array[key] == 1){
      collisions++;
    }
    filled_array[key] = 1;
  }
	
	return collisions;
}
