/*
    Washief Hossain Mugdho
    16 January 2022
    Codeforces 1501-1750 1626 1626E
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
    int n;
    cin >> n;
    vi c(n);
    rep(i, n) cin >> c[i];
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
    vi res(n);
    rep(i, n)
    {
        if (c[i])
            res[i] = 1;
        for (auto d : adj[i])
            if (c[d])
                res[i] = 1;
    }
    vi down(n);
    vi black(n);
    vi up(n);

    y_combinator([&](auto self, int node, int parent) -> int
                 {
                     vi blacks;
                     blacks.pb(0);
                     int cc = 0;
                     for (auto child : adj[node])
                         if (child != parent)
                         {
                             down[node] += self(child, node);
                             blacks.pb(black[child]);
                             cc += c[child];
                             black[node] += black[child];
                         }
                     if (c[node] && black[node])
                         down[node] = 1;
                     black[node] += c[node];
                     if (black[node])
                         black[node] = 1;
                     if (down[node])
                         return down[node] = 1;
                     repe(i, gsz(blacks) - 1) blacks[i] += blacks[i - 1];
                     if (cc && blacks.back() > 1)
                         down[node] = 1;
                     return down[node];
                 })(0, -1);

    y_combinator([&](auto self, int node, int parent, int rev) -> void
                 {
                     vi children;
                     vi cc;
                     vi blacks;
                     vi dd;
                     cc.pb(0);
                     blacks.pb(0);
                     dd.pb(0);
                     for (int child : adj[node])
                         if (child != parent)
                         {
                             children.pb(child);
                             cc.pb(c[child]);
                             blacks.pb(black[child]);
                             dd.pb(down[child]);
                         }
                     if (parent != -1)
                     {
                         cc.pb(c[parent]);
                         blacks.pb(rev);
                         dd.pb(up[node]);
                     }
                     repe(i, gsz(cc) - 1)
                     {
                         cc[i] += cc[i - 1];
                         blacks[i] += blacks[i - 1];
                         dd[i] += dd[i - 1];
                     }
                     rep(i, gsz(children))
                     {
                         if (dd.back() - dd[i + 1] + dd[i])
                         {
                             up[children[i]] = 1;
                             self(children[i], node, blacks.back() - blacks[i + 1] + blacks[i] + c[node] > 0);
                         }
                         else if (c[node] && blacks.back() - blacks[i + 1] + blacks[i])
                         {
                             up[children[i]] = 1;
                             self(children[i], node, blacks.back() - blacks[i + 1] + blacks[i] + c[node] > 0);
                         }
                         else if (cc.back() - cc[i + 1] + cc[i] && blacks.back() - blacks[i + 1] + blacks[i] > 1)
                         {
                             up[children[i]] = 1;
                             self(children[i], node, blacks.back() - blacks[i + 1] + blacks[i] + c[node] > 0);
                         }
                         else
                             self(children[i], node, blacks.back() - blacks[i + 1] + blacks[i] + c[node] > 0);
                     }
                 })(0, -1, 0);
    rep(i, n) if (up[i] || down[i]) res[i] = 1;
    rep(i, n) cout << res[i] << " ";
    cout << endl;
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