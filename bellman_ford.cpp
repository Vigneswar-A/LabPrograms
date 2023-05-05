#include <iostream>

using namespace std;

class Edge
{
public:
    int u, v, cost;
    Edge(int u, int v, int cost) : u(u), v(v), cost(cost) {}
};

void bellman_ford(Edge *edges[], int size, int n, int src)
{
    int *prev = new int[n];
    int *pred = new int[n];
    for (int i = 0; i < n; i++)
        prev[i] = 100000;
    prev[src] = 0;
    for (int j = 0; j < n - 1; j++)
    {
        int *curr = new int[n];
        for (int i = 0; i < n; i++)
            curr[i] = prev[i];
        for (int i = 0; i < size; i++)
        {
            int u = edges[i]->u, v = edges[i]->v, cost = edges[i]->cost;
            if (prev[u] + cost < curr[v])
            {
                curr[v] = prev[u] + cost;
                pred[v] = u;
            }
        }
        prev = curr;
    }
    for (int i = 0; i < n; i++)
        cout << prev[i] << " ";
    cout << endl;
}

int main(void)
{
    Edge *edges[3];
    edges[0] = new Edge(0, 1, 2);
    edges[1] = new Edge(1, 2, 2);
    edges[2] = new Edge(0, 2, 1);
    bellman_ford(edges, 3, 3, 0);
}