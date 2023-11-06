
/*
    Improved doubly linked list
    This code insert functionalties in double
    linked list: Cursor; prepend; and append.

    Cristofer Costa
    cristofercosta@yahoo.com.br
*/

#include <iostream>


// Class to store the data of a doubly linked list.
// The Node is the unit element of the list.
class Node {
public:
    int data;         // Data stored in the node
    Node* prev;       // Pointer to the previous node in the list
    Node* next;       // Pointer to the next node in the list

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};


// Class to implement the wrapper of the list controlling the flow 
// of creation and access to each Node.
class DoublyLinkedList {
private:
    Node* head;       // Pointer to the head node of the list
    Node* tail;       // Pointer to the tail node of the list
    Node* _cursor;    // Pointer to the actual node
    int _length;      // Int ti store the number of nodes in the list

public:
    // Default constructor
    DoublyLinkedList();
    
    // Destructor
    ~DoublyLinkedList();
    
    // Returns how many nodes does the list has
    int length();
    
    // Insert a new node at the beginning of the list - LIFO
    void prepend(int value);
    
    // Insert a new node at the end of the list - FIFO
    void append(int value);
    
    // Search for a value in the list
    bool search(int value);
    
    // Overloaded operator<< for printing the list
    friend std::ostream& operator<<(std::ostream& out, const DoublyLinkedList& list);
    
    // Print the whole list stanrting with the last element
    void print_backward();
    
    // Return the data of the current node and engage the next
    int cursor();
    
    // Return the cursor to the first element of the list
    void reset_cursor();
};

DoublyLinkedList::DoublyLinkedList()
    // Default constructor definiton
    : head(nullptr)
    , tail(nullptr) 
    , _cursor(nullptr)
    , _length(0)
{}

DoublyLinkedList::~DoublyLinkedList(){
    // Delete all nodes when the list is destroyed
    _cursor = head;
    while (_cursor != nullptr) {
        _cursor = head->next;
        delete head;
        head = _cursor;
    }
    std::cout << "DoublyLinkedList Nodes erased!\n";
}

int DoublyLinkedList::length(){
    // Returns how many Nodes does the list has
    return _length;
}

void DoublyLinkedList::prepend(int value){
    // Insert a new node at the beginning of the list - LIFO
    Node* new_node = new Node(value);
    if (head == nullptr) {
        // List is empty, make the new node both head and tail
        head = new_node;
        tail = new_node;
        _cursor = new_node;
        ++_length;
    } else {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
        _cursor = new_node;
        ++_length;
    }
}

void DoublyLinkedList::append(int value){
    // Insert a new node at the end of the list - FIFO
    Node* new_node = new Node(value);
    if (head == nullptr){
        // List is empty, make the new node both head and tail
        head = new_node;
        tail = new_node;
        _cursor = new_node;
        ++_length;
    } else {
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
        ++_length;
    }
}

bool DoublyLinkedList::search(int value){
    // Search for a value in the list
    Node* current = head;
    while (current != nullptr){
        if (current->data == value){
            return true;                // Value found.
        }
        current = current->next;
    }
    return false;                       // Value not found.
}

std::ostream& operator<<(std::ostream& out, const DoublyLinkedList& list){
    // Overloaded operator<< for printing the list
    Node* current = list.head;
    while (current != nullptr) {
        out << current->data << "\t";
        current = current->next;
    }
    out << std::endl;
    return out;
}

void DoublyLinkedList::print_backward(){
    // Print the whole list stanrting with the last element
    Node* current = tail;
    while (current != nullptr) {
        std::cout << current->data << "\t";
        current = current->prev;
    }
    std::cout << std::endl;
}

int DoublyLinkedList::cursor(){
    // Return the data of the current node and engage the next
    if (_cursor != nullptr){
        Node* current = _cursor;
        _cursor = current->next;
        return current->data;
    } else {
        return 0;
    }   
}

void DoublyLinkedList::reset_cursor(){
    // Returns the cursor to the first element of the list
    _cursor = head;
}

int main() {
    
    DoublyLinkedList myList, fList, bList;

    std::cout << "\nLIFO list ADT:\n";
    bList.prepend(10);
    bList.prepend(20);
    bList.prepend(30);
    std::cout << bList;
    std::cout << "LIFO backward print:\n";
    bList.print_backward();
    std::cout << "LIFO cursor call:\n";
    for (int i = 0; i < bList.length(); i++){
        std::cout << bList.cursor() << std::endl;
    }

    std::cout << "LIFO cursor call before cursor_reset():\n";
    for (int i = 0; i < bList.length(); i++){
        std::cout << bList.cursor() << std::endl;
    }

    bList.reset_cursor();
    std::cout << "LIFO cursor call after cursor_reset():\n";
    for (int i = 0; i < bList.length(); i++){
        std::cout << bList.cursor() << std::endl;
    }

    std::cout << "\nFIFO list ADT:\n";
    fList.append(10);
    fList.append(20);
    fList.append(30);
    std::cout << fList;
    std::cout << "FIFO backward print:\n";
    fList.print_backward();
    std::cout << "FIFO cursor call:\n";
    for (int i = 0; i < fList.length(); i++){
        std::cout << fList.cursor() << std::endl;
    }

    std::cout << "\nMixed use (prepend(10),prepend(20),append(30),append(40)):\n";
    myList.prepend(10);
    myList.prepend(20);
    myList.append(30);
    myList.append(40);
    std::cout << myList << std::endl;

    // Search for values in the list
    std::cout << "\nSearch features:\n";
    std::cout << "Search 30: " << (fList.search(30) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search 50: " << (fList.search(50) ? "Found" : "Not Found") << std::endl;
    
    return 0;
}
