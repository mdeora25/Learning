#include <unordered_map>

using namespace std;

unordered_map<string, int> common_elems(unordered_map<string, int> mapA,
                                        unordered_map<string, int> mapB) {

    unordered_map<string, int> result;

	unordered_map<string, int> & longerMap = mapA.size() < mapB.size() ? mapB : mapA;
	unordered_map<string, int> & shorterMap = mapA.size() >= mapB.size() ? mapB : mapA;

    for (auto elem : longerMap) {
    	if (shorterMap.find(elem.first) != shorterMap.end()) {
    		pair<string, int> new_pair (elem.first, elem.second + shorterMap[elem.first]);
    		result.insert(new_pair);
    	}
    }

    for (auto elem : result) {
    	shorterMap.erase(elem.first);
    	longerMap.erase(elem.first);
    }

    return result;
} 