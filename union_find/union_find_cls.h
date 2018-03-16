#include <iostream>
using namespace std;

class UnionFind
/* 
union-find by quick-union with weighting and path shortening
with integers representing each node 
*/
{
    int N_nodes; //number of blocks in the problem
    int *father; //record father of each node
    int *size; // size of each sub-tree with this node as root
    int find_root (int node); // return the root of this node, with path shortening
    public:
    UnionFind (int); //constructor, input the value of N_nodes, initialize father and size
    void merge (int node1, int node2); //join connected components node1 and node2 belong to
    bool is_connected (int node1, int node2); //return whether node1 and node2 belong to the same connected component
    ~UnionFind (); // deconstructor, free father and size
};