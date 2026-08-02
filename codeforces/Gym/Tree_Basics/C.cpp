/*
    Washief Hossain Mugdho
    09 September 2020
    Tree Basics C
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
int x, y, n, q;
int d[300005][23];
vector<int> adj[300005];

void dfs(int a, int p, int dis)
{
    d[a][0] = dis;
    d[a][1] = p;
    for (int i = 0; i < adj[a].size(); i++)
    {
        if (adj[a][i] == p)
            continue;
        dfs(adj[a][i], a, dis + 1);
    }
}

int lift(int a, int level)
{
    if (level <= 0)
        return a;
    int i = 1;
    while (level != 0)
    {
        if (level & 1)
            a = d[a][i];
        level /= 2;
        i++;
        if (a == 0)
            return 0;
    }
    return a;
}

int getLCA(int a, int b)
{
    a = lift(a, d[a][0] - d[b][0]);
    b = lift(b, d[b][0] - d[a][0]);
    if (a == b)
        return a;
    for (int i = 21; i >= 0; i--)
    {
        int g = d[a][i];
        int h = d[b][i];
        if (g != h)
        {
            a = g;
            b = h;
        }
    }
    return d[a][1];
}

int main()
{
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> x >> y;
        x--;
        y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    dfs(0, 0, 0);

    for (int i = 2; i < 22; i++)
        for (int j = 0; j < n; j++)
            d[j][i] = d[d[j][i - 1]][i - 1];

    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> x >> y >> n;
        x--;
        y--;
        int lca = getLCA(x, y);
        if (d[x][0] - d[lca][0] >= n)
            cout << lift(x, n) + 1 << endl;
        else
            cout << lift(y, d[y][0] - 2 * d[lca][0] + d[x][0] - n) + 1 << endl;
    }
}
