/*
    21 January 2023
    Codeforces 1751-2000 1777 1777C
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
#define MAX 320

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

void gen(vpii &factors, int index, int now, vi &f)
{
    if (index == gsz(factors))
    {
        f.pb(now);
        return;
    }
    rep(m, factors[index].sc + 1)
    {
        gen(factors, index + 1, now, f);
        now *= factors[index].fr;
    }
}

inline void __run_test()
{
    int n, m;
    cin >> n >> m;
    vi a(n);
    rep(i, n) cin >> a[i];
    sort(a2z(a));

    mii cnt;
    int distinct_count = 0;

    auto add = [&](int num) -> void
    {
        if (num > m)
            return;
        if (cnt[num] == 0)
            distinct_count++;
        cnt[num]++;
    };

    auto remove = [&](int num) -> void
    {
        if (num > m)
            return;
        if (cnt[num] == 1)
            distinct_count--;
        cnt[num]--;
    };

    int res = INT32_MAX;
    int j = 0;
    vi factors;
    rep(i, n)
    {
        while (j < n && distinct_count < m)
        {
            factors.clear();
            auto temp = getFactors(a[j]);
            gen(temp, 0, 1, factors);
            for (auto factor : factors)
                add(factor);
            j++;
        }
        if (distinct_count == m)
            res = min(res, a[j - 1] - a[i]);
        factors.clear();
        auto temp = getFactors(a[i]);
        gen(temp, 0, 1, factors);
        for (auto factor : factors)
            remove(factor);
    }

    if (res == INT32_MAX)
        res = -1;
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