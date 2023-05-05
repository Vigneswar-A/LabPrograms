#include <iostream>

using namespace std;

void print(int array[], int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

void count_sort(int array[], int size)
{
    int max = 0;
    for (int i = 0; i < size; i++)
        if (array[i] > max)
            max = array[i];

    int count[max + 1] = {0};
    for (int i = 0; i < size; i++)
        count[array[i]]++;

    count[0]--;
    for (int i = 1; i < max + 1; i++)
        count[i] += count[i - 1];

    int res[size];
    for (int i = 0; i < size; i++)
        res[count[array[i]]--] = array[i];

    for (int i = 0; i < size; i++)
        array[i] = res[i];
}

int main(void)
{
    int array[] = {3, 1, 5, 9, 6, 7, 8, 2, 4};
    int size = sizeof(array) / sizeof(array[0]);
    count_sort(array, 9);
    print(array, size);
    return 0;
}