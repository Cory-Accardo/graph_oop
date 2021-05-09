#include "graphing.cpp"

using namespace std;

int main ()
{
    Graph G;
    G.add_node();
    G.append_node(0,2);
    G.append_node(2, 3);
    G.connect_nodes(1, 2);
    G.remove_node(2);
    G.print_graph();
}