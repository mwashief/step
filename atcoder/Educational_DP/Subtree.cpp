/*
    Washief Hossain Mugdho
    21 September 2020
    Educational DP Subtree
*/

#ifndef DEBUG
#pragma GCC optimize("-O2")
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
int n, mod, x, y;
const int mx = 1e5 + 5;
ll down[mx], up[mx];
list<int> adj[mx];

void downPaths(int a, int parent)
{
    for (auto i : adj[a])
        if (i != parent)
        {
            downPaths(i, a);
            down[a] = (down[a] * (down[i] + 1)) % mod;
        }
}

void upPaths(int a, int parent)
{
    vector<int> children;
    for (int i : adj[a])
        if (i != parent)
            children.pb(i);

    ll suffix[children.size() + 2], prefix[children.size() + 2];
    prefix[0] = suffix[children.size() + 1] = 1;

    for (int i = 0; i < children.size(); i++)
    {
        prefix[i + 1] = (prefix[i] * (down[children[i]] + 1)) % mod;
        suffix[children.size() - i] = (suffix[children.size() - i + 1] * (down[children[children.size() - i - 1]] + 1)) % mod;
    }

    for (int i = 0; i < children.size(); i++)
    {
        ll res = (prefix[i] * suffix[i + 2]) % mod;
        res = (res * up[a] + 1) % mod;
        up[children[i]] = res;
        upPaths(children[i], a);
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
    cin >> n >> mod;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    for (int i = 1; i <= n; i++)
        down[i] = up[i] = 1;
    downPaths(1, 0);
    upPaths(1, 0);
    for (int i = 1; i <= n; i++)
        cout << (down[i] * up[i]) % mod << endl;
}
