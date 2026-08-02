/*
    Washief Hossain Mugdho
    04 November 2020
    Codeforces 1436D
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
#define MAX 200005
using namespace std;

vector<int> adj[MAX];
ll a[MAX];
ll extra[MAX];
ll res[MAX];
ll leafs[MAX];
int n, x;

void dfs(int node)
{
    if (adj[node].size() == 0)
    {
        res[node] = a[node];
        leafs[node] = 1;
        extra[node] = 0;
        return;
    }
    ll remaining = 0;
    ll currentMax = 0;
    for (auto child : adj[node])
    {
        dfs(child);
        currentMax = max(currentMax, res[child]);
        leafs[node] += leafs[child];
    }
    for (auto child : adj[node])
    {
        ll reducable = min(extra[child], a[node]);
        extra[child] -= reducable;
        a[node] -= reducable;
        remaining += extra[child];

        remaining += (currentMax - res[child]) * leafs[child];
        reducable = min((currentMax - res[child]) * leafs[child], a[node]);
        a[node] -= reducable;
        remaining -= reducable;
    }
    res[node] = currentMax;
    extra[node] = remaining;
    if (a[node] == 0)
        return;
    assert(extra[node] == 0);
    res[node] += (a[node] + leafs[node] - 1) / leafs[node];
    extra[node] += (leafs[node] - (a[node] % leafs[node])) % leafs[node];
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
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> x;
        adj[x - 1].push_back(i);
    }
    for (int i = 0; i < n; i++)
        cin >> a[i];
    dfs(0);
    cout << res[0] << endl;
}
