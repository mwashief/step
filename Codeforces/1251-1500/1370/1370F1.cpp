/*
    Washief Hossain Mugdho
    16 June 2021
    Codeforces 1251-1500 1370 1370F1
*/

#ifndef __DEBUG__
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")
#endif

#define __INTERACTIVE__

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
int root, dist;
pii query(vi &given, int k)
{
    vi v;
    for (auto x : given)
        if (x != k)
            v.pb(x);
    if (v.size() == 0)
        return {k, dist};

    cout << "? " << v.size();
    for (auto d : v)
        cout << " " << d;
    cout << endl;
    int x, y;
    cin >> x >> y;
    return {x, y};
}

inline void __run_test()
{
    int n;
    cin >> n;
    vvi adj(n + 1);
    rep(i, n - 1)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vi parent(n + 1), depth(n + 1);
    iota(a2z(parent), 1);
    auto temp = query(parent, n + 1);
    root = temp.fr;
    dist = temp.sc;

    vvi level(dist + 1);
    queue<tuple<int, int, int>> s;
    for (auto d : adj[root])
        s.push({d, root, 1});
    level[0].pb(root);
    parent[root] = root;
    depth[root] = 0;
    while (s.size())
    {
        auto top = s.front();
        s.pop();
        int u = get<0>(top);
        int par = get<1>(top);
        int d = get<2>(top);
        parent[u] = par;
        depth[u] = d;
        if (d > dist)
            continue;
        level[d].pb(u);
        for (auto v : adj[u])
            if (v != par)
                s.push({v, u, d + 1});
    }
    int l = 1, r = dist;
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        if (level[mid].size() && query(level[mid], -1).sc <= dist)
            l = mid;
        else
            r = mid - 1;
    }
    int x = query(level[l], -1).fr;
    root = x;
    while (depth[root] > dist - l)
        root = parent[root];
    int y = query(level[dist - l], root).fr;
    cout << "! " << x << " " << y << endl;
    string ss;
    cin >> ss;
    if (ss != "Correct")
        exit(0);
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