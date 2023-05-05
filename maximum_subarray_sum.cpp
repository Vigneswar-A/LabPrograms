#include <iostream>

using namespace std;

int divide_and_conquor(int array[], int left, int right, int &l, int &r)
{
    if (left > right)
        return 0;

    // calculate cross sum
    int mid = left + right >> 1;
    int left_max_sum = 0, right_max_sum = 0;
    int left_idx = mid, right_idx = mid;

    int temp = 0;
    for (int i = mid - 1; i >= left; i--)
    {
        temp += array[i];
        if (temp > left_max_sum)
        {
            left_max_sum = temp;
            left_idx = i;
        }
    }

    temp = 0;
    for (int i = mid + 1; i <= right; i++)
    {
        temp += array[i];
        if (temp > right_max_sum)
        {
            right_max_sum = temp;
            right_idx = i;
        }
    }
    int cross_sum = left_max_sum + array[mid] + right_max_sum;

    int left_sum = divide_and_conquor(array, left, mid - 1, l, r);
    int right_sum = divide_and_conquor(array, mid + 1, right, l, r);

    // choose the best one
    if (cross_sum >= left_sum && cross_sum >= right_sum)
    {
        l = left_idx;
        r = right_idx;
        return cross_sum;
    }
    else if (left_sum > right_sum)
        return left_sum;
    else
        return right_sum;
}

int main(void)
{
    int array[] = {1, 2, 3, 2, -5, -8, 3, 4, 5, 2, 3, 4, -6};
    int size = sizeof(array) / sizeof(array[0]);
    int l, r;
    int res = divide_and_conquor(array, 0, size - 1, l, r);
    cout << l << " " << r << " " << res << endl;
    return 0;
}