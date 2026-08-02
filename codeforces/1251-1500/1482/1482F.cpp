/*
    Washief Hossain Mugdho
    10 June 2021
    Codeforces 1251-1500 1482 1482F
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
#define INF 220000000

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
    vector<vpii> adj(n), triples(n);
    vvi dis(n, vi(n, INF));
    rep(i, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
        dis[u][v] = w;
        dis[v][u] = w;
    }
    rep(i, n) dis[i][i] = 0LL;
    rep(k, n) rep(i, n) rep(j, n) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);

    int q;
    cin >> q;
    rep(i, q)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        triples[u].pb({v, w});
        triples[v].pb({u, w});
    }

    auto edgeHash = [](int a, int b)
    {
        if (a > b)
            swap(a, b);
        return a * 601 + b;
    };

    bool useful[360700];
    ms(useful, 0);
    rep(v, n) if (triples[v].size())
    {
        vb inCloud(n);
        vi d(n, INF);
        for (auto u : triples[v])
            d[u.fr] = -u.sc;

        rep(step, n - 1)
        {
            int least = INF;
            int u;
            rep(i, n) if (!inCloud[i] && d[i] < least)
            {
                least = d[i];
                u = i;
            }
            inCloud[u] = 1;
            if (least == INF)
                break;
            for (auto child : adj[u])
                if (d[child.fr] > least + child.sc)
                    d[child.fr] = least + child.sc;
        }

        rep(a, n) for (auto b : adj[a]) if (d[b.fr] <= -b.sc - dis[v][a]) useful[edgeHash(a, b.fr)] = 1;
    }

    int ans = 0;
    rep(i, 360700) ans += useful[i];
    cout << ans << endl;
}