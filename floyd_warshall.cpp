#include <iostream>

using namespace std;

int main(void)
{
    int adjacency_matrix[4][4] = {
        {1, 2, 3, 4},
        {2, 3, 1, 4},
        {1, 2, 3, 4},
        {3, 2, 1, 2}};

    int m = 4;
    int n = 4;

    int dp[n][n];
    int pred[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = (i == j) ? 0 : adjacency_matrix[i][j];
            pred[i][j] = -1;
        }

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dp[i][j] > dp[i][k] + dp[k][j])
                {
                    dp[i][j] = dp[i][k] + dp[k][j];
                    pred[i][j] = k;
                }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
    return 0;
}