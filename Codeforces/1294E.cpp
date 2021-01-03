/*
    Washief Hossain Mugdho
    07 August 2020
    Codeforces 1294E
*/

#pragma GCC optimize("O3")
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

int main()
{
    int n, m;
    cin >> n >> m;
    int grid[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        vector<int> unsupported(n, n);
        for (int j = 0; j < n; j++)
        {
            if (grid[j][i] % m != (i + 1) % m)
                continue;
            int actualPlace = (grid[j][i] - 1 - i) / m;
            if (actualPlace >= n)
                continue;
            int move = (j - actualPlace + n) % n;
            unsupported[move]--;
        }
        int neededMove = INT32_MAX;
        for (int i = 0; i < n; i++)
            neededMove = min(neededMove, i + unsupported[i]);
        ans += neededMove;
    }
    cout << ans << endl;
}
