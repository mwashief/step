/*
    Washief Hossain Mugdho
    20 November 2021
    HackerEarth nov-circuit B
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
    int n, k;
    cin >> n >> k;
    vi a(n);
    rep(i, n) cin >> a[i];
    vvi adj(n);
    rep(i, n - 1)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vl sum(n), xsum(n), up(n);
    y_combinator([&](auto self, int node, int parent) -> ll
                 {
                     sum[node] = a[node];
                     for (auto child : adj[node])
                         if (child != parent)
                             sum[node] += self(child, node);
                     return sum[node];
                 })(0, -1);
    y_combinator([&](auto self, int node, int parent) -> ll
                 {
                     xsum[node] = a[node] ^ k;
                     for (auto child : adj[node])
                         if (child != parent)
                             xsum[node] += self(child, node);
                     return xsum[node];
                 })(0, -1);
    ll res = max(sum[0], xsum[0]);
    queue<pii> q;
    q.push({0, -1});
    auto calc = y_combinator([&](auto self, int node, int parent) -> void
                             {
                                 vi children;
                                 vl down, xdown;
                                 children.pb(-1);
                                 down.pb(0);
                                 xdown.pb(0);
                                 for (auto child : adj[node])
                                     if (child != parent)
                                     {
                                         children.pb(child);
                                         down.pb(sum[child]);
                                         xdown.pb(xsum[child]);
                                     }
                                 children.pb(-1);
                                 down.pb(0);
                                 xdown.pb(0);
                                 vl suffix(gsz(down)), prefix(gsz(down));
                                 repe(i, gsz(xdown) - 2) prefix[i] = prefix[i - 1] + xdown[i];
                                 rrepe(i, gsz(xdown) - 2) suffix[i] = suffix[i + 1] + xdown[i];
                                 repe(i, gsz(children) - 2)
                                     up[children[i]] = prefix[i - 1] + suffix[i + 1] + up[node] + (a[node] ^ k);
                                 down.back() = sum[0] - sum[node];
                                 xdown.back() = up[node];
                                 children.pb(parent);
                                 down.pb(0);
                                 xdown.pb(0);
                                 prefix.pb(0LL);
                                 suffix.pb(0LL);
                                 repe(i, gsz(xdown) - 2) prefix[i] = prefix[i - 1] + xdown[i];
                                 rrepe(i, gsz(xdown) - 2) suffix[i] = suffix[i + 1] + xdown[i];

                                 repe(i, gsz(prefix) - 2) res = max(res, prefix[i - 1] + suffix[i + 1] + (a[node] ^ k) + down[i]);
                                 repe(i, gsz(children) - 3) q.push({children[i], node});
                             });
    while (q.size())
    {
        auto d = q.front();
        q.pop();
        calc(d.fr, d.sc);
    }

    cout << res << endl;
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
*/