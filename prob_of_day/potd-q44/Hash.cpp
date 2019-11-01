#include <vector>
#include <string>
#include <iostream>
#include "Hash.h"

unsigned long HashTable::bernstein(std::string str, int M)
{
    unsigned long b_hash = 5381;
    for (int i = 0; i < (int)str.length(); ++i)
    {
        b_hash = b_hash * 33 + str[i];
    }
    return b_hash % M;
};

HashTable::HashTable(int M)        // M is the size of the hash table
{
    table = new std::vector<std::string>[M];
    this->M = M;
};

void HashTable::printKeys()        // Function to print all keys in the hash table
{
    for(int i = 0; i < M; ++i)
        for (auto it = table[i].begin(); it!= table[i].end(); ++it)
            std::cout<<*it<<std::endl;
};

void HashTable::insert(std::string str)         //Inserts str into the hash table; must handle duplicates!
{
    // your code here
    unsigned long cur_hash = bernstein(str, M);
    if (!table[cur_hash].empty() && contains(str)) return;
    table[cur_hash].insert(table[cur_hash].begin(), str);
};

bool HashTable::contains(std::string str)       //Checks if the hash table contains str
{
    // your code here
     unsigned long cur_hash = bernstein(str, M);
    auto it = table[cur_hash].begin();
    while (it != table[cur_hash].end()) {
        if (*it == str) return true;
        it++;
    }
    return false;
};

