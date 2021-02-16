/*
    Washief Hossain Mugdho
    09 December 2020
    Codeforces 1454E
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
int n, x, y;
vector<vector<int>> adj;
vector<int> parent;
unordered_set<int> cycle;

int dfs(int a, int p)
{
    parent[a] = p;
    for (auto child : adj[a])
        if (child != p)
        {
            if (parent[child] != -1)
            {
                parent[child] = -1;
                return a;
            }
            int k = dfs(child, a);
            if (k != -1)
                return k;
        }
    return -1;
}

ull getTreeSize(int a, int p)
{
    ull res = 1;
    for (auto child : adj[a])
        if (child != p && cycle.find(child) == cycle.end())
            res += getTreeSize(child, a);
    return res;
}

void findCycle()
{
    int oncycle = dfs(0, 0);
    while (1)
    {
        cycle.insert(oncycle);
        if (parent[oncycle] == -1)
            break;
        oncycle = parent[oncycle];
    }
}

void solve()
{
    cin >> n;
    adj = vector<vector<int>>(n, vector<int>());
    parent = vector<int>(n, -1);
    cycle.clear();
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        x--;
        y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    findCycle();
    vector<ull> trees;
    for (auto a : cycle)
        trees.pb(getTreeSize(a, a));
    ull ans = n;
    ans = ans * (ans - 1);
    for (int i = 0; i < trees.size(); i++)
        ans -= trees[i] * (trees[i] - 1) / 2ULL;
    cout << ans << endl;
}

int main()
{
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif

    int tc;
    cin >> tc;
    while (tc--)
        solve();
}
