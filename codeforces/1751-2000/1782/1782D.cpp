/*
    20 January 2023
    Codeforces 1751-2000 1782 1782D
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
#define MAX 32000

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

bool is_composite[MAX];
vi primes;

vpii getFactors(int num)
{
    vpii factors;
    for (auto prime : primes)
    {
        int cnt = 0;
        while (num % prime == 0)
        {
            cnt++;
            num /= prime;
        }
        if (cnt)
            factors.pb({prime, cnt});
    }

    if (num != 1)
        factors.pb({num, 1});

    return factors;
}

inline void __run_test()
{
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    map<ll, seti> track;
    rep(i, n) for (int j = i + 1; j < n; j++)
    {
        int x = a[i];
        int y = a[j];
        if (x < y)
            swap(x, y);
        int num = x - y;
        auto factors = getFactors(num);

        y_combinator(
            [&](auto self, int index, int now) -> void
            {
                if (index == gsz(factors))
                {
                    int f1 = now;
                    int f2 = num / now;
                    if (f1 < f2)
                        swap(f1, f2);
                    int p = (f1 + f2);
                    int q = (f1 - f2);
                    ll k = 1LL * q * q / 4LL - y;
                    if ((p & 1) || (q & 1) || k < 0LL)
                        return;
                    track[k].insert(i);
                    track[k].insert(j);
                    return;
                }
                rep(m, factors[index].sc + 1)
                {
                    self(index + 1, now);
                    now *= factors[index].fr;
                }
            })(0, 1);
    }

    int res = 1;
    for (auto &[_, eligible] : track)
        res = max(res, gsz(eligible));

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

    for (int i = 2; i < MAX; ++i)
    {
        if (!is_composite[i])
            primes.push_back(i);
        for (int j = 0; j < gsz(primes) && 1LL * i * primes[j] < (ll)MAX; ++j)
        {
            is_composite[i * primes[j]] = true;
            if (i % primes[j] == 0)
                break;
        }
    }

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