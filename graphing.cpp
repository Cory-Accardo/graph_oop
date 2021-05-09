#include "graphing.h"


Graph::~Graph(){
    for(int i = 0; i < nodes.size(); i++){
        remove_node(nodes[i]->id);
    }
}

int Graph::get_size(){
    return nodes.size();
}

Node* Graph::get_node(int id){
    for(int i = 0; i < nodes.size(); i++){
        if(nodes[i]->id == id){return nodes[i];}
    }
    return NULL;
}

void Graph::add_node(){
    Node* new_node = new Node();
    new_node->id = nodes.size();
    nodes.push_back(new_node);
}

void Graph::connect_nodes(int left_id, int right_id){
    Node* left_node = get_node(left_id);
    Node* right_node = get_node(right_id);
    left_node->neighbors.push_back(right_node);
    right_node->neighbors.push_back(left_node);
}

void Graph::remove_node(int id){
    Node* c_node = get_node(id);
    nodes.erase(remove(nodes.begin(), nodes.end(), c_node), nodes.end()); 
    for(int i = 0; i < c_node->neighbors.size(); i++){
        Node* node_neighbor = c_node->neighbors[i];
        if(node_neighbor->prev == c_node){node_neighbor->prev = NULL;}
        node_neighbor->neighbors.erase(remove(node_neighbor->neighbors.begin(), node_neighbor->neighbors.end(), c_node), node_neighbor->neighbors.end());
    }
    delete c_node;
}

void Graph::append_node(int id){
    Node* c_node = get_node(id);
    Node* new_node = new Node();
    new_node->id = nodes.size();
    new_node->prev = c_node;
    new_node->neighbors.push_back(c_node);
    c_node->neighbors.push_back(new_node);
    nodes.push_back(new_node);
}

void Graph::append_node(int id, int times){
    for(int i = 0; i < times; i++){
        append_node(id);
    }
}

void Graph::print_graph(){
    if(nodes.size() == 0){cout << "This is an empty graph" << endl;}
    for(int i = 0; i < nodes.size(); i++){
        cout << "{ " << nodes[i]->id << ":: ";
        for(int j = 0; j < nodes[i]->neighbors.size(); j++){
            cout << nodes[i]->neighbors[j]->id << ", ";
        }
        cout << "}" << endl;
    }
}



