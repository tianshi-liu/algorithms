#include "union_find_cls.h"

void fast_union_find (int N_nodes, int N_ops, int* ops, int* node1, int* node2)
/*
test union find program
ops: 0 for union, 1 for check connection
*/
{
    UnionFind uf (N_nodes);
    for (int i = 0; i < N_ops; i++)
    {
        if (ops[i] == 0)
        {
            uf.merge (node1[i], node2[i]);
            cout << "merge node " << node1[i] << " and " << node2[i] << endl;
        }
        else
        {
            if (uf.is_connected(node1[i], node2[i]))
                cout << "node " << node1[i] << " and " << node2[i] << " are connected" << endl;
            else
                cout << "node " << node1[i] << " and " << node2[i] << " are not connected" << endl;
        }
    }
}

int main()
{
    int N_nodes = 10;
    int N_ops = 10;
    int ops [] =   {0, 0, 0, 0, 0, 0, 0, 1, 1, 1};
    int node1 [] = {1, 3, 5, 4, 3, 6, 9, 5, 9, 7};
    int node2 [] = {2, 4, 6, 1, 7, 8, 3, 9, 4, 3};
    fast_union_find (N_nodes, N_ops, ops, node1, node2);
    return (0);
}