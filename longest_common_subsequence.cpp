#include <iostream>

using namespace std;

int top_down(string s, string t, int memo[100][100], int pred[100][100], int i = 0, int j = 0)
{
    if (memo[i][j] != -1)
        return memo[i][j];

    if (i == s.length() || j == t.length())
    {
        memo[i][j] = 0;
        return 0;
    }

    if (s[i] == t[j])
    {
        memo[i][j] = 1 + top_down(s, t, memo, pred, i + 1, j + 1);
        pred[i][j] = 1;
    }
    else
    {
        int res1 = top_down(s, t, memo, pred, i + 1, j);
        int res2 = top_down(s, t, memo, pred, i, j + 1);
        if (res1 < res2)
        {
            memo[i][j] = res2;
            pred[i][j] = 2;
        }
        else
        {
            memo[i][j] = res1;
            pred[i][j] = 3;
        }
    }
    return memo[i][j];
}

void print_lcs(string s, string t, int pred[100][100])
{
    int i = 0;
    int j = 0;
    while (i < s.length() && j < t.length())
    {
        if (pred[i][j] == 1)
        {
            cout << s[i];
            i++;
            j++;
        }
        else if (pred[i][j] == 3)
            i++;
        else
            j++;
    }
}

void bottom_up(string s, string t, int memo[100][100], int pred[100][100])
{
    for (int i = 0; i < s.length(); i++)
        for (int j = 0; j < s.length(); j++)
            if (s[i] == t[j])
            {
                memo[i][j] = memo[i - 1][j - 1] + 1;
                pred[i][j] = 1;
            }
            else
                pred[i][j] = (memo[i - 1][j] < memo[i][j - 1]) ? 3 : 2;
}

int divide_and_conquor(string s, string t, int memo[100][100], int pred[100][100], int i = 0, int j = 0)
{
    if (i == s.length() || j == t.length())
    {
        memo[i][j] = 0;
        return 0;
    }

    if (s[i] == t[j])
    {
        memo[i][j] = 1 + top_down(s, t, memo, pred, i + 1, j + 1);
        pred[i][j] = 1;
    }
    else
    {
        int res1 = top_down(s, t, memo, pred, i + 1, j);
        int res2 = top_down(s, t, memo, pred, i, j + 1);
        if (res1 < res2)
        {
            memo[i][j] = res2;
            pred[i][j] = 2;
        }
        else
        {
            memo[i][j] = res1;
            pred[i][j] = 3;
        }
    }
    return memo[i][j];
}
int main(void)
{
    int n = 100;
    int memo[100][100];
    int pred[100][100];

    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
        {
            memo[i][j] = -1;
            pred[i][j] = -1;
        }

    divide_and_conquor("hellllllo", "hello", memo, pred);
    print_lcs("hellllllo", "hello", pred);
}