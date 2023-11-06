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
    unsigned short _v;              // Vertex v - origin
    unsigned short _w;              // Vertex w - destination
    unsigned short _cost;           // Edge positive cost (distance)

    Edge(unsigned short v,
         unsigned short w,
         unsigned short cost) : _v(v),
                                _w(w),
                                _cost(cost) {}
};


// Class to implement a Vertex wrapper
class Vertex {
private:
    list<Edge*> _edges;             // List of edges        
    unsigned short _id;             // Vertex id

public:
    // Constructor
    Vertex(unsigned short id);

    // Destructor
    ~Vertex();

    // Add a new edge to the Vertex
    void add_edge(unsigned short v,
                  unsigned short w,
                  unsigned short cost);

    // Print out all edges of the Vertex
    void print_edges();

    // Return the number of edges from the Vertex
    int edges_size(){return _edges.size();};
};

Vertex::Vertex(unsigned short id): _id(id) {
    // Constructor
    cout << "New Vertex #" << id << " object instantiated." << endl;
}

Vertex::~Vertex(){
    // Destructor
    // Delete all Edges when the Vertex is destroyed
    cout << "Destroing Vertex #" << _id << " object" << endl;
    list<Edge*>::iterator it;
    for (it = _edges.begin(); it != _edges.end(); it++){
        cout << "Destroing Edge (v: " << (*it)->_v;
        cout << ", w: " << (*it)->_w << ")" << endl;
        delete *it;
    }
}

void Vertex::add_edge(unsigned short v,
                      unsigned short w,
                      unsigned short cost) {
    // Create a new Edge for the Vertex
    Edge* new_edge = new Edge(v, w, cost);
    _edges.push_back(new_edge);
    // cout << "New edge created." << endl;
}

void Vertex::print_edges(){
    // Print all edges conected to the Vertex
    cout << "Vertex id #" << _id << ":" << endl;
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
    vector<Vertex*> _vertices;
public:
    // Constructor
    Graph();

    // Destructor
    ~Graph();

    // Return the number of Vertcies of the Graph
    int vertices_size(){return _vertices.size();};

    // Return the number of Edges of the Graph
    int edges_size();

    // Add Vertex to the Graph
    void add_vertex(Vertex* vertex_ptr){_vertices.push_back(vertex_ptr);};

    // Print all Vertices and its Edges from the Graph
    void print_vertices();

    // Generate random data
    void random_graph(unsigned short vertices_size,
                      double edge_density,
                      unsigned short distance_range);
};

Graph::Graph(){
    // Constructor
    cout << "New Graph object instantiated." << endl;
}

Graph::~Graph(){
    cout << "Destroing Graph object" << endl;
    vector<Vertex*>::iterator it;
    for (it=_vertices.begin(); it!=_vertices.end(); it++){
        delete *it;
    }
}

int Graph::edges_size(){
    // Return the number of Edges of the Graph
    int sum = 0;
    vector<Vertex*>::iterator it;
    for (it=_vertices.begin(); it!=_vertices.end(); it++){
        sum += (*it)->edges_size();
    }
    return sum;
}

void Graph::print_vertices(){
    // Print Vertices and its Edges from the Graph
    vector<Vertex*>::iterator it;
    for (it=_vertices.begin(); it!=_vertices.end(); it++){
        (*it)->print_edges();
    }
}

void Graph::random_graph(unsigned short vertices_size,
                         double edge_density,
                         unsigned short distance_range){
    // This function aims to create a random graph
    Vertex* vertex;
    default_random_engine generator(time(0));
    uniform_int_distribution<unsigned> random_vertices(0, vertices_size-1),
                                       random_edges(0,4),
                                       random_distance(1, distance_range);
    int cost, destination;
    cout << "\nRandom Graph being generated.\n";
    for (int i = 0; i < vertices_size; i++){
        vertex = new Vertex(i);
        for (int j = random_edges(generator); j < 5; j++){
            cost = random_distance(generator);
            vertex->add_edge(i, random_vertices(generator), cost);
        } 
        add_vertex(vertex);
    }
}


int main() {
    /* Manual Graph creation */ 
    cout << "\nManual Graph creation:\n";   
    Graph graph;
    Vertex* vertex_ptr = new Vertex(1);
    vertex_ptr->add_edge(1,3,2), vertex_ptr->add_edge(3,5,3);
    cout << "\nPrinting all the edges from a vertex:\n";
    vertex_ptr->print_edges();
    cout << "\nPrinting additional node information:\n";
    cout << "Edges size: " << vertex_ptr->edges_size() << endl;
    cout << "\nAdding a vertex manually to a Graph object:\n";
    graph.add_vertex(vertex_ptr);
    cout << "Graph size: " << graph.vertices_size() << " vertex(s).\n\n";

    /* Automatic Graph creation*/
    cout << "\n\nAutomatic Graph creation:\n";
    Graph graph_random;
    graph_random.random_graph(10,1,10);
    cout << "\nPrinting Graph information:\n";
    cout << "Vertices size: " << graph_random.vertices_size() << endl;
    cout << "Edges size: " << graph_random.edges_size() << endl;
    graph_random.print_vertices();

    return 0;
}