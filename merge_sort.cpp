#include <iostream>

using namespace std;

void print(int array[], int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

void merge(int array[], int left, int mid, int right)
{
    int n1 = mid - left + 1, n2 = right - mid;
    int left_array[n1], right_array[n2];

    for (int i = 0; i < n1; i++)
        left_array[i] = array[left + i];

    for (int i = 0; i < n2; i++)
        right_array[i] = array[mid + i + 1];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
        if (left_array[i] < right_array[j])
            array[k++] = left_array[i++];
        else
            array[k++] = right_array[j++];

    while (i < n1)
        array[k++] = left_array[i++];

    while (j < n2)
        array[k++] = right_array[j++];
}

void merge_sort(int array[], int left, int right)
{
    if (left < right)
    {
        int mid = left + right >> 1;
        merge_sort(array, left, mid);
        merge_sort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

void merge_sort2(int *array, int size)
{
    if (size <= 1)
        return;

    int n1 = size / 2;
    int n2 = n1 + size % 2;
    int *left = new int[n1], *right = new int[n2];

    for (int i = 0; i < size; i++)
        if (i < n1)
            left[i] = array[i];
        else
            right[i - n1] = array[i];

    merge_sort2(left, n1);
    merge_sort2(right, n2);

    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2)
        if (left[i] < right[j])
            array[k++] = left[i++];
        else
            array[k++] = right[j++];

    while (i < n1)
        array[k++] = left[i++];

    while (j < n2)
        array[k++] = right[j++];
}

int main(void)
{
    int array[] = {9, 7, 8, 5, 6, 3, 4, 1, 2};
    int size = sizeof(array) / sizeof(array[0]);
    merge_sort2(array, size);
    print(array, size);
    return 0;
}