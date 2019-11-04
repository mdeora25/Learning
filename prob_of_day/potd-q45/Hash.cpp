#include <vector>
#include "Hash.h"

void doubleHashInput(std::vector<int> &v, int elem){
	//your code here
  int idx = firstHash(elem, v.size());
	int jump = secondHash(elem);
	while (v[idx] != -1) {
		idx = (idx + jump) % v.size();
	}
  	v[idx] = elem;
}
int firstHash(int elem, int length) {
  int index = elem * 4;
  index = index % length;
  return index;
}
int secondHash(int elem) {
  return (3- (elem%3));
}
//make a hash function called firstHash
//make a second function called secondHash
