#include <iostream>

using namespace std;

void print(int array[], int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

int partition(int array[], int left, int right)
{
    int j = left - 1;
    int pivot = array[right];
    for (int i = left; i <= right; i++)
        if (array[i] <= pivot)
        {
            int temp = array[++j];
            array[j] = array[i];
            array[i] = temp;
        }
    return j;
}

void quick_sort(int array[], int left, int right)
{
    if (left < right)
    {
        int q = partition(array, left, right);
        quick_sort(array, left, q - 1);
        quick_sort(array, q + 1, right);
    }
}

int main(void)
{
    int array[] = {3, 1, 5, 9, 6, 7, 8, 2, 4};
    int size = sizeof(array) / sizeof(array[0]);
    quick_sort(array, 0, 8);
    print(array, size);
    return 0;
}