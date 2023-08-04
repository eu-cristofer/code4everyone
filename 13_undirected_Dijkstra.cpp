/*
    Peer-graded Assignment: Homework 2
    Undirected Dijkstra's Algorithm

    Cristofer Costa
    cristofercosta@yahoo.com.br
*/


#include <iostream>
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
    ~Edge(){// cout << "Edge " << this << " deleted." << endl;
    }

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
    set<Vertex*> _adjacent;         // Adjacency container
    vector<Edge*> _edges;           // Adjacent Edges container
    unsigned short _id;             // Vertex id

public:
    // Constructor
    Vertex(unsigned short id)
        : _id(id)
    {// cout << "New instance " << *this << "." << endl;
    }

    // Destructor
    ~Vertex(){// cout << "Vertex object " << this << " deleted." << endl;
    }

    // Operator << overloading
    friend ostream& operator<<(ostream& out, const Vertex& vertex);

    // ID getter
    unsigned short get_id(){return _id;}

    // Add vertex to the Adjacency container
    void add_adjacency(Vertex* vertex_ptr){_adjacent.insert(vertex_ptr);}

    // Add 
    void add_adjacent_edge(Edge* edge_ptr){_edges.push_back(edge_ptr);}

    // Print adjacency list
    void display_adjacencies();

    // Check if is adjacente with w
    bool is_adjacent(int w);

    // Get the edge cost
    unsigned short get_edge_value(int w);
};

ostream& operator<<(ostream& out, const Vertex& vertex){
    // Operator << overloading
    out << "Vertex #" << vertex._id;
    return out;
};

void Vertex::display_adjacencies(){
    // Printout adjacency list
    set<Vertex*>::iterator itr;
    // Displaying set elements
    cout << "Printing adjacencies" << endl;
    for (itr = _adjacent.begin(); itr != _adjacent.end(); itr++){
        cout << **itr << "\t";
    }
    cout << endl;
}

bool Vertex::is_adjacent(int w){
    // Check if the vertex is adjacente with vertex w
    bool check = 0;
    set<Vertex*>::iterator itr;
    // Iterating trough the set elements
    for (itr = _adjacent.begin(); itr != _adjacent.end(); itr++){
        if (w == (*itr)->get_id()){
            check = 1;
        }
    }
    return check;
}

unsigned short Vertex::get_edge_value(int w){
    // Get the edge cost
    vector<Edge*>::iterator itr;
    int cost;
    // Iterating trough the vector elements
    for (itr = _edges.begin(); itr != _edges.end(); itr++){
        if ((w == (*itr)->_v) || (w == (*itr)->_w)){
            cost = (*itr)->_cost;
        }
    }
    return cost;
}


// Class to implement a Graph
class Graph
{
private:
    vector<Vertex*> _vertices;        // Vertices vector
    vector<Edge*> _edges;             // Edges vector
    vector<Vertex*> _path;            // Path vector
public:
    // Constructor
    Graph(){//cout << "New instace " << *this << "." << endl;
    }

    // Destructor
    ~Graph();

    // Operator << overloading
    friend ostream& operator<<(ostream& out, const Graph& graph);
    
    // Operator [] overloading
    Vertex* operator[](int i);
 
    // Number of Vertcies of the Graph
    int vertices_size(){return _vertices.size();}

    // Number of Edges of the Graph
    int edges_size(){return _edges.size();}

    // Graph Density
    float density(){return 2.0 * _edges.size() / (_vertices.size() * (_vertices.size() - 1)); }

    // Create Vertices
    void create_vertices(int quantity = 1);

    // Add Vertex to the Graph
    void add_vertex(Vertex* vertex_ptr){_vertices.push_back(vertex_ptr);}

    // Add Edge to the Graph
    void add_edge(Edge* edge_ptr);

    // List all nodes shuch that there is a edge
    void neighbors(int vertex_id);

    // Test if is adjacente v and w
    bool is_adjacent(int v, int w);

    // Get the edge cost
    unsigned short get_edge_value(int v, int w);

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
    //cout << "Graph object " << this << " deleted." << endl;
}

ostream& operator<<(ostream& out, const Graph& graph){
    // Operator << overloading
    out << "Graph (vertices: " << graph._vertices.size();
    out << ", edges: " << graph._edges.size();
    out << ")";
    return out;
}

Vertex* Graph::operator[](int i){
    return _vertices[i];
}

void Graph::add_edge(Edge* edge_ptr){
    /*
        This function adds the Edge object into the Graph instance.
        First it adds the Edge object pointer to the vector _edges
        and update the Vertices (origin "v" and destination "w")
        adjacency vector ("_adjacent").
        Note the design considers that all the Vertex have already been
        instantiated.
    */
    _edges.push_back(edge_ptr);
    
    // Update the vertices adjacent list
    Vertex * vertex_ptr_v, * vertex_ptr_w;
    vertex_ptr_v = _vertices[edge_ptr->_v];
    vertex_ptr_w = _vertices[edge_ptr->_w];
    vertex_ptr_v->add_adjacency(vertex_ptr_w);
    vertex_ptr_v->add_adjacent_edge(edge_ptr);
    vertex_ptr_w->add_adjacency(vertex_ptr_v);
    vertex_ptr_w->add_adjacent_edge(edge_ptr);
}

void Graph::neighbors(int vertex_id){
    // List all nodes shuch that there is a edge
    _vertices[vertex_id]->display_adjacencies();
}

bool Graph::is_adjacent(int v, int w){
    // Check if is adjacente v and w
    return _vertices[v]->is_adjacent(w);
}

unsigned short Graph::get_edge_value(int v, int w){
    // Get the edge cost
    return _vertices[v]->get_edge_value(w);
}

