#include <iostream>

using namespace std;

class Node
{
public:
    Node *left, *right;
    int freq;
    char c;
    Node(Node *l = NULL, Node *r = NULL, int f = -1, char ch = '*')
    {
        freq = (f == -1) ? (l->freq + r->freq) : f;
        c = ch;
        left = l;
        right = r;
    }
};

class Heap
{
private:
    Node *heap[26];
    int size;

    void swap(int i, int j)
    {
        Node *temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }

public:
    Heap()
    {
        size = 0;
    }

    void push(Node *node)
    {
        heap[++size] = node;
        int idx = size;
        while (idx > 1 && heap[idx]->freq < heap[idx / 2]->freq)
        {
            swap(idx, idx / 2);
            idx /= 2;
        }
    }

    int length()
    {
        return size;
    }

    Node *pop()
    {
        Node *res = heap[1];
        heap[1] = heap[size--];
        int idx = 1;
        while (idx <= size / 2)
        {
            int left = 2 * idx;
            int right = left + 1;

            if (heap[left]->freq < heap[idx]->freq && heap[left]->freq <= heap[right]->freq)
            {
                swap(idx, left);
                idx = left;
            }
            else if (heap[right]->freq < heap[idx]->freq)
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

Node *huffman_tree(char arr[], int freq[], int size)
{
    Heap heap;
    for (int i = 0; i < size; i++)
        heap.push(new Node(NULL, NULL, freq[i], arr[i]));

    while (heap.length() > 1)
        heap.push(new Node(heap.pop(), heap.pop()));

    return heap.pop();
}

void huffman_code(Node *root, string code = "")
{
    if (root == NULL)
        return;
    if (root->c != '*')
        cout << root->c << "-" << code << endl;
    huffman_code(root->left, code + "0");
    huffman_code(root->right, code + "1");
}

int main(void)
{
    char arr[] = "abcde";
    int freq[] = {1, 2, 3, 4, 5};
    Node *root = huffman_tree(arr, freq, 5);
    huffman_code(root);
    return 0;
}
