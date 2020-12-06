/*
    Washief Hossain Mugdho
    06 December 2020
    Codeforces 688E
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
int k = 0;
vector<vector<int>> adj;

int dfs(int a, int parent)
{
    vector<int> children;
    for (auto x : adj[a])
        if (x != parent)
            children.pb(dfs(x, a) + 1);
    if (children.size() == 0) //leaf
        return 0;
    if (children.size() == 1) // single path
    {
        k = max(k, children[0]);
        return children[0];
    }
    sort(children.begin(), children.end());
    if (a == 0)
        k = max({k, children.back(), children[children.size() - 2] + 1});
    else
        k = max({k, children.back() + 1});
    return children[0];
}

void solve()
{
    int x, y;
    cin >> n;
    adj = vector<vector<int>>(n, vector<int>());
    k = 0;
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y;
        adj[x - 1].pb(y - 1);
        adj[y - 1].pb(x - 1);
    }
    dfs(0, -1);
    cout << k << endl;
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
