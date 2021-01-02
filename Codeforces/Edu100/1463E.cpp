/*
    Washief Hossain Mugdho
    18 December 2020
    Edu100 1463E
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
int n, k, x, y;
vector<vector<int>> child;
vector<vector<int>> parent;
vector<unordered_set<int>> edges;
vector<int> revEdges;
vector<int> visited;
vector<int> res;

bool hasCycle(int a)
{
    visited[a] = 1;
    bool res = false;
    for (auto b : edges[a])
    {
        if (visited[b] == 1)
            return true;
        if (!visited[b])
            res |= hasCycle(b);
    }
    visited[a] = 2;
    return res;
}

void dfs(int a)
{
    if (visited[a] != 0)
        return;
    visited[a] = 1;
    for (auto b : edges[a])
        dfs(b);

    if (child[a].size())
    {
        visited[child[a][0]] = 0;
        dfs(child[a][0]);
    }
    res.pb(a);
}

void update(int a, unordered_set<int> &grands)
{
    if (visited[a])
        return;
    visited[a] = 1;
    if (parent[a].size() == 0)
    {
        for (auto grand : grands)
            if (grand != a)
                edges[grand].insert(a);
        return;
    }
    grands.insert(revEdges[a]);
    update(parent[a][0], grands);
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
    cin >> n >> k;
    child = vector<vector<int>>(n + 1, vector<int>());
    parent = vector<vector<int>>(n + 1, vector<int>());
    edges = vector<unordered_set<int>>(n + 1, unordered_set<int>());
    revEdges = vector<int>(n + 1);
    visited = vector<int>(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        edges[x].insert(i);
        revEdges[i] = x;
    }
    for (int i = 0; i < k; i++)
    {
        cin >> x >> y;
        child[x].pb(y);
        parent[y].pb(x);
        edges[x].insert(y);
        if (revEdges[y] != 0 && revEdges[y] != x)
            edges[revEdges[y]].insert(x);
    }
    for (int i = 1; i <= n; i++)
        if (parent[i].size() > 1 || child[i].size() > 1 || (!visited[i] && hasCycle(i)))
        {
            cout << 0 << endl;
            return 0;
        }

    visited.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
        if (parent[i].size())
            visited[i] = 1;
    for (int i = 1; i <= n; i++)
        dfs(i);
    visited.assign(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        unordered_set<int> temp;
        update(res[i], temp);
    }

    res.clear();
    visited.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
        if (parent[i].size())
            visited[i] = 1;
    for (int i = 1; i <= n; i++)
        dfs(i);
    for (int i = n - 1; i >= 0; i--)
        cout << res[i] << " ";
    cout << endl;
}
