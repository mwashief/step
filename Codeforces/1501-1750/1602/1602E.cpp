/*
    Washief Hossain Mugdho
    01 November 2021
    Codeforces 1501-1750 1602 1602E
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
    int n, m;
    cin >> n >> m;
    vi a(n), b(m);
    vpii position;
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];
    a.pb(INT32_MAX);
    sort(a2z(b));
    y_combinator([&](auto self, int al, int ar, int bl, int br) -> void
                 {
                     if (bl > br)
                         return;
                     int mid = (bl + br) >> 1;
                     vi prefix(ar - al + 1), suffix(ar - al + 1);
                     for (int i = ar; i >= al; i--)
                     {
                         if (a[i] < b[mid])
                             suffix[i - al] = 1;
                         if (i != ar)
                             suffix[i - al] += suffix[i - al + 1];
                     }

                     for (int i = al + 1; i <= ar; i++)
                     {
                         if (a[i - 1] > b[mid])
                             prefix[i - al] = 1;
                         prefix[i - al] += prefix[i - al - 1];
                     }
                     int pos = -1;
                     int cost = INT32_MAX;
                     for (int i = al; i <= ar; i++)
                     {
                         int c = prefix[i - al] + suffix[i - al];
                         if (c < cost)
                         {
                             cost = c;
                             pos = i;
                         }
                     }
                     position.pb({pos, b[mid]});
                     self(al, pos, bl, mid - 1);
                     self(pos, ar, mid + 1, br);
                 })(0, n, 0, m - 1);
    sort(a2z(position), [](pii x, pii y)
         {
             if (x.fr == y.fr)
                 return x.sc < y.sc;
             return x.fr < y.fr;
         });
    reverse(a2z(position));

    vi final;
    rep(i, n + 1)
    {
        while (gsz(position) && position.back().fr == i)
        {
            final.pb(position.back().sc);
            position.pop_back();
        }
        final.pb(a[i]);
    }
    vi temp;
    temp.reserve(n + m);
    cout << y_combinator([&](auto self, int l, int r) -> ll
                         {
                             if (l >= r)
                                 return 0LL;
                             int mid = (l + r) >> 1;
                             ll cost = self(l, mid) + self(mid + 1, r);
                             int i = l, j = mid + 1;
                             temp.clear();
                             while (gsz(temp) < r - l + 1)
                             {
                                 if (j > r || (i <= mid && final[i] <= final[j]))
                                 {
                                     temp.pb(final[i]);
                                     i++;
                                 }
                                 else if (i > mid || final[j] < final[i])
                                 {
                                     temp.pb(final[j]);
                                     j++;
                                     cost += mid + 1 - i;
                                 }
                             }
                             rep(i, r - l + 1) final[l + i] = temp[i];
                             return cost;
                         })(0, n + m - 1)
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
*/