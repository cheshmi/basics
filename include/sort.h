#ifndef BASICS_SORT_H
#define BASICS_SORT_H

#include <vector>

struct Node {
    int value;
    Node* next;
};

class LinkedList {
public:
    Node* head = nullptr;
    int size = 0;

    ~LinkedList();
    void push_front(int v);
    static LinkedList from_vector(const std::vector<int>& v);
};

void sort_insertion(LinkedList& list); //O(n^2)
void sort_merge(LinkedList& list); //O(n log n)

#endif //BASICS_SORT_H