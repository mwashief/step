/*
    Washief Hossain Mugdho
    09 June 2021
    Codeforces 1001-1250 1029 1029E
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
    vvi memo(n, vi(3, -1));
    auto dp = y_combinator([&](auto self, int node, int parent, int state) -> int
                           {
                               if (memo[node][state] != -1)
                                   return memo[node][state];
                               int connect = 1, not_connect = 0;

                               for (auto child : adj[node])
                                   if (child != parent)
                                       connect += self(child, node, 0);

                               if (state == 0)
                               {
                                   for (auto child : adj[node])
                                       if (child != parent)
                                           not_connect += self(child, node, 1);
                                   return memo[node][state] = min(connect, not_connect);
                               }
                               if (state == 1)
                               {
                                   vi one, two;
                                   one.pb(0);
                                   two.pb(0);
                                   for (auto child : adj[node])
                                       if (child != parent)
                                       {
                                           one.pb(self(child, node, 1));
                                           two.pb(self(child, node, 2));
                                       }
                                   repe(i, one.size() - 1) one[i] += one[i - 1];
                                   not_connect = INT32_MAX;
                                   repe(i, one.size() - 1)
                                       not_connect = min(not_connect, two[i] + one[i - 1] + one.back() - one[i]);
                                   return memo[node][state] = min(connect, not_connect);
                               }
                               return memo[node][state] = connect;
                           });
    int res = 0;
    for (auto start : adj[0])
        for (auto child : adj[start])
            if (child != 0)
                res += dp(child, start, 0);
    cout << res << endl;
}