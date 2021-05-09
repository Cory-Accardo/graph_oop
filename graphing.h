#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Node {
    vector<Node*> neighbors; //a vector of a node's neighbors
    int id;
    Node* prev = NULL; //can be useful for BFS
};


class Graph {
    public:
        ~Graph();
        int get_size(); //returns the current number of nodes in the graph
        Node* add_node(); //used to create a new distinct component node
        void connect_nodes(int left_id, int right_id); //pass the ids of the two nodes you want to connect
        void remove_node(int id); // pass the id of the node you want to remove
        void append_node(int id); //pass the node you want to attach to
        void append_node(int id, int times); //overload allows you to append a node a set number of times
        void print_graph(); //prints, from vertex 0 - n, the vertex's respective neighbor's id.
    private:
        Node* get_node(int id); //pass a node's id and receive a Node pointer to that node.
        vector<Node*> nodes;
};
