#include <iostream>

using namespace std;

class ListNode
{
public:
    int n;
    ListNode *next;
    ListNode(int n, ListNode *next = NULL) : n(n), next(next) {}
};

class List
{
public:
    ListNode *head = NULL;
    ListNode *tail = NULL;

    void append(int n)
    {
        if (head == NULL)
        {
            head = new ListNode(n);
            tail = head;
            return;
        }
        tail->next = new ListNode(n);
        tail = tail->next;
    }

    int popleft()
    {
        if (head == NULL)
            return -1;
        if (head->next == NULL)
            tail = NULL;
        int n = head->n;
        head = head->next;
        return n;
    }

    bool empty()
    {
        return head == NULL;
    }
};

void topological_sort(int n, List adjacency[])
{
    List queue;
    int degrees[n] = {0};
    for (int i = 0; i < n; i++)
    {
        ListNode *currnode = adjacency[i].head;
        while (currnode != NULL)
        {
            degrees[currnode->n]++;
            currnode = currnode->next;
        }
    }

    for (int i = 0; i < n; i++)
        if (degrees[i] == 0)
            queue.append(i);

    while (!queue.empty())
    {
        int node = queue.popleft();
        cout << node << " ";
        ListNode *currnode = adjacency[node].head;
        while (currnode != NULL)
        {
            degrees[currnode->n]--;
            if (degrees[currnode->n] == 0)
                queue.append(currnode->n);
            currnode = currnode->next;
        }
    }
    cout << endl;
}

int main(void)
{
    int n = 3;
    List adjacency[n];
    adjacency[0].append(1);
    adjacency[2].append(1);
    topological_sort(n, adjacency);
    return 0;
}