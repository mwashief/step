/*
    Washief Hossain Mugdho
    24 August 2020
    UVa 11747
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

int n, m, q, x, y, z;
vector<pair<int, pair<int, int>>> edges;
vector<pair<int, int>> graph[105];

int parent[1004];

void iniDSU()
{
    for (int i = 0; i < n; i++)
        parent[i] = i;
}

int getParent(int a)
{
    if (parent[a] != a)
        parent[a] = getParent(parent[a]);
    return parent[a];
}

void DSU(int a, int b)
{
    parent[parent[a]] = parent[parent[b]] = min(getParent(a), getParent(b));
}

void kruskal()
{
    int taken = 0;
    iniDSU();
    sort(edges.begin(), edges.end());
    for (int i = 0; i < edges.size() && taken < n - 1; i++)
    {
        int a = edges[i].sc.fr;
        int b = edges[i].sc.sc;
        if (getParent(a) == getParent(b))
            continue;
        taken++;
        DSU(a, b);
        graph[a].pb(mp(b, edges[i].fr));
        graph[b].pb(mp(a, edges[i].fr));
    }
}

int dfs(int a, int parent, int cost)
{
    if (a == y)
        return cost;
    int res = -1;
    for (int i = 0; i < graph[a].size(); i++)
        if (graph[a][i].fr != parent)
            res = max(res, dfs(graph[a][i].fr, a, max(cost, graph[a][i].sc)));
    return res;
}

int main()
{
    int tt = 1;
    while (cin >> n >> m >> q && !(n == 0 && m == 0 && q == 0))
    {
        edges.clear();
        for (int i = 0; i < n; i++)
            graph[i].clear();
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y >> z;
            edges.pb(mp(z, mp(x - 1, y - 1)));
        }
        kruskal();
        if (tt != 1)
            cout << endl;
        cout << "Case #" << tt << endl;
        for (int i = 0; i < q; i++)
        {
            cin >> x >> y;
            x--;
            y--;
            int res = dfs(x, -1, 0);
            if (res < 0)
                cout << "no path";
            else
                cout << res;
            cout << endl;
        }
        tt++;
    }
}
