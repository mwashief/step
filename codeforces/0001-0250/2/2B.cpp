/*
    Washief Hossain Mugdho
    22 December 2020
    Codeforces 2B
*/

#ifndef DEBUG
#pragma GCC optimize("O2")
#endif

#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define fastio ios_base::sync_with_stdio(0)
#define untie cin.tie(0)
#define ms(a, b) memset(a, b, sizeof a)
using namespace std;
int n, x, zx = -1, nonZeroRes = INT32_MAX;
vector<vector<vector<int>>> mat;
vector<vector<bool>> dir;
string path;

pair<int, int> factors(int x)
{
    if (x == 0)
        return {1, 1};
    pair<int, int> res = {0, 0};
    while (x % 5 == 0)
    {
        res.fr++;
        x /= 5;
    }
    while (x % 2 == 0)
    {
        res.sc++;
        x /= 2;
    }
    return res;
}

void dp(int pos)
{
    vector<vector<int>> memo = vector<vector<int>>(n, vector<int>(n));
    memo[0][0] = mat[0][0][pos];
    int ini = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = ini; j < n; j++)
        {
            if (i == 0)
                memo[i][j] = mat[i][j][pos] + memo[i][j - 1];
            else if (j == 0)
                memo[i][j] = mat[i][j][pos] + memo[i - 1][j];
            else
            {
                if (memo[i - 1][j] < memo[i][j - 1])
                {
                    memo[i][j] = memo[i - 1][j] + mat[i][j][pos];
                    dir[i][j] = 0;
                }
                else
                {
                    memo[i][j] = memo[i][j - 1] + mat[i][j][pos];
                    dir[i][j] = 1;
                }
            }
        }
        ini = 0;
    }
    if (memo[n - 1][n - 1] < nonZeroRes)
    {
        nonZeroRes = memo[n - 1][n - 1];
        path.clear();
        int r = n - 1, c = n - 1;
        while (r > 0 || c > 0)
        {
            if (r == 0)
            {
                c--;
                path.pb('R');
                continue;
            }
            if (c == 0)
            {
                r--;
                path.pb('D');
                continue;
            }
            if (dir[r][c] == 0)
            {
                r--;
                path.pb('D');
                continue;
            }
            c--;
            path.pb('R');
        }
    }
}

int main()
{
    fastio;
    untie;
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    cin >> n;
    mat = vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(2)));
    dir = vector<vector<bool>>(n, vector<bool>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> x;
            pair<int, int> c = factors(x);
            mat[i][j][0] = c.fr;
            mat[i][j][1] = c.sc;
            if (x == 0)
                zx = i;
        }
    dp(0);
    dp(1);
    if (zx != -1 && nonZeroRes > 0)
    {
        cout << 1 << endl;
        for (int i = 0; i < zx; i++)
            cout << "D";
        for (int i = 0; i < n - 1; i++)
            cout << "R";
        for (int i = zx; i < n - 1; i++)
            cout << "D";
        cout << endl;
        return 0;
    }
    reverse(path.begin(), path.end());
    cout << nonZeroRes << endl
         << path << endl;
}
