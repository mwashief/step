/*
    Washief Hossain Mugdho
    03 September 2020
    UVa 11506
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
int n, x, y, g, f, h;

int adj[109][109];
vector<int> parent;

int findAug()
{
    vector<int> parent(n, -1);
    vector<int> cost(n, 100099);
    queue<int> Q;
    Q.push(0);
    while (!Q.empty())
    {
        int a = Q.front();
        if (a == x - 1)
            break;
        Q.pop();
        for (int i = 0; i < n; i++)
            if (parent[i] == -1 && adj[a][i])
                cost[i] = min(cost[a], adj[a][i]), Q.push(i), parent[i] = a;
    }
    if (parent[x - 1] == -1)
        return 0;
    int bottleneck = cost[x - 1];
    int a = x - 1;
    while (a)
    {
        adj[parent[a]][a] -= bottleneck;
        adj[a][parent[a]] += bottleneck;
        a = parent[a];
    }
    return bottleneck;
}

int outID(int a)
{
    if (a == 0 || a == x - 1)
        return a;
    return x + a - 1;
}
int main()
{
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif

    while (cin >> x >> y && !(x == 0 && y == 0))
    {
        ms(adj, 0);
        n = 2 * x - 2;
        for (int i = 0; i < x - 2; i++)
        {
            cin >> g >> f;
            g--;
            adj[g][outID(g)] = f;
        }
        for (int i = 0; i < y; i++)
        {
            cin >> g >> f >> h;
            g--;
            f--;
            adj[outID(g)][f] = h;
            adj[outID(f)][g] = h;
        }

        int res = 0;
        int a;
        while (a = findAug())
            res += a;
        cout << res << endl;
    }
}
