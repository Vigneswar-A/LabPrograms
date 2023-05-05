#include <iostream>

using namespace std;

class Edge
{
public:
    int u, v, cost;
    Edge(int u, int v, int cost) : u(u), v(v), cost(cost) {}
};

class ListNode
{
public:
    Edge *edge;
    ListNode *next;
    ListNode(Edge *edge, ListNode *next = NULL) : edge(edge), next(next) {}
};

class LinkedList
{
public:
    ListNode *head = NULL;
    void add(Edge *edge)
    {
        head = new ListNode(edge, head);
    }
};

class Heap
{
private:
    Edge **heap;
    int size;
    int currsize;

public:
    Heap(int size) : size(size), currsize(0)
    {
        heap = new Edge *[size];
    }

    void swap(int i, int j)
    {
        Edge *temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }

    void push(Edge *edge)
    {
        int idx = ++currsize;
        heap[idx] = edge;
        while (idx > 1 && heap[idx]->cost < heap[idx / 2]->cost)
        {
            swap(idx, idx / 2);
            idx /= 2;
        }
    }

    bool empty()
    {
        return currsize == 0;
    }
    Edge *pop()
    {
        Edge *res = heap[1];
        heap[1] = heap[currsize--];
        int idx = 1;
        while (idx <= currsize / 2)
        {
            int left = 2 * idx;
            int right = left + 1;

            if (heap[left]->cost < heap[idx]->cost && heap[left]->cost <= heap[right]->cost)
            {
                swap(idx, left);
                idx = left;
            }
            else if (heap[right]->cost < heap[idx]->cost)
            {
                swap(idx, right);
                idx = right;
            }
            else
                break;
        }

        return res;
    }
};

int prims(LinkedList adjacency[], int n)
{
    Heap heap(n * n);
    heap.push(new Edge(-1, 0, 0));
    int visited[n] = {0};
    int cost = 0;
    cout << "Edges included are:" << endl;
    while (!heap.empty())
    {
        Edge *edge = heap.pop();
        if (visited[edge->v])
            continue;
        visited[edge->v] = 1;
        cost += edge->cost;
        if (edge->u != -1)
            cout << edge->u << " " << edge->v << " " << edge->cost << endl;
        ListNode *currnode = adjacency[edge->v].head;
        while (currnode != NULL)
        {
            if (!visited[currnode->edge->v])
                heap.push(currnode->edge);

            currnode = currnode->next;
        }
    }
    return cost;
}

int main(void)
{
    int n = 4;
    LinkedList adjacency[n];
    adjacency[0].add(new Edge(0, 1, 1));
    adjacency[0].add(new Edge(0, 2, 4));
    adjacency[0].add(new Edge(0, 3, 3));
    adjacency[1].add(new Edge(1, 3, 2));
    adjacency[2].add(new Edge(2, 3, 5));
    int cost = prims(adjacency, n);
    cout << "minimum cost is: " << cost;
    return 0;
}