#include "sort.h"
#include <algorithm>

LinkedList::~LinkedList() {
    while (head != nullptr) {
        Node* next = head->next;
        delete head;
        head = next;
    }
}

void LinkedList::push_front(int v) {
    Node* new_node = new Node{v, head};
    head = new_node;
    size++;
}

LinkedList LinkedList::from_vector(const std::vector<int>& v) {
    LinkedList list;
    for (int i = v.size() - 1; i >= 0; --i) {
        list.push_front(v[i]);
    }
    return list;
}

void sort_insertion(LinkedList& list) {
    if (list.head == nullptr || list.head->next == nullptr) { return; } //List is already sorted

    Node* sorted = nullptr;

    while (list.head != nullptr) {
        Node* current = list.head;
        list.head = list.head->next;
        if (sorted == nullptr || current->value < sorted->value) {
            current->next = sorted;
            sorted = current;
        } else {
            Node* temp = sorted;
            while (temp->next != nullptr && temp->next->value < current->value) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
    }
    list.head = sorted;
}

void sort_merge(LinkedList& list) {
    if (list.head == nullptr || list.head->next == nullptr) {return;} //List is already sorted

    // Split the list into two halves
    Node* slow = list.head;
    Node* fast = list.head->next;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* mid = slow->next;
    slow->next = nullptr;

    LinkedList left_list;
    left_list.head = list.head;
    left_list.size = 0; // Size will be recalculated

    LinkedList right_list;
    right_list.head = mid;
    right_list.size = 0; // Size will be recalculated

    sort_merge(left_list);
    sort_merge(right_list);

    // Merge the two sorted halves
    Node* merged_head = nullptr;
    Node** merged_tail = &merged_head;

    Node* left_node = left_list.head;
    Node* right_node = right_list.head;

    while (left_node != nullptr && right_node != nullptr) {
        if (left_node->value < right_node->value) {
            *merged_tail = left_node;
            left_node = left_node->next;
        } else {
            *merged_tail = right_node;
            right_node = right_node->next;
        }
        merged_tail = &((*merged_tail)->next);
    }

    if (left_node != nullptr) {
        *merged_tail = left_node;
    } else {
        *merged_tail = right_node;
    }

    list.head = merged_head;
    left_list.head = nullptr; // Avoid double deletion
    right_list.head = nullptr; // Avoid double deletion
    
    int new_size = 0; // Recalculate size
    Node* current = list.head;
    while (current != nullptr) {
        new_size++;
        current = current->next;
    }
    list.size = new_size;
}