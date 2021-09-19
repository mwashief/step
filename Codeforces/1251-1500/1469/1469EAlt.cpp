/*
    Washief Hossain Mugdho
    19 September 2021
    Codeforces 1251-1500 1469 1469EAlt
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
    string s;
    cin >> s;
    int logn = ceil(log2(n + 1));
    int candidates = n - k + 1;
    vi temp;
    string prefix;
    if (k <= logn)
        rep(i, candidates) temp.pb(i);
    else
    {
        int take = k - logn;
        int zeros = 0;
        rep(i, take)
        {
            if (s[i] == '0')
                zeros++;
            prefix += '0';
        }
        rep(i, candidates)
        {
            if (!zeros)
                temp.pb(i);
            if (s[i] == '0')
                zeros--;
            if (s[i + take] == '0')
                zeros++;
        }
    }

    auto res = y_combinator([&](auto self, int bit, vi &a) -> pair<bool, string>
                            {
                                if (bit >= k)
                                    return {!gsz(a), ""};
                                vi b;
                                int i = 0;
                                for (auto d : a)
                                {
                                    bool tt = s[d + bit] - '0';
                                    if (tt)
                                        b.pb(d);
                                    else
                                        a[i++] = d;
                                }
                                i = gsz(a) - i;
                                rep(j, i) a.pop_back();
                                auto blacks = self(bit + 1, b);
                                if (blacks.fr)
                                    return {true, "0" + blacks.sc};
                                auto whites = self(bit + 1, a);
                                if (whites.fr)
                                    return {true, "1" + whites.sc};
                                return {false, ""};
                            })(max(0, k - logn), temp);
    if (res.fr)
    {
        pyes << endl;
        cout << prefix + res.sc << endl;
    }
    else
        pno << endl;
}

int main()
{
    fastio;
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
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