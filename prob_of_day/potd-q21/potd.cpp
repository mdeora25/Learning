#include "potd.h"

// Your code here!
double sum(vector<double>::iterator start, vector<double>::iterator end) {
    double ans = 0;
    for (auto i = start; i != end; i++) {
        ans += *i;
    }
    return ans;
 }

/** Returns an iterator that points to the element with the largest value between start and end. */
vector<double>::iterator max_iter(vector<double>::iterator start, vector<double>::iterator end) {
    vector<double>::iterator res = start;
    for (auto i = start; i != end; i++) {
		if (*i > *res) res = i;
	}
	return res;
}

/** Sort, in descending order, part of an array between start to end. 
	Hint: use max_iter.
*/
void sort_vector(vector<double>::iterator start, vector<double>::iterator end) {
    for (auto i = start; i != end; i++) {
            vector<double>::iterator j = max_iter(i, end);
            if (*i != *j) {
                double temp = *i;
                *i = *j;
                *j = temp;
            }
        }

}