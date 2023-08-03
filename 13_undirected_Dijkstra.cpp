/*
    Peer-graded Assignment: Homework 2
    Undirected Dijkstra's Algorithm

    Cristofer Costa
    cristofercosta@yahoo.com.br
*/


#include <iostream>
#include <list>
#include <set>
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
    
    // Constructor
    Edge(
        unsigned short v,
        unsigned short w,
        unsigned short cost
    )
        : _v(v)
        , _w(w)
        , _cost(cost)
    {cout << "New instance " << *this << "." << endl;}

    // Destructor
    ~Edge(){cout << "Edge " << this << " deleted." << endl;}

    // Operator << overloading
    friend ostream& operator<<(ostream& out, const Edge& edge);
};

ostream& operator<<(ostream& out, const Edge& edge){
    // Operator << overloading
    out << "Edge (v: " << edge._v;
    out << ", w: " << edge._w;
    out << ", cost: " << edge._cost;
    out << ")";
    return out;
};


// Class to implement a Vertex.
class Vertex {
private:
    set<Vertex*> _adjacent;         // Adjacency list
    unsigned short _id;             // Vertex id

public:
    // Constructor
    Vertex(unsigned short id)
        : _id(id)
    {cout << "New instance " << *this << "." << endl;}

    // Destructor
    ~Vertex(){cout << "Vertex " << this << " deleted." << endl;}

    // Operator << overloading
    friend ostream& operator<<(ostream& out, const Vertex& vertex);
};

ostream& operator<<(ostream& out, const Vertex& vertex){
    // Operator << overloading
    out << "Vertex #" << vertex._id;
    return out;
};


// Class to implement a Graph
class Graph
{
private:
    vector<Vertex*> _vertices;        // Vertices vector
    vector<Edge*> _edges;             // Edges vector
    vector<Vertex*> _path;            // Path vector
public:
    // Constructor
    Graph(){cout << "New instace " << *this << "." << endl;}

    // Destructor
    ~Graph();

    // Operator << overloading
    friend ostream& operator<<(ostream& out, const Graph& graph);
    
    // Operator [] overloading
    Vertex operator[](int i);

    // Return the number of Vertcies of the Graph
    int vertices_size(){return _vertices.size();}

    // Return the number of Edges of the Graph
    int edges_size(){return _edges.size();}

    // Create Vertices
    void create_vertices(int quantity = 1);

    // Add Vertex to the Graph
    void add_vertex(Vertex* vertex_ptr){_vertices.push_back(vertex_ptr);}

    // Add Edge to the Graph
    void add_edge(Edge* edge_ptr);

    // Generate random data
    void random_graph(
        unsigned short vertices_size,
        double edge_density,
        unsigned short distance_range
    );
};

Graph::~Graph(){
    // Destructor
    // Deleting vertices
    vector<Vertex*>::iterator it1;
    for (it1=_vertices.begin(); it1!=_vertices.end(); it1++){
        delete *it1;
    }
    // Deleting vertices
    vector<Edge*>::iterator it;
    for (it=_edges.begin(); it!=_edges.end(); it++){
        delete *it;
    }
    cout << "Graph object " << this << " deleted." << endl;
}

ostream& operator<<(ostream& out, const Graph& graph){
    // Operator << overloading
    out << "Graph (vertices: " << graph._vertices.size();
    out << ", edges: " << graph._edges.size();
    out << ")";
    return out;
}

Vertex Graph::operator[](int i){
    return *_vertices[i];
}

void Graph::add_edge(Edge* edge_ptr){
    // This function add the edge into the Graph instance.
    _edges.push_back(edge_ptr);
    // TO DO:
    // Checks if the vertices exist
    // Update the vertices adjacent list
    //(_vertices[edge_ptr->_v])->_adjacent.insert(_vertices[edge_ptr->_v])
}

// void Graph::random_graph(unsigned short vertices_size,
//                          double edge_density,
//                          unsigned short distance_range){
//     // This function aims to create a random graph
//     Vertex* vertex;
//     default_random_engine generator(time(0));
//     uniform_int_distribution<unsigned> random_vertices(0, vertices_size-1),
//                                        random_edges(0,4),
//                                        random_distance(1, distance_range);
//     int cost, destination;
//     cout << "\nRandom Graph being generated.\n";
//     for (int i = 0; i < vertices_size; i++){
//         vertex = new Vertex(i);
//         for (int j = random_edges(generator); j < 5; j++){
//             cost = random_distance(generator);
//             vertex->add_edge(i, random_vertices(generator), cost);
//         } 
//         add_vertex(vertex);
//     }
// }

void Graph::create_vertices(int quantity){
    // Create the vertices
    Vertex* vertex_ptr;
    for (int i = 0; i < quantity; i++){
        vertex_ptr = new Vertex(_vertices.size());
        this->add_vertex(vertex_ptr);
    }
}


int main() {
    /* Manual Graph creation */ 
    cout << "\nManual Graph creation:\n";   
    Graph* graph = new Graph();
    cout << "\tNumber of vertices: " << graph->vertices_size() << endl;
    cout << "\tNumber of edges: " << graph->edges_size() << endl;
    Vertex* vertex_ptr = new Vertex(0);
    Edge* edge_ptr = new Edge(1,1,1);
    graph->add_vertex(vertex_ptr);
    graph->add_edge(edge_ptr);
    cout << "\tNumber of vertices: " << graph->vertices_size() << endl;
    cout << "\tNumber of edges: " << graph->edges_size() << endl;
    graph->create_vertices();
    cout << "\tNumber of vertices: " << graph->vertices_size() << endl;
    cout << "\tNumber of edges: " << graph->edges_size() << endl;
    cout << *graph << endl;
    delete(graph);
    
    /* Autometic Graph Creation*/
    cout << "\nAutomatic graph generation:" << endl;
    graph = new Graph();
    graph->create_vertices(10);
    edge_ptr = new Edge(1,2,1);
    graph->add_edge(edge_ptr);
    cout << "_______________________" << endl;
    cout << (*graph)[0] << endl;
    
    delete(graph);
    
    // cout << "\nPrinting all the edges from a vertex:\n";
    // vertex_ptr->print_edges();
    // cout << "\nPrinting additional node information:\n";
    // cout << "Edges size: " << vertex_ptr->edges_size() << endl;
    // cout << "\nAdding a vertex manually to a Graph object:\n";
    // graph.add_vertex(vertex_ptr);
    // cout << "Graph size: " << graph.vertices_size() << " vertex(s).\n\n";

    // /* Automatic Graph creation*/
    // cout << "\n\nAutomatic Graph creation:\n";
    // Graph graph_random;
    // graph_random.random_graph(10,1,10);
    // cout << "\nPrinting Graph information:\n";
    // cout << "Vertices size: " << graph_random.vertices_size() << endl;
    // cout << "Edges size: " << graph_random.edges_size() << endl;
    // graph_random.print_vertices();

    return 0;
}
