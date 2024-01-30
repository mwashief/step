/*
    30 January 2024
    Codeforces 1751-2000 1920 1920D
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

int binaryDigits(ll k)
{
    int res = 0;
    while (k)
    {
        res++;
        k >>= 1;
    }

    return res;
}

inline void __run_test()
{
    int n, q;
    cin >> n >> q;
    vl prefixSum(n + 1);
    vi type(n + 1), val(n + 1);

    repe(i, n)
    {
        cin >> type[i] >> val[i];

        if (prefixSum[i - 1] == INT64_MAX)
        {
            prefixSum[i] = INT64_MAX;
            continue;
        }
        if (type[i] == 1)
            prefixSum[i] = prefixSum[i - 1] + 1;
        else
        {
            int d1 = binaryDigits(prefixSum[i - 1]);
            int d2 = binaryDigits(val[i] + 1);
            if (d1 + d2 <= 62)
                prefixSum[i] = prefixSum[i - 1] * ((ll)(val[i] + 1));
            else
                prefixSum[i] = INT64_MAX;
        }
    }

    while (gsz(prefixSum) >= 2 && prefixSum.back() == INT64_MAX && prefixSum[gsz(prefixSum) - 2] == INT64_MAX)
        prefixSum.pop_back();

    auto search = y_combinator(
        [&](auto self, ll k) -> int
        {
            auto it = lower_bound(a2z(prefixSum), k);
            int index = it - prefixSum.begin();
            if (type[index] == 1)
                return val[index];
            ll chunk = prefixSum[index - 1];
            k %= chunk;
            if (k == 0)
                k = chunk;
            return self(k);
        });

    while (q--)
    {
        ll k;
        cin >> k;
        cout << search(k) << " ";
    }
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