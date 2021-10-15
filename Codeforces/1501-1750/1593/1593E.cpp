/*
    Washief Hossain Mugdho
    15 October 2021
    Codeforces 1501-1750 1593 1593E
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

    if (n <= 2)
    {
        cout << 0 << endl;
        return;
    }

    vi up(n, -1);
    int root;
    rep(i, n) if (gsz(adj[i]) > 1)
    {
        root = i;
        break;
    }
    vector<multiset<int, greater<int>>> branches(n);
    rep(i, n) branches[i].insert(1);

    y_combinator([&](auto self, int node, int parent) -> void
                 {
                     for (auto child : adj[node])
                         if (child != parent)
                         {
                             self(child, node);
                             branches[node].insert(*branches[child].begin() + 1);
                         }
                 })(root, -1);

    y_combinator([&](auto self, int node, int parent) -> void
                 {
                     vi children;
                     for (auto child : adj[node])
                         if (child != parent)
                             children.pb(child);
                     vi prefix(gsz(children)), suffix(gsz(children));
                     rep(i, gsz(children))
                     {
                         prefix[i] = *branches[children[i]].begin() + 2;
                         suffix[i] = *branches[children[i]].begin() + 2;
                     }
                     repe(i, gsz(children) - 1) prefix[i] = max(prefix[i], prefix[i - 1]);
                     rrep(i, gsz(children) - 1) suffix[i] = max(suffix[i], suffix[i + 1]);
                     rep(i, gsz(children))
                     {
                         if (i != 0)
                             up[children[i]] = prefix[i - 1];
                         if (i != gsz(children) - 1)
                             up[children[i]] = max(up[children[i]], suffix[i + 1]);
                         up[children[i]] = max(up[children[i]], up[node] + 1);
                     }
                     for (auto child : children)
                         self(child, node);
                 })(root, -1);
    int res = n;
    rep(i, n)
    {
        branches[i].insert(up[i]);
        branches[i].erase(branches[i].begin());
        if (*branches[i].begin() <= k)
            res--;
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
-> Check the copied part again
*/