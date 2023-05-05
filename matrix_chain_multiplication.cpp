#include <iostream>

using namespace std;

int top_down(int array[], int i, int j, int memo[100][100])
{
    if (memo[i][j] != 100000)
        return memo[i][j];

    if (i >= j)
        return 0;

    for (int k = i; k < j; k++)
        memo[i][j] = min(memo[i][j], top_down(array, i, k, memo) + top_down(array, k + 1, j, memo) + array[i - 1] * array[k] * array[j]);

    return memo[i][j];
}

int bottom_up(int array[], int size)
{
    int dp[size][size];
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            dp[i][j] = (i == j) ? 0 : 100000;

    for (int l = 2; l < size; l++)
        for (int i = 0; i < size - l + 1; i++)
        {
            int j = i + l - 1;
            for (int k = i; k < j; k++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + array[i - 1] * array[j] * array[k]);
        }

    return dp[1][size - 1];
}

int main(void)
{
    int memo[100][100];
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            memo[i][j] = 100000;

    int array[] = {1, 2, 4, 8};
    int size = sizeof(array) / sizeof(array[0]);

    cout << top_down(array, 1, size - 1, memo) << endl;
    cout << bottom_up(array, size);
    return 0;
}