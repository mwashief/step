/*
    Washief Hossain Mugdho
    19 September 2020
    Educational DP IndependentSet
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
#define mod 1000000007
using namespace std;
ll memo[100005][2];
int n, x, y;
list<int> adj[100005];

ll dp(int now, int parent, int prevCol)
{
    if (memo[now][prevCol] != -1)
        return memo[now][prevCol];
    ll res = 1;
    for (auto p : adj[now])
    {
        if (p != parent)
        {
            ll temp = dp(p, now, 1) % mod;
            if (prevCol)
                temp = (temp + dp(p, now, 0)) % mod;
            res = (res * temp) % mod;
        }
    }
    return memo[now][prevCol] = res;
}

int main()
{
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    cin >> n;
    ms(memo, -1);
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y;
        x--;
        y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    cout << (dp(0, -1, 0) + dp(0, -1, 1)) % mod << endl;
}
