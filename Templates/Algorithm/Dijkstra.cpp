/*
    Washief Hossain Mugdho
    12 June 2021
    Templates Algorithm Dijkstra
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

#if !defined(__INTERACTIVE__) && !defined(__DEBUG__)
#define endl "\n"
#endif

typedef long long ll;
typedef unsigned long long ull;

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
#if !defined(__INTERACTIVE__) && !defined(__DEBUG__)
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
#endif
    using namespace std;
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    rep(i, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    auto d = dijkstra(
        adj, 0, 0, 999999);
    for (auto dd : d)
        cout << dd << endl;
}