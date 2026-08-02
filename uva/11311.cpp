#include <bits/stdc++.h>
using namespace std;
bool memo[48][48][48][48][2];
bool visited[48][48][48][48][2];

bool dp(int r1, int r2, int c1, int c2, bool who)
{
    if (r1 == r2)
    {
        if (c1 == c2)
            return !who;
        return who;
    }
    if (c1 == c2)
        return who;
    if (visited[r1][r2][c1][c2][who])
        return memo[r1][r2][c1][c2][who];
    if (visited[c1][c2][r1][r2][who])
        return memo[c1][c2][r1][r2][who];
    visited[r1][r2][c1][c2][who] = true;

    if (who == 0)
    {
        bool result = true;
        for (int i = 0; i < r1; i++)
            result &= dp(min(i, r2), max(i, r2), c1, c2, 1);

        for (int i = 0; i < r2; i++)
            result &= dp(min(i, r1), max(i, r1), c1, c2, 1);

        for (int i = 0; i < c1; i++)
            result &= dp(r1, r2, min(i, c2), max(i, c2), 1);

        for (int i = 0; i < c2; i++)
            result &= dp(r1, r2, min(i, c1), max(i, c1), 1);

        return memo[r1][r2][c1][c2][who] = result;
    }

    for (int i = 0; i < r1; i++)
        if (dp(min(i, r2), max(i, r2), c1, c2, 0))
            return memo[r1][r2][c1][c2][who] = true;

    for (int i = 0; i < r2; i++)
        if (dp(min(i, r1), max(i, r1), c1, c2, 0))
            return memo[r1][r2][c1][c2][who] = true;

    for (int i = 0; i < c1; i++)
        if (dp(r1, r2, min(i, c2), max(i, c2), 0))
            return memo[r1][r2][c1][c2][who] = true;

    for (int i = 0; i < c2; i++)
        if (dp(r1, r2, min(i, c1), max(i, c1), 0))
            return memo[r1][r2][c1][c2][who] = true;

    return memo[r1][r2][c1][c2][who] = false;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int m, n, r, c;
        cin >> m >> n >> r >> c;
        int r1 = r;
        int r2 = m - r - 1;
        int c1 = c;
        int c2 = n - c - 1;
        memset(visited, 0, sizeof(visited));
        if (dp(min(r1, r2), max(r1, r2), min(c1, c2), max(c1, c2), 1))
            cout << "Gretel" << endl;
        else
            cout << "Hansel" << endl;
    }
}