void Graph::random_graph(unsigned short vertices_size,
                         double edge_density,
                         unsigned short distance_range){
    /*
        This function aims to create a random graph.
        From the parameteres vertices_size and edge_density,
        the function determines the aproximated number of edges
        to be generated. Later, these edges are filled with random
        "u" and "w" vertices and a random unsigned short distance_range.
    */
    float edges_quantity;
    edges_quantity = edge_density * vertices_size * (vertices_size -1) / 2.0;
    int round_edges = round(edges_quantity);
    cout << "\nRandom Graph being generated.\n";
    cout << "Theoretical edges qty: " << edges_quantity << endl;
    cout << "Rounding: " << round_edges  << endl;
    
    // Setting up random functions
    default_random_engine generator(time(0));
    uniform_int_distribution<unsigned> random_vertices(0, vertices_size-1),
                                       random_edges(0,4),
                                       random_distance(1, distance_range);
    
    // Creating the Vertices
    Vertex* vertex_ptr;
    for (int i = 0; i < vertices_size; i++){
        vertex_ptr = new Vertex(i);
        this->add_vertex(vertex_ptr);
    }

    // Creating the Edges
    Edge* edge_ptr;
    for (int i = 0; i < round_edges; i++){
        edge_ptr = new Edge(random_vertices(generator),
                            random_vertices(generator),
                            random_distance(generator));
        this->add_edge(edge_ptr);
    }
}


class ShortestPath
{
private:
    Graph* _graph;
    vector<Vertex*> _path;
    vector<Edge*> _edges;
    int _v, _w;                     // Origin and destination id
public:
    // Constructor
    ShortestPath(Graph* graph):_graph(graph){};

    // Destructor
    ~ShortestPath();

    // Find the shortest path between u and v
    void path(int v, int w);

    // List the vertices of the shortest path
    void display_path();

    // Return the cost of the shortest path
    int path_cost();

    // Return the number of elements of the shortest path
    int path_size(){return _path.size();}
};

ShortestPath::~ShortestPath(){
    delete(_graph);
    //cout << "ShortestPath object " << this << " deleted." << endl;
}

void ShortestPath::path(int v, int w){
    // Find the shortest path between u and v
    // Check if is it adjacent
    _v = v;
    _w = w;
    _path.push_back((*_graph)[v]);
    if(_graph->is_adjacent(v, w)){
        _path.push_back((*_graph)[w]);
    }

    // TO DO
    // Add an else implementing Dijkstra algo
}

void ShortestPath::display_path(){
    // Print the shortest path
    vector<Vertex*>::iterator itr;
    // Displaying vector elements
    cout << "Printing shortest path:" << endl;
    for (itr = _path.begin(); itr != _path.end(); itr++){
        cout << **itr << "\t";
    }
    cout << endl;
}

int ShortestPath::path_cost(){
    // Compute te path cost
    int sum = 0;
    vector<Vertex*>::iterator itr;
    for (itr = _path.begin(); (itr + 1)!= _path.end(); itr++){
        sum += _graph->get_edge_value((**itr).get_id(), (**(itr+1)).get_id());
    }
    return sum;
}


int main() {
    // /* Manual Graph creation */ 
    cout << "\nManual Graph creation:\n";   
    Graph* graph = new Graph();
    // cout << "\tNumber of vertices: " << graph->vertices_size() << endl;
    // cout << "\tNumber of edges: " << graph->edges_size() << endl;
    Vertex* vertex_ptr0 = new Vertex(0);
    Vertex* vertex_ptr1 = new Vertex(1);
    Edge* edge_ptr = new Edge(0,1,100);
    graph->add_vertex(vertex_ptr0);
    graph->add_vertex(vertex_ptr1);
    // vertex_ptr1 = new Vertex(2);
    // graph->add_vertex(vertex_ptr1);
    graph->add_edge(edge_ptr);
    cout << "\tNumber of vertices: " << graph->vertices_size() << endl;
    cout << "\tNumber of edges: " << graph->edges_size() << endl;
    (*graph)[0]->display_adjacencies();
    // graph->create_vertices();
    // cout << "\tNumber of vertices: " << graph->vertices_size() << endl;
    // cout << "\tNumber of edges: " << graph->edges_size() << endl;
    // cout << *graph << endl;
    ShortestPath* shortest_path = new ShortestPath(graph);
    shortest_path->path(0, 1);
    cout << "Path size: " << shortest_path->path_size() << endl;
    shortest_path->display_path();
    cout << "Cost: " << shortest_path->path_cost() << endl;
    delete(shortest_path);
    
    // /* Autometic Graph Creation*/
    // cout << "\nAutomatic graph generation:" << endl;
    // graph = new Graph();
    // graph->create_vertices(10);
    // edge_ptr = new Edge(1,2,1);
    // graph->add_edge(edge_ptr);
    // cout << "_______________________" << endl;
    // cout << *graph << endl;
    // cout << (*graph)[1].get_id() << endl;

    /* Automatic Graph Creation*/
    cout << "\nAutomatic graph generation:" << endl;
    Graph* graph1 = new Graph();
    graph1->random_graph(5, 0.75, 10);
    graph1->neighbors(1);
    cout << "is adjacent 1 and 2? " << graph1->is_adjacent(1, 2) << endl;
    cout << "1 and 2 cost: ";
    if (graph1->is_adjacent(1,2)){
        cout << graph1->get_edge_value(1, 2);
    } else {
        cout << "not conected";
    }
    cout << endl;
    cout << *graph1 << endl;
    cout << "Graph density: " << graph1->density() << endl;
    ShortestPath* shortest_path1 = new ShortestPath(graph1);
    cout << "Path size: " << shortest_path1->path_size() << endl;
    delete(shortest_path1);
    return 0;
}
