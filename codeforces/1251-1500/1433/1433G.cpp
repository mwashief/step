/*
    Washief Hossain Mugdho
    16 May 2021
    Codeforces 1433 1433G
*/

#ifndef DEBUG
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")
#endif

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define pyes cout << "YES"
#define pno cout << "NO"
#define fastio ios_base::sync_with_stdio(0)
#define untie cin.tie(0)
#define rep(i, n) for (int i = 0; i < (n); (i)++)
#define repe(i, n) for (int i = 1; i <= (n); (i)++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; (i)--)
#define rrepe(i, n) for (int i = (n); i > 0; (i)--)
#define ms(a, b) memset(a, b, sizeof a)
#define a2z(x) (x).begin(), (x).end()
#define z2a(x) (x).rbegin(), (x).rend()
#define endl "\n"
#define gsz(v) ((int)(v).size())
#define MOD 1000000007 //998244353
#define MAX 1000005
const int INF = 1000000000;

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<ll>;
using vvb = vector<vector<bool>>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vpii = vector<pair<int, int>>;
using mii = map<int, int>;
using umii = unordered_map<int, int>;
using seti = set<int>;
using useti = unordered_set<int>;

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

    int n, m, k;
    cin >> n >> m >> k;
    vector<vpii> adj(n);
    vpii edges;
    rep(i, m)
    {
        int a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;
        edges.pb({a, b});
        adj[a].pb({b, w});
        adj[b].pb({a, w});
    }

    auto dijkstra = [&](int s, vector<int> &d)
    {
        d.assign(n, INF);
        d[s] = 0;
        set<pair<int, int>> q;
        q.insert({0, s});
        while (!q.empty())
        {
            int v = q.begin()->second;
            q.erase(q.begin());

            for (auto edge : adj[v])
            {
                int to = edge.first;
                int len = edge.second;

                if (d[v] + len < d[to])
                {
                    q.erase({d[to], to});
                    d[to] = d[v] + len;
                    q.insert({d[to], to});
                }
            }
        }
    };

    vpii routes(k);
    rep(i, k)
    {
        cin >> routes[i].fr >> routes[i].sc;
        routes[i].fr--;
        routes[i].sc--;
    }
    vi cost(k);
    int ans = 0;
    rep(i, k)
    {
        vi res;
        dijkstra(routes[i].fr, res);
        cost[i] = res[routes[i].sc];
        ans += cost[i];
    }

    for (auto edge : edges)
    {
        vi f, s;
        dijkstra(edge.fr, f);
        dijkstra(edge.sc, s);
        int res = 0;
        rep(i, k)
            res += min(cost[i], min(f[routes[i].fr], s[routes[i].fr]) + min(f[routes[i].sc], s[routes[i].sc]));
        ans = min(ans, res);
    }
    cout << ans << endl;
}
