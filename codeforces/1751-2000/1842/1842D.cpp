/*
    24 June 2023
    Codeforces 1751-2000 1842 1842D
*/

#ifndef __DEBUG__
#pragma GCC optimize("Ofast")
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
#define MOD 1000000007 // 998244353
#define MAX 1000005

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

template <class T>
pair<std::vector<T>, std::vector<pair<int, T>>> dijkstra(
    std::vector<std::vector<std::pair<int, T>>> &adj,
    const int source,
    const T init,
    const T INF,
    const std::function<T(T, T)> add = [](T a, T b)
    { return a + b; },
    const std::function<bool(T, T)> comp = [](T a, T b)
    { return a < b; })
{
    auto setComparator = [comp](std::pair<T, int> a, std::pair<T, int> b)
    {
        if (!comp(a.first, b.first) && !comp(b.first, a.first))
            return a.second < b.second;
        return comp(a.fr, b.fr);
    };

    std::vector<T> distance(adj.size(), INF);
    std::vector<pair<int, T>> parent(adj.size(), {-1, -1});
    distance[source] = init;
    std::set<std::pair<T, int>, decltype(setComparator)> q(setComparator);
    q.insert(std::make_pair(init, source));
    while (!q.empty())
    {
        int from = q.begin()->sc;
        q.erase(q.begin());
        for (auto node : adj[from])
        {
            int to = node.first;
            T edgeLength = node.second;
            auto newDistance = add(distance[from], edgeLength);
            if (comp(newDistance, distance[to]))
            {
                q.erase(std::make_pair(distance[to], to));
                distance[to] = newDistance;
                parent[to] = {from, edgeLength};
                q.insert(std::make_pair(distance[to], to));
            }
        }
    }
    return {distance, parent};
}

namespace std
{

    template <class Fun>
    class y_combinator_result
    {
        Fun fun_;

    public:
        template <class T>
        explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}

        template <class... Args>
        decltype(auto) operator()(Args &&...args)
        {
            return fun_(std::ref(*this), std::forward<Args>(args)...);
        }
    };

    template <class Fun>
    decltype(auto) y_combinator(Fun &&fun)
    {
        return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
    }

}

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
    std::vector<std::vector<std::pair<int, ll>>> adj(n);
    while (m--)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--;
        v--;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    auto dij = dijkstra(adj, n - 1, 0LL, INT64_MAX / 4LL);
    auto dist = dij.fr;
    auto parent = dij.sc;

    if (parent[0].fr == -1)
    {
        cout << "inf" << endl;
        return 0;
    }

    rep(i, n) dist[i] = min(dist[i], dist[0]);
    vector<pair<ll, int>> temp;
    vector<pair<vector<int>, ll>> res = {{vi(n, 0), dist[0]}};

    rep(i, n) temp.pb({dist[i], i});
    sort(a2z(temp), [&](auto a, auto b) -> bool
         {
        if(a.fr < b.fr) return true;
        if(b.fr < a.fr) return false;
        return a.sc > b.sc; });

    rep(i, n)
    {
        rep(j, gsz(res)) if (res[j].sc <= temp[i].fr)
        {
            res[j].fr[temp[i].sc] = 1;
            temp[i].fr -= res[j].sc;
        }

        if (temp[i].fr)
        {
            res.pb(res.back());
            res[gsz(res) - 2].fr[temp[i].sc] = 1;
            res.back().sc = res[gsz(res) - 2].sc - temp[i].fr;
            res[gsz(res) - 2].sc = temp[i].fr;
        }
    }

    cout << dist[0] << " " << gsz(res) << endl;
    rep(i, gsz(res))
    {
        rep(j, n) cout << res[i].fr[j];
        cout << " " << res[i].sc << endl;
    }
}

/*
-> Check for data types
-> Fix macro
-> Run test case
-> Check the copied part
-> Set or multiset?
-> Check statement order
-> Check simple logic errors
-> Read problem statements carefully
*/