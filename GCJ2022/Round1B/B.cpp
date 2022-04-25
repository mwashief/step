/*
    Washief Hossain Mugdho
    24 April 2022
    GCJ2022 Round1B B
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

    template <class T>
    T &unmove(T &&t) { return t; }

}

inline void __run_test(int &__test_case)
{
    cout << "Case #" << __test_case << ": ";
    int n, p;
    cin >> n >> p;
    vpii all(n, {INT32_MAX, INT32_MIN});
    rep(i, n) rep(j, p)
    {
        int x;
        cin >> x;
        all[i].fr = min(all[i].fr, x);
        all[i].sc = max(all[i].sc, x);
    }

    vvl memo(n, vl(2, -1));
    auto dp = y_combinator([&](auto self, int index, int sesh) -> ll
                           {
                               if (index >= n)
                                   return 0;
                               if (memo[index][sesh] != -1)
                                   return memo[index][sesh];
                               ll gap = all[index].sc - all[index].fr;
                               if(index == n-1)
                                   return memo[index][sesh] = gap;
                               
                               ll last = all[index].fr;
                               if (sesh)
                                   last = all[index].sc;

                               ll res = abs(last - all[index+1].fr) + self(index+1, 1);
                               res = min(res, abs(last - all[index+1].sc) + self(index+1, 0)); 
                               return memo[index][sesh] = gap + res; });
    cout << min(all[0].fr + dp(0, 1), all[0].sc + dp(0, 0)) << endl;
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
    for (int __test_case = 1; __test_case <= __tests; __test_case++)
        __run_test(__test_case);
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