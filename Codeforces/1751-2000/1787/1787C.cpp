/*
    29 January 2023
    Codeforces 1751-2000 1787 1787C
*/

#ifndef __DEBUG__
#pragma GCC optimize("Ofast")
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

}

inline void __run_test()
{
    int n, s;
    cin >> n >> s;
    vvi a(n, vi(2));
    rep(i, n) cin >> a[i][0];
    repe(i, n - 2)
    {
        if (a[i][0] > s)
        {
            a[i][1] = a[i][0] - s;
            a[i][0] = s;
        }

        if (a[i][0] > a[i][1])
            swap(a[i][0], a[i][1]);
    }
    a[0][1] = a[0][0];
    a[0][0] = 0;
    a[n - 1][1] = a[n - 1][0];

    vvl memo(n, vl(2, -1));
    cout << y_combinator(
                [&](auto self, int now, int ind) -> ll
                {
                    if (now >= n - 1)
                        return 0LL;
                    if (memo[now][ind] != -1)
                        return memo[now][ind];
                    memo[now][ind] = min(1LL * a[now][ind] * a[now + 1][0] + self(now + 1, 1),
                                         1LL * a[now][ind] * a[now + 1][1] + self(now + 1, 0));
                    return memo[now][ind];
                })(0, 1)
         << endl;
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