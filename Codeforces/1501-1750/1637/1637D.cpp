/*
    Washief Hossain Mugdho
    12 February 2022
    Codeforces 1501-1750 1637 1637D
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
    int n;
    cin >> n;
    vi a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    int sum = 0;
    rep(i, n) sum += a[i] + b[i];
    vvi memo(n, vi(sum + 1, -1));
    vvb parent(n, vb(sum + 1));
    ll res = 0;

    auto dp = y_combinator([&](auto self, int node, int total) -> bool
                           {
                     if (total < 0)
                         return false;
                     if (node == -1 && total == 0)
                         return true;
                    if(node == -1) return false;
                     if (memo[node][total] != -1)
                         return memo[node][total];

                     if (self(node - 1, total - a[node]))
                     {
                         memo[node][total] = 1;
                         parent[node][total] = 0;
                         return true;
                     }
                     if (self(node - 1, total - b[node]))
                     {
                         memo[node][total] = 1;
                         parent[node][total] = 1;
                         return true;
                     }memo[node][total] = 0; return false; });

    int mm = sum / 2;
    vi x, y;
    rrepe(i, mm) if (dp(n - 1, i))
    {
        int j = n - 1;
        int s = i;
        while (j >= 0)
        {
            if (parent[j][s])
            {
                x.pb(b[j]);
                y.pb(a[j]);
                s -= b[j];
            }
            else
            {
                x.pb(a[j]);
                y.pb(b[j]);
                s -= a[j];
            }
            j--;
        }
        break;
    }

    rep(i, n) for (int j = i + 1; j < n; j++)
    {
        res += 1LL * (x[i] + x[j]) * (x[i] + x[j]);
        res += 1LL * (y[i] + y[j]) * (y[i] + y[j]);
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
-> Check simple logic errors
-> Read problem statements carefully
*/