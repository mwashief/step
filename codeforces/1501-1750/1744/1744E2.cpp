/*
    Washief Hossain Mugdho
    18 October 2022
    Codeforces 1501-1750 1744 1744E2
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

vi primes;

inline void __run_test()
{
    vvl a(2, vl(2));
    rep(i, 2) rep(j, 2) cin >> a[j][i];

    ll aa = a[0][0], bb = a[1][0];

    auto find = [&](ll num, int index) -> ll
    {
        ll ceil = (a[index][0] + num) / num;
        ll res = num * ceil;

        if (res <= a[index][1])
            return res;
        return -1;
    };

    mii factorization;

    for (auto prime : primes)
        if (aa >= prime)
            while (aa % prime == 0)
            {
                aa /= prime;
                factorization[prime]++;
            }
        else
            break;
    if (aa > 1)
        factorization[(int)aa]++;

    for (auto prime : primes)
        if (bb >= prime)
            while (bb % prime == 0)
            {
                bb /= prime;
                factorization[prime]++;
            }
        else
            break;
    if (bb > 1)
        factorization[(int)bb]++;

    vpii all;
    for (auto p : factorization)
        all.pb(p);

    vl factors;

    y_combinator(
        [&](auto self, int index, ll num) -> void
        {
            if (index == gsz(all))
            {
                factors.pb(num);
                return;
            }
            ll now = 1LL;
            rep(i, all[index].sc + 1)
            {
                self(index + 1, num * now);
                now *= all[index].fr;
            }
        })(0, 1LL);

    for (auto factor : factors)
    {
        ll x = find(factor, 0);
        ll y = find(a[0][0] * a[1][0] / factor, 1);

        if (x != -1LL && y != -1LL)
        {
            cout << x << " " << y << endl;
            return;
        }
    }

    cout << "-1 -1" << endl;
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
    primes.pb(2);
    vb bookKeeping(31630);
    for (int i = 3; i < 31630; i += 2)
    {
        if (bookKeeping[i])
            continue;
        primes.pb(i);
        for (int j = i * i; j < 31630; j += (i << 1))
            bookKeeping[j] = 1;
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