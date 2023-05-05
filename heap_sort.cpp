#include <iostream>

using namespace std;

void print(int array[], int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

void swap(int &i, int &j)
{
    int temp = i;
    i = j;
    j = temp;
}

void max_heapify(int array[], int idx, int size)
{
    int left = 2 * idx + 1;
    int right = left + 1;

    if (left < size && (right >= size | array[left] > array[right]) && array[left] > array[idx])
    {
        swap(array[idx], array[left]);
        max_heapify(array, left, size);
    }
    else if (right < size && array[right] > array[idx])
    {
        swap(array[idx], array[right]);
        max_heapify(array, right, size);
    }
}

void build_max_heap(int array[], int size)
{
    for (int i = size / 2; i >= 0; i--)
        max_heapify(array, i, size);
}

void heap_sort(int array[], int size)
{
    build_max_heap(array, size);
    for (int i = 0; i < size; i++)
    {
        swap(array[size - i - 1], array[0]);
        max_heapify(array, 0, size - i - 1);
    }
}

int main(void)
{
    int array[] = {3, 1, 5, 9, 6, 7, 8, 2, 4};
    int size = sizeof(array) / sizeof(array[0]);
    heap_sort(array, 9);
    print(array, size);
    return 0;
}