/*
    Washief Hossain Mugdho
    11 September 2020
    Tree Basics E
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
#define mx 100005
using namespace std;
int tt, n, q, cases;
int startTime[mx];
int endTime[mx];
int parent[mx];
ll t[mx];
vector<int> adj[mx];

void dfs()
{
    stack<pair<int, int>> S;
    S.push(mp(1, 0));
    while (!S.empty())
    {
        int a = S.top().fr;
        int p = S.top().sc;
        S.pop();
        if (a < 0)
        {
            endTime[-a] = tt;
            continue;
        }
        S.push(mp(-a, 0));
        startTime[a] = ++tt;
        parent[a] = p;
        for (int i = 0; i < adj[a].size(); i++)
            if (adj[a][i] != p)
                S.push(mp(adj[a][i], a));
    }
}

ll read(int idx)
{
    ll sum = 0;
    while (idx > 0)
    {
        sum += t[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void update(int idx, ll val)
{
    while (idx <= n)
    {
        t[idx] += val;
        idx += (idx & -idx);
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
    fastio;
    untie;
    cin >> cases;
    for (int cc = 1; cc <= cases; cc++)
    {
        cin >> n >> q;
        for (int i = 1; i <= n; i++)
        {
            adj[i].clear();
            t[i] = 0;
        }
        t[0] = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int x, y;
            cin >> x >> y;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        tt = 0;
        dfs();
        for (int i = 0; i < q; i++)
        {
            ll x, y, z;
            cin >> x >> y >> z;
            if (z == 0)
            {
                int p;
                if (parent[y] == x)
                    p = y;
                else
                    p = x;
                cout << abs(read(endTime[p]) - read(startTime[p] - 1)) << endl;
            }
            else
            {
                update(startTime[x], z);
                update(startTime[y], -z);
            }
        }
    }
}
