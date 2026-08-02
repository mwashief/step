/*
    21 January 2023
    Codeforces 1751-2000 1777 1777E
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
std::vector<T> dijkstra(
    const std::vector<std::vector<std::pair<int, T>>> &adj,
    const int source,
    const T init,
    const T INF,
    const std::function<T(T, T)> add = [](T a, T b)
    { return max(a, b); },
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
                q.insert(std::make_pair(distance[to], to));
            }
        }
    }
    return distance;
}

inline void __run_test()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, ll>>> adj(n);
    while (m--)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--;
        v--;
        adj[u].pb({v, 0LL});
        adj[v].pb({u, w});
    }

    ll maximum = INT64_MAX >> 2;
    auto d1 = dijkstra(adj, 0, 0LL, maximum);

    auto ma = *max_element(a2z(d1));
    if (ma == maximum)
    {
        cout << -1 << endl;
        return;
    }

    int node = max_element(a2z(d1)) - d1.begin();

    auto d2 = dijkstra(adj,
                       node,
                       0LL,
                       maximum);

    node = max_element(a2z(d2)) - d2.begin();
    auto d3 = dijkstra(adj,
                       node,
                       0LL,
                       maximum);

    cout << *max_element(a2z(d3)) << endl;
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
    int __tests;
    cin >> __tests;
    while (__tests--)
        __run_test();
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