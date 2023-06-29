/*
    Peer-graded Assignment: Homework 2
    Dijkstra's Algorithm

    Cristofer Costa
    cristofercosta@yahoo.com.br
*/

#include <iostream>
#include <list>
#include <vector>
#include <ctime>
#include <random>

using namespace std;


// Class to store the Edge data. 
class Edge {
public:
    unsigned short _cost;           // Edge positive cost (distance)
    unsigned short _v;              // Vertex v - origin
    unsigned short _w;              // Vertex w - destination

    Edge(unsigned short cost,
         unsigned short v,
         unsigned short w) : _cost(cost),
                             _v(v),
                             _w(w) {}
};


// Class to implement a Node wrapper
class Node {
private:
    list<Edge*> _edges;             // List of edges        
    unsigned short _id;             // Node id

public:
    // Constructor
    Node(unsigned short id);

    // Destructor
    ~Node();

    // Add a new edge to the Node
    void add_edge(unsigned short cost,
                  unsigned short v,
                  unsigned short w);

    // Print out all edges from the Node
    void print_edges();

    // Return the number of edges from the Node
    int edges_size(){return _edges.size();};
};

Node::Node(unsigned short id): _id(id) {
    // Constructor
    // cout << "New Node #" << id << " object instantiated." << endl;
}

Node::~Node(){
    // Delete all Edges when the Node is destroyed
    cout << "Destroing Node #" << _id << " object" << endl;
    list<Edge*>::iterator it;
    for (it = _edges.begin(); it != _edges.end(); it++){
        cout << "Destroing Edge (v: " << (*it)->_v;
        cout << ", w: " << (*it)->_w << ")" << endl;
        delete *it;
    }
}

void Node::add_edge(unsigned short cost,
                    unsigned short v,
                    unsigned short w) {
    // Create a new Edge fo the Node
    Edge* new_edge = new Edge(cost, v, w);
    _edges.push_back(new_edge);
    // cout << "New edge created." << endl;
}

void Node::print_edges(){
    // Print all edges conected to the Node
    cout << "Node id #" << _id << ":" << endl;
    list<Edge*>::iterator it;
    for (it = _edges.begin(); it != _edges.end(); it++){
        cout << "\t" << "Edge (v: " << (*it)->_v;
        cout << ", w: " << (*it)->_w << "),";
        cout << " cost: " << (*it)->_cost << endl;
    }
}


// Class to implement a Graph
class Graph
{
private:
    vector<Node*> _nodes;
public:
    // Constructor
    Graph(/* args */);

    // Destructor
    ~Graph();

    // Return the number of Nodes of the Graph
    int nodes_size(){return _nodes.size();};

    // Return the number of Edges of the Graph
    int edges_size();

    // Add node to the Graph
    void add_node(Node* node_ptr){_nodes.push_back(node_ptr);};

    // Print Nodes and its Edges from the Graph
    void print_nodes();

    // Generate random data
    void random_graph(unsigned short nodes,
                      double edge_density,
                      unsigned short distance_range);
};

Graph::Graph(/* args */){
    // Constructor
    // cout << "New Graph object instantiated." << endl;
}

Graph::~Graph(){
    cout << "Destroing Graph object" << endl;
    vector<Node*>::iterator it;
    for (it=_nodes.begin(); it!=_nodes.end(); it++){
        delete *it;
    }
}

int Graph::edges_size(){
    int sum = 0;
    vector<Node*>::iterator it;
    for (it=_nodes.begin(); it!=_nodes.end(); it++){
        sum += (*it)->edges_size();
    }
    return sum;
}

void Graph::print_nodes(){
    // Print Nodes and its Edges from the Graph
    vector<Node*>::iterator it;
    for (it=_nodes.begin(); it!=_nodes.end(); it++){
        (*it)->print_edges();
    }
}

void Graph::random_graph(unsigned short nodes,
                         double edge_density,
                         unsigned short distance_range){
    // This function aims to create a random graph
    Node* node;
    default_random_engine generator(time(0));
    uniform_int_distribution<unsigned> random_nodes(1, nodes),
                                       random_edges(0,4),
                                       random_distance(1, distance_range);
    int cost, destination;
    cout << "\nrandom Graph being generated.\n";
    for (int i = 0; i < nodes; i++){
        node = new Node(i);
        for (int j = random_edges(generator); j < 5; j++){
            cost = random_distance(generator);
            node->add_edge(cost, i, random_nodes(generator));
        } 
        add_node(node);
    }
}


int main(int argc, const char * argv[]) {
    
    /* Manual Graph creation */ 
    cout << "\nManual Graph creation:\n";   
    Graph graph;
    Node* node_ptr = new Node(1);
    node_ptr->add_edge(1,1,2), node_ptr->add_edge(2,1,3);
    cout << "\nPrinting all the edges from a node:\n";
    node_ptr->print_edges();
    cout << "\nPrinting additional node information:\n";
    cout << "Edges size: " << node_ptr->edges_size() << endl;
    cout << "\nAdding a node manually to a Graph object:\n";
    graph.add_node(node_ptr);
    cout << "Graph size: " << graph.nodes_size() << " node(s).\n\n";

    /* Automatic Graph creation*/
    cout << "\n\nAutomatic Graph creation:\n";
    Graph graph_random;
    graph_random.random_graph(10,1,10);
    cout << "\nPrinting Graph information:\n";
    cout << "Nodes size: " << graph_random.nodes_size() << endl;
    cout << "Edges size: " << graph_random.edges_size() << endl;
    graph_random.print_nodes();

    return 0;
}