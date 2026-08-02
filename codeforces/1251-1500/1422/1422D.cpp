/*
    Washief Hossain Mugdho
    12 June 2021
    Codeforces 1251-1500 1422 1422D
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
#define MAX 2000000002

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

/* 
 * Dijskstra Algorithm for sparse graph.
 * Complexity : |V|log(|V|) + |E|
 * 
 * @author EmZie
 * 
 * 
 * @param adj adjacency list
 * @param source source node
 * @param init initial value of source node
 * @param INF lowest value considered as infinity
 * @param add edge value adding function
 * @param comp comparator function
 * @return distance vector of all nodes 
 */
template <class T>
std::vector<T> dijkstra(
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
            int edgeLength = node.second;
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
    vpii all(m + 1);
    pii destination;
    cin >> all[0].fr >> all[0].sc >> destination.fr >> destination.sc;
    repe(i, m) cin >> all[i].fr >> all[i].sc;
    vector<vpii> adj(m + 1);

    vi order(m + 1);
    iota(a2z(order), 0);

    sort(a2z(order), [&](int a, int b)
         { return all[a].sc < all[b].sc; });
    rep(i, m) adj[order[i]].pb({order[i + 1], abs(all[order[i]].sc - all[order[i + 1]].sc)});
    repe(i, m) adj[order[i]].pb({order[i - 1], abs(all[order[i]].sc - all[order[i - 1]].sc)});

    sort(a2z(order), [&](int a, int b)
         { return all[a].fr < all[b].fr; });
    rep(i, m) adj[order[i]].pb({order[i + 1], abs(all[order[i]].fr - all[order[i + 1]].fr)});
    repe(i, m) adj[order[i]].pb({order[i - 1], abs(all[order[i]].fr - all[order[i - 1]].fr)});

    auto d = dijkstra(adj, 0, 0, MAX);
    int res = INT32_MAX;
    rep(i, m + 1) res = min(res, d[i] + abs(destination.fr - all[i].fr) + abs(destination.sc - all[i].sc));
    cout << res << endl;
}