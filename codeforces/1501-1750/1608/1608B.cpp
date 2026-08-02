/*
    Washief Hossain Mugdho
    11 December 2021
    Codeforces 1501-1750 1608 1608B
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
    int n, a, b;
    cin >> n >> a >> b;
    int aa = a;
    int bb = b;
    if (a + b > n - 2)
    {
        cout << -1 << endl;
        return;
    }
    if (abs(a - b) > 1)
    {
        cout << -1 << endl;
        return;
    }

    vi d(n);
    for (int i = 1; i < n - 1; i++)
    {
        if (d[i - 1] == 0)
        {
            if (a > 0 && a >= b)
            {
                d[i] = 1;
                a--;
            }
            else if (b > 0 && b >= a)
            {
                d[i] = -1;
                b--;
            }
        }
        if (d[i - 1] == -1 && a)
        {
            a--;
            d[i] = 1;
        }
        else if (d[i - 1] == 1 && b)
        {
            b--;
            d[i] = -1;
        }
    }
    if (a || b)
    {
        cout << -1 << endl;
        return;
    }
    vvi adj(n);
    for (int i = 1; i < n - 1; i++)
        if (d[i] == 1)
        {
            adj[i - 1].pb(i);
            adj[i + 1].pb(i);
        }
        else if (d[i] == -1)
        {
            adj[i].pb(i - 1);
            adj[i].pb(i + 1);
        }
        else
            break;
    int sign = 1;
    rrep(i, n) if (d[i])
    {
        sign = d[i];
        break;
    }

    if (sign == 1)
    {
        for (int i = aa + bb; i < n - 1; i++)
            adj[i + 1].pb(i);
    }
    else
    {
        for (int i = aa + bb; i < n - 1; i++)
            adj[i].pb(i + 1);
    }
    vb visited(n);
    vi all;
    rep(i, n) if (!visited[i])
    {
        visited[i] = true;
        y_combinator([&](auto self, int node) -> void
                     {
                         for (auto c : adj[node])
                             if (!visited[c])
                             {
                                 visited[c] = 1;
                                 self(c);
                             }
                         all.pb(node);
                     })(i);
    }
    vi res(n);
    int now = n;
    rep(i, n) res[all[i]] = now--;
    rep(i, n) cout << res[i] << " ";
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
*/