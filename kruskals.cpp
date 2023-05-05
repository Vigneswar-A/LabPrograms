#include <iostream>

using namespace std;

class UnionFind
{
private:
    int *root;
    int *rank;

public:
    UnionFind(int n)
    {
        root = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++)
        {
            root[i] = i;
            rank[i] = 0;
        }
    }
    int find(int x)
    {
        if (x != root[x])
            root[x] = find(root[x]);
        return root[x];
    }

    bool union_(int x, int y)
    {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx == rooty)
            return false;

        if (rank[rootx] > rank[rooty])
            root[rooty] = rootx;
        else if (rank[rooty] > rank[rootx])
            root[rootx] = rooty;
        else
        {
            root[rooty] = rootx;
            rank[rootx]++;
        }

        return true;
    }
};

class Edge
{
public:
    int u, v, cost;
    Edge(int u, int v, int cost) : u(u), v(v), cost(cost) {}
};

void insertion_sort(Edge *edges[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int j = i - 1;
        Edge *temp = edges[i];
        while (j >= 0 && edges[j]->cost > temp->cost)
        {
            edges[j + 1] = edges[j];
            j--;
        }
        edges[j + 1] = temp;
    }
}

int kruskals(Edge *edges[], int size, int n)
{
    insertion_sort(edges, size);
    UnionFind uf(n);
    int mst_cost = 0;
    for (int i = 0; i < size; i++)
        cout << edges[i]->cost << " ";
    cout << endl;
    int edge_count = 0;
    for (int i = 0; i < size && n - 1 != edge_count; i++)
        if (uf.union_(edges[i]->u, edges[i]->v))
        {
            mst_cost += edges[i]->cost;
            edge_count++;
        }
    return mst_cost;
}

int main(void)
{
    int n = 100;
    Edge *edges[n];
    edges[0] = new Edge(0, 1, 4);
    edges[1] = new Edge(0, 7, 8);
    edges[2] = new Edge(1, 2, 8);
    edges[3] = new Edge(1, 7, 11);
    edges[4] = new Edge(7, 6, 1);
    edges[5] = new Edge(7, 8, 7);
    edges[6] = new Edge(2, 8, 2);
    edges[7] = new Edge(2, 5, 4);
    edges[8] = new Edge(2, 3, 7);
    edges[9] = new Edge(3, 4, 9);
    edges[10] = new Edge(3, 5, 14);
    edges[11] = new Edge(5, 4, 10);
    edges[12] = new Edge(6, 5, 2);
    edges[13] = new Edge(8, 6, 6);

    cout << kruskals(edges, 15, 9);
    return 0;
}