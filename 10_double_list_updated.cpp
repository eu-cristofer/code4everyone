
/*
    Improved double linked list
    This code insert functionalties in double
    linked list: Cursor; prepend; and append.

    Cristofer Costa
    cristofercosta@yahoo.com.br
*/

#include <iostream>

class Node {
public:
    int data;         // Data stored in the node
    Node* prev;       // Pointer to the previous node in the list
    Node* next;       // Pointer to the next node in the list

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;       // Pointer to the head node of the list
    Node* tail;       // Pointer to the tail node of the list
    Node* cursor;     // Pointer to the actual node

public:
    DoublyLinkedList();

    ~DoublyLinkedList();

    void prepend(int);
    // Insert a new node at the beginning of the list - LIFO

};

DoublyLinkedList::DoublyLinkedList()
    // Default constructor definiton
    : head(nullptr)
    , tail(nullptr) 
    , cursor(nullptr)
{}

DoublyLinkedList::~DoublyLinkedList(){
    // Delete all nodes when the list is destroyed
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void DoublyLinkedList::prepend(int value){
    Node* new_node = new Node(value);
    if (head == nullptr) {
        // List is empty, make the new node both head and tail
        head = new_node;
        tail = new_node;
        cursor = new_node;
    } else {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
}

int main() {
    
    DoublyLinkedList myList, fList, bList;

    std::cout << "\nLIFO list ADT:\n";
    bList.prepend(10);
    bList.prepend(20);
    bList.prepend(30);

    
    return 0;
}
