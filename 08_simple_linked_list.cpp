/*
    Simple List ADT

    Cristofer Costa
    cristofercosta@yahoo.com.br
*/


#include <iostream>


// Node class representing a single node in the linked list
class Node {
public:
    int data;        // Data stored in the node
    Node* next;      // Pointer to the next node in the list

    // Constructor
    Node(int value) : data(value), next(nullptr) {}
};


// LinkedList class representing the linked list
class LinkedList {
private:
    Node* head;      // Pointer to the head node of the list

public:
    // Constructor
    LinkedList() : head(nullptr) {}

    // Destructor
    ~LinkedList() {
        // Delete all nodes when the list is destroyed
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    // Insert a new node at the beginning of the list
    void insert(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Insert a new node at the end of the list
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            // If the list is empty, make the new node the head
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            // Insert the new node at the end
            current->next = newNode;
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

    // Print the elements of the list
    void printList() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << "\t";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Overload the std::ostream operator
    friend std::ostream& operator<< (std::ostream& out, const LinkedList& list){
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
    // Create a new linked list
    LinkedList myList;

    // Insert some elements into the list
    myList.insert(10);
    myList.insert(20);

    std::cout << myList;

    myList.insertAtEnd(30);
    myList.insertAtEnd(40);

    // Print the list
    myList.printList();

    // Search for values in the list
    std::cout << "Search 30: " << (myList.search(30) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search 50: " << (myList.search(50) ? "Found" : "Not Found") << std::endl;

    return 0;
}
