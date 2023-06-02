
/*
    
    Double Linked List

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

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    ~DoublyLinkedList() {
        // Delete all nodes when the list is destroyed
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    // Insert a new node at the beginning of the list - LIFO
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            // List is empty, make the new node both head and tail
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Insert a new node at the end of the list - FIFO
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            // List is empty, make the new node both head and tail
            head = newNode;
            tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Search for a value in the list
    bool search(int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                // Value found
                return true;
            }
            current = current->next;
        }
        // Value not found
        return false;
    }

    // Backward print the elements of the list
    void printListBack() {
        Node* current = tail;
        while (current != nullptr) {
            std::cout << current->data << "\t";
            current = current->prev;
        }
        std::cout << std::endl;
    }

    // Overloaded operator<< for printing the list
    friend std::ostream& operator<<(std::ostream& out, const DoublyLinkedList& list) {
        Node* current = list.head;
        while (current != nullptr) {
            out << current->data << "\t";
            current = current->next;
        }
        out << std::endl;
        return out;
    }
};

int main() {
    
    DoublyLinkedList myList, fList, bList;

    std::cout << "FIFO list ADT:\n";
    fList.insertAtEnd(10);
    fList.insertAtEnd(20);
    fList.insertAtEnd(30);
    std::cout << fList;                     // Print the list using the overloaded operator<<
    std::cout << "FIFO backward print:\n";
    fList.printListBack();

    std::cout << "\nLIFO list ADT:\n";
    bList.insertAtBeginning(10);
    bList.insertAtBeginning(20);
    bList.insertAtBeginning(30);
    std::cout << bList;
    std::cout << "LIFO backward print:\n";
    bList.printListBack();

    std::cout << "\nMixed use (insert(10),insert(20),insertAtEnd(30),insertAtEnd(40)):\n";
    myList.insertAtBeginning(10);
    myList.insertAtBeginning(20);
    myList.insertAtEnd(30);
    myList.insertAtEnd(40);
    std::cout << myList << std::endl;

    // Search for values in the list
    std::cout << "Search 30: " << (myList.search(30) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search 50: " << (myList.search(50) ? "Found" : "Not Found") << std::endl;

    return 0;
}


