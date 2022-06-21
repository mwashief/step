/*
    Washief Hossain Mugdho
    09 September 2020
    Tree Basics A
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
int x, y, n, corner, maxLen;

vector<int> adj[300005];

void dfs(int a, int p, int dis)
{
    maxLen = max(maxLen, dis);
    if (dis == maxLen)
        corner = a;
    for (int i = 0; i < adj[a].size(); i++)
    {
        if (adj[a][i] == p)
            continue;
        dfs(adj[a][i], a, dis + 1);
    }
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
    dfs(0, -1, 0);
    dfs(corner, -1, 0);
    cout << 3 * maxLen << endl;
}
