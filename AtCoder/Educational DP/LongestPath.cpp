/*
    Washief Hossain Mugdho
    17 September 2020
    Educational DP LongestPath
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
int n, m, x, y, ans;
vector<int> adj[100005];
int memo[100005];
bool visited[100005];
stack<int> topSort;

void dfs(int a)
{
    if (visited[a])
        return;
    visited[a] = 1;
    for (int i = 0; i < adj[a].size(); i++)
        dfs(adj[a][i]);
    topSort.push(a);
}

int dp(int a)
{
    if (memo[a])
        return memo[a];
    int res = 1;
    for (int i = 0; i < adj[a].size(); i++)
        res = max(res, 1 + dp(adj[a][i]));
    return memo[a] = res;
}

int main()
{
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        adj[x - 1].pb(y - 1);
    }
    for (int i = 0; i < n; i++)
        if (!visited[i])
            dfs(i);

    while (!topSort.empty())
    {
        ans = max(ans, dp(topSort.top()));
        topSort.pop();
    }
    cout << ans - 1 << endl;
}
