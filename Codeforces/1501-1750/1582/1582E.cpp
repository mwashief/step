/*
    Washief Hossain Mugdho
    24 October 2021
    Codeforces 1501-1750 1582 1582E
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
#define MAX 100005

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

ll find(ll n)
{
    ll l = 0, r = n;
    while (l < r)
    {
        ll mid = (l + r) >> 1;
        if (mid * (mid + 1) / 2LL >= n)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}

ll a[MAX], prefix[MAX], memo[MAX][450];

inline void __run_test()
{
    int n;
    cin >> n;
    rep(i, n) cin >> a[i];
    rep(i, n) prefix[i + 1] = prefix[i] + a[i];
    int d = find(n) + 2;
    rep(i, n) rep(j, d + 1) memo[i][j] = -1;

    auto dp = y_combinator([&](auto self, int i, int j) -> ll
                           {
                               if (j == 0)
                                   return INT64_MAX;
                               if (n - i < j || i >= n)
                                   return -2;
                               if (memo[i][j] != -1)
                                   return memo[i][j];
                               ll res = -2;
                               ll temp = self(i + j, j - 1);
                               if (temp != -2 && temp > prefix[i + j] - prefix[i])
                                   res = prefix[i + j] - prefix[i];
                               res = max(res, self(i + 1, j));

                               return memo[i][j] = res;
                           });
    rrep(i, d) if (dp(0, i) != -2)
    {
        cout << i << endl;
        return;
    }
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