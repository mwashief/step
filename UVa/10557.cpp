/*
    Washief Hossain Mugdho
    28 August 2020
    UVa 10557
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

int n;
vector<bool> visited;
vector<vector<int>> adj;

bool dfs(int a)
{
    visited[a] = 1;
    if (a == n - 1)
        return 1;
    int res = false;
    for (int i = 0; i < adj[a].size(); i++)
        if (visited[adj[a][i]] == 0)
            res |= dfs(adj[a][i]);

    return res;
}

int main()
{
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif

    int x, y, k;
    while (cin >> n && n != -1)
    {
        int energy[n];
        adj = vector<vector<int>>(n, vector<int>());
        for (int i = 0; i < n; i++)
        {
            cin >> energy[i] >> x;
            for (int j = 0; j < x; j++)
            {
                cin >> y;
                if (y < 1 || y > n)
                    continue;
                adj[i].pb(y - 1);
            }
        }

        vector<int> d(n, INT32_MIN);
        bool changed = true;
        d[0] = 100;
        for (k = 0; k < n && changed; k++)
        {
            changed = false;
            for (int i = 0; i < n - 1; i++)
            {
                if (d[i] > 0)
                    for (int j = 0; j < adj[i].size(); j++)
                    {
                        int next = adj[i][j];
                        int cost = d[i] + energy[next];
                        if (cost > 0 && cost > d[next])
                        {
                            d[next] = cost;
                            changed = true;
                        }
                    }
            }
        }

        if (d[n - 1] > 0)
            cout << "winnable" << endl;
        else if (!changed)
            cout << "hopeless" << endl;
        else
        {
            vector<int> inCycle;
            for (int i = 0; i < n; i++)
            {
                if (d[i] > 0)
                    for (int j = 0; j < adj[i].size(); j++)
                    {
                        int next = adj[i][j];
                        int cost = d[i] + energy[next];
                        if (cost > 0 && cost > d[next])
                        {
                            d[next] = cost;
                            inCycle.push_back(next);
                        }
                    }
            }

            bool res = false;
            visited = vector<bool>(n, 0);
            for (int i = 0; i < inCycle.size(); i++)
            {
                if (visited[inCycle[i]] == 0)
                    res = dfs(inCycle[i]);
                if (res)
                    break;
            }

            if (res)
                cout << "winnable" << endl;
            else
                cout << "hopeless" << endl;
        }
    }
}
