#include "union_find_cls.h"


UnionFind::UnionFind (int N)
{
    N_nodes = N;
    father = new int [N];
    size = new int [N];
    for (int i = 0; i < N; i++)
    {
        father[i] = i;
        size[i] = 1;
    }
}

UnionFind::~UnionFind ()
{
    delete [] father;
    delete [] size;
}

int UnionFind::find_root (int node)
{
    while (father[node] != node)
    {
        father[node] = father[father[node]];
        node = father[node];
    };
    return node;
}

void UnionFind::merge (int node1, int node2)
{
    int root1, root2;
    if (!(is_connected (node1, node2)))
    {
        root1 = find_root (node1);
        root2 = find_root (node2);
        if (size[root1] < size[root2])
        {
            father[root1] = father[root2];
            size[root2] += size[root1];
        }
        else
        {
            father[root2] = father[root1];
            size[root1] = size[root2];
        }
    }

}

bool UnionFind::is_connected (int node1, int node2)
{
    return (find_root (node1) == find_root (node2));
}