/*
    Washief Hossain Mugdho
    25 July 2021
    Codeforces 1501-1750 1547 1547G
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

    template <class T>
    T &unmove(T &&t) { return t; }

}

inline void __run_test()
{
    int n, m, componentCount = 0;
    cin >> n >> m;
    vvi adj(n), adj_rev(n), nodesInCompo;
    vi order, componentNo(n), visited(n);
    vb used(n);
    useti loops;
    rep(i, m)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        if (x == y)
        {
            loops.insert(x);
            continue;
        }
        adj[x].pb(y);
        adj_rev[y].pb(x);
    }

    for (int i = 0; i < n; i++)
        if (!used[i])
            y_combinator([&](auto self, int v) -> void
                         {
                             used[v] = true;

                             for (auto u : adj[v])
                                 if (!used[u])
                                     self(u);

                             order.push_back(v);
                         })(i);

    used.assign(n, false);
    reverse(order.begin(), order.end());

    for (auto v : order)
        if (!used[v])
        {
            nodesInCompo.pb(vi());
            y_combinator([&](auto self, int v) -> void
                         {
                             used[v] = true;
                             componentNo[v] = componentCount;
                             nodesInCompo.back().pb(v);

                             for (auto u : adj_rev[v])
                                 if (!used[u])
                                     self(u);
                         })(v);
            componentCount++;
        }

    vi compVisited(componentCount);
    vector<useti> compAdj(componentCount), compAdj_rev(componentCount);

    rep(i, n) for (auto v : adj[i])
    {
        compAdj[componentNo[i]].insert(componentNo[v]);
        compAdj_rev[componentNo[v]].insert(componentNo[i]);
    }
    vi memo(componentCount, -1);
    memo[componentNo[0]] = 1;

    rep(i, componentCount) if (memo[i] == -1) y_combinator([&](auto self, int component) -> int
                                                           {
                                                               if (memo[component] != -1)
                                                                   return memo[component];
                                                               memo[component] = 0;
                                                               for (auto parent : compAdj_rev[component])
                                                                   memo[component] = min(2, memo[component] + self(parent));
                                                               return memo[component];
                                                           })(i);

    rep(i, componentCount) if (memo[i] > 0)
    {
        if (gsz(nodesInCompo[i]) == 1 && loops.find(nodesInCompo[i][0]) != loops.end())
            memo[i] = -1;
        else if (gsz(nodesInCompo[i]) > 1)
            memo[i] = -1;
    }

    vb checked(n);
    rep(i, componentCount) if (!checked[i] && memo[i] == -1)
        y_combinator([&](auto self, int v) -> void
                     {
                         if (checked[v])
                             return;
                         checked[v] = true;
                         memo[v] = -1;
                         for (auto child : compAdj[v])
                             self(child);
                     })(i);

    rep(i, n) cout << memo[componentNo[i]] << " ";
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