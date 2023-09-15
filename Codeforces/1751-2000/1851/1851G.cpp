/*
    15 September 2023
    Codeforces 1751-2000 1851 1851G
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

/* DS : Disjoint Set Union
 * Elements are numbered from 0 to n-1
 */
class DSU
{
public:
    int n;
    std::vector<int> parent, subsetSize;
    DSU(int numberOfElements) : n(numberOfElements)
    {
        parent = std::vector<int>(numberOfElements);
        subsetSize = std::vector<int>(numberOfElements, 1);
        std::iota(parent.begin(), parent.end(), 0);
    }

    int getRepresentative(int subset)
    {
        if (parent[subset] == subset)
            return subset;
        return parent[subset] = getRepresentative(parent[subset]);
    }

    bool isConnected(int subset1, int subset2)
    {
        return getRepresentative(subset1) == getRepresentative(subset2);
    }

    bool join(int subset1, int subset2)
    {
        if (isConnected(subset1, subset2))
            return false;
        subset1 = getRepresentative(subset1);
        subset2 = getRepresentative(subset2);
        if (subsetSize[subset1] < subsetSize[subset2])
            swap(subset1, subset2);
        subsetSize[subset1] += subsetSize[subset2];
        parent[subset2] = subset1;
        return true;
    }
};

inline void __run_test()
{
    int n, m;
    cin >> n >> m;
    vpii edges(m);
    vi h(n);
    rep(i, n) cin >> h[i];
    rep(i, m)
    {
        cin >> edges[i].fr >> edges[i].sc;
        edges[i].fr--;
        edges[i].sc--;
        if (h[edges[i].fr] > h[edges[i].sc])
            swap(edges[i].fr, edges[i].sc);
    }

    sort(
        a2z(edges),
        [&](pii a, pii b) -> bool
        {
            return h[a.sc] > h[b.sc];
        });

    DSU dsu(n);
    int q;
    cin >> q;
    vector<pair<pii, pii>> queries(q);
    rep(i, q)
    {
        cin >> queries[i].fr.fr >> queries[i].fr.sc >> queries[i].sc.fr;
        queries[i].fr.fr--;
        queries[i].fr.sc--;
        queries[i].sc.sc = i;
    }

    sort(a2z(queries), [&](auto u, auto v) -> bool
         { return h[u.fr.fr] + u.sc.fr < h[v.fr.fr] + v.sc.fr; });

    vi res(q);
    rep(i, q)
    {
        int u = queries[i].fr.fr;
        int v = queries[i].fr.sc;
        int w = queries[i].sc.fr;
        int index = queries[i].sc.sc;
        while (gsz(edges) && h[edges.back().sc] <= h[u] + w)
        {
            auto edge = edges.back();
            dsu.join(edge.fr, edge.sc);
            edges.pop_back();
        }
        res[index] = dsu.isConnected(u, v);
    }

    for (auto r : res)
        if (r)
            pyes << endl;
        else
            pno << endl;

    cout << endl;
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
