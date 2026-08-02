/*
    Washief Hossain Mugdho
    08 March 2022
    Codeforces 1501-1750 1650 1650F
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
#define MAX 10000000005LL

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

ll memo[100005][105];

void reset(int a)
{
    rep(i, a) rep(j, 105) memo[i][j] = -1;
}

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

    vl a(n);
    rep(i, n) cin >> a[i];
    vector<vector<tuple<ll, int, int>>> options(n);
    repe(i, m)
    {
        int e, t, p;
        cin >> e >> t >> p;
        e--;
        options[e].pb({t, p, i});
    }
    vl res;
    int now;
    vi ans;
    auto dp = y_combinator([&](auto self, int ind, int per) -> ll
                           {
                               if (ind >= gsz(options[now]))
                               {
                                   if (per > 0)
                                       return MAX;
                                   return 0LL;
                               }
                               if(per <= 0) return 0LL;
                               

                               if (memo[ind][per] != -1)
                                   return memo[ind][per];

                               // time, per, ind
                               auto x = get<0>(options[now][ind]) + self(ind + 1, per - get<1>(options[now][ind]));
                               auto y = self(ind + 1, per);

                               return memo[ind][per] = min(x, y); });

    auto go = y_combinator([&](auto self, int ind, int per) -> void
                           {
                               if (ind >= gsz(options[now]))
                                   return;
                                if(per < 0) return;

                               // time, per, ind
                               auto x = get<0>(options[now][ind]) + dp(ind + 1, per - get<1>(options[now][ind]));
                               auto y = dp(ind + 1, per);
                               if (x < y)
                               {
                                   ans.pb(get<2>(options[now][ind]));
                                   self(ind + 1, per - get<1>(options[now][ind]));
                               }
                               else
                                   self(ind + 1, per); });

    rep(i, n)
    {
        now = i;
        reset(gsz(options[i]) + 2);
        res.pb(dp(0, 100));
        go(0, 100);
    }

    repe(i, n - 1) res[i] += res[i - 1];
    rep(i, n) if (res[i] > a[i])
    {
        cout << -1 << endl;
        return;
    }
    cout << gsz(ans) << endl;
    for (auto op : ans)
        cout << op << " ";
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
-> Check simple logic errors
-> Read problem statements carefully
*/