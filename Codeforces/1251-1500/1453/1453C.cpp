/*
    Washief Hossain Mugdho
    05 December 2020
    Codeforces 1453C
*/

#ifndef DEBUG
#pragma GCC optimize("O3")
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

void solve()
{
    vector<int> area(10, 0);
    vector<int> xmax(10, 0);
    vector<int> ymax(10, 0);
    vector<int> xmin(10, 3000);
    vector<int> ymin(10, 3000);
    int n;
    cin >> n;
    char c;
    vector<vector<int>> mat(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> c;
            int x = c - '0';
            xmax[x] = max(xmax[x], i);
            xmin[x] = min(xmin[x], i);
            ymax[x] = max(ymax[x], j);
            ymin[x] = min(ymin[x], j);
            mat[i][j] = x;
        }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            int x = mat[i][j];
            int hor = max(n - 1 - i, i);
            int ver = max(n - 1 - j, j);
            hor = max(hor * (j - ymin[x]), hor * (ymax[x] - j));
            ver = max(ver * (i - xmin[x]), ver * (xmax[x] - i));
            area[x] = max(area[x], hor);
            area[x] = max(area[x], ver);
        }
    for (int i = 0; i < 10; i++)
        cout << area[i] << " ";
    cout << endl;
}

int main()
{
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        solve();
}
