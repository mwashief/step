/*
    Washief Hossain Mugdho
    15 June 2021
    Codeforces 1501-1750 1534 1534F1
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
    vvi adj(n * m), adj_rev(n * m);
    vb used(n * m, false);
    vi scc(n * m, -1), order;
    int cnt = 0;
    auto getId = [&](int r, int c)
    {
        return r * m + c;
    };

    auto addEdge = [&](int a, int b)
    {
        adj[a].pb(b);
        adj_rev[b].pb(a);
    };

    char mat[n][m];
    rep(i, n) rep(j, m) cin >> mat[i][j];
    rep(j, m)
    {
        bool found = false;
        rep(i, n)
        {
            if (mat[i][j] == '#')
            {
                if (i > 0 && mat[i - 1][j] == '#')
                    addEdge(getId(i, j), getId(i - 1, j));
                found = true;
            }
            if (found)
            {
                if (j > 0 && mat[i][j - 1] == '#')
                    addEdge(getId(i, j), getId(i, j - 1));
                if (j < m - 1 && mat[i][j + 1] == '#')
                    addEdge(getId(i, j), getId(i, j + 1));
                if (i < n - 1)
                    addEdge(getId(i, j), getId(i + 1, j));
            }
        }
    }
    rep(i, n * m) if (!used[i])
        y_combinator([&](auto self, int v) -> void
                     {
                         used[v] = true;

                         for (auto u : adj[v])
                             if (!used[u])
                                 self(u);

                         order.push_back(v);
                     })(i);

    used.assign(n * m, false);
    reverse(a2z(order));
    for (auto v : order)
        if (!used[v])
        {
            y_combinator([&](auto self, int v) -> void
                         {
                             used[v] = true;
                             scc[v] = cnt;

                             for (auto u : adj_rev[v])
                                 if (!used[u])
                                     self(u);
                         })(v);
            cnt++;
        }

    seti res;
    vi indegree(n * m);
    rep(i, n * m) for (auto v : adj[i]) if (scc[i] != scc[v]) indegree[scc[v]]++;
    rep(i, n) rep(j, m) if (mat[i][j] == '#' && indegree[scc[getId(i, j)]] == 0) res.insert(scc[getId(i, j)]);
    cout << res.size() << endl;
}