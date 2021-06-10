/*
    Washief Hossain Mugdho
    10 June 2021
    Codeforces 1251-1500 1473 1473E
*/

#ifndef __DEBUG__
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")
#endif

#undef __INTERACTIVE__

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define pyes cout << "YES" //"Yes"
#define pno cout << "NO"   //"No"
#define fastio ios_base::sync_with_stdio(0)
#define untie cin.tie(0)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repe(i, n) for (int i = 1; i <= (n); i++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; i--)
#define rrepe(i, n) for (int i = (n); i > 0; i--)
#define ms(a, b) memset(a, b, sizeof a)
#define a2z(x) (x).begin(), (x).end()
#define z2a(x) (x).rbegin(), (x).rend()
#define gsz(v) ((int)(v).size())
#define MOD 1000000007 //998244353
#define MAX 1000005
#define INF 1000000000000000LL

#if !defined(__INTERACTIVE__) && !defined(__DEBUG__)
#define endl "\n"
#endif

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

using pii = pair<int, int>;
using pll = pair<ll, ll>;

using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<ll>;
using vpii = vector<pair<int, int>>;

using vvb = vector<vector<bool>>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vvpii = vector<vector<pair<int, int>>>;

using mii = map<int, int>;
using umii = unordered_map<int, int>;
using seti = set<int>;
using useti = unordered_set<int>;

int main()
{
    fastio;
#if !defined(__INTERACTIVE__) && !defined(__DEBUG__)
    untie;
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
#endif
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, ll>>> adj(n);
    rep(i, m)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--;
        v--;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    auto getNode = [=](int k, int tier) -> int
    {
        return tier * n + k;
    };

    auto getState = [=](int node) -> pii
    {
        int tier = node / n;
        int k = node % n;
        return {k, tier};
    };

    vl d(n << 2, INF);
    d[0] = 0;
    set<pair<ll, int>> q;
    q.insert({0, 0});

    auto relax = [&](int from, int to, ll len)
    {
        if (d[from] + len < d[to])
        {
            q.erase({d[to], to});
            d[to] = d[from] + len;
            q.insert({d[to], to});
        }
    };

    while (!q.empty())
    {
        int from = q.begin()->sc;
        auto v = getState(from);
        q.erase(q.begin());
        int k = v.fr;
        int tier = v.sc;
        for (auto edge : adj[k])
        {
            int node = edge.fr;
            ll w = edge.sc;
            if (tier == 0)
            {
                relax(from, getNode(node, 0), w);
                relax(from, getNode(node, 1), 0);
                relax(from, getNode(node, 2), w << 1);
                relax(from, getNode(node, 3), w);
            }
            else if (tier == 1)
            {
                relax(from, getNode(node, 1), w);
                relax(from, getNode(node, 3), w << 1);
            }
            else if (tier == 2)
            {
                relax(from, getNode(node, 2), w);
                relax(from, getNode(node, 3), 0);
            }
            else
                relax(from, getNode(node, 3), w);
        }
    }
    for (int i = 3 * n + 1; i < 4 * n; i++)
        cout << d[i] << " ";
    cout << endl;
}