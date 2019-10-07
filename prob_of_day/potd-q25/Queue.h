#pragma once
#include <vector>
#include <cstddef>

class Queue {
    public:
        Queue();
        int size() const;
        bool isEmpty() const;
        void enqueue(int value);
        int dequeue();
        ~Queue();
        std::vector<int> v;
};