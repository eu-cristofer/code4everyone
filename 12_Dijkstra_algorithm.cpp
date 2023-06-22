/*
    Peer-graded Assignment: Homework 2
    Dijkstra's Algorithm

    Cristofer Costa
    cristofercosta@yahoo.com.br
*/

#include <iostream>

using namespace std;


// Class to store the data of a doubly linked list.
// The Node is the unit element of the list.
class Edge {
public:
    unsigned int coast;         // Data stored in the node
    Node* prev;                 // Pointer to the previous node in the list
    Node* next;                 // Pointer to the next node in the list

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

// Class to store the data of a doubly linked list.
// The Node is the unit element of the list.
class Node {
public:
    int id;         // Data stored in the node
    Node* prev;       // Pointer to the previous node in the list
    Node* next;       // Pointer to the next node in the list

    Node(int value) : id(value), prev(nullptr), next(nullptr) {}
};


class Graph
{
private:
    /* data */
public:
    Graph(/* args */);
    ~Graph();
};

Graph::Graph(/* args */)
{
}

Graph::~Graph()
{
}


int main(int argc, const char * argv[]) {
    
    /* code */

    cout << "Hello world!";
    
    return 0;
}