/*
    Washief Hossain Mugdho
    25 November 2022
    Codeforces 1501-1750 1750 1750D
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
#define MOD 998244353
#define MAXN 31630

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

template <int mod>
struct Mod
{
    long long x;
    Mod() : x(0) {}
    Mod(long long xx) : x(xx)
    {
        if (abs(x) >= mod)
            x %= mod;
        if (x < 0)
            x += mod;
    }
    operator int() const { return x; }
    operator long long() const { return x; }
    Mod operator+(const Mod &a) const
    {
        Mod n;
        n.x = x + a.x;
        if (n.x >= mod)
            n.x -= mod;
        return n;
    }
    Mod operator-(const Mod &a) const
    {
        Mod n;
        n.x = x - a.x;
        if (n.x < 0)
            n.x += mod;
        return n;
    }
    Mod operator*(const Mod &a) const
    {
        return x * a.x;
    }
    Mod operator+=(const Mod &a)
    {
        x += a.x;
        if (x >= mod)
            x -= mod;
        return *this;
    }
    Mod operator-=(const Mod &a)
    {
        x -= a.x;
        if (x < 0)
            x += mod;
        return *this;
    }
    Mod operator++()
    {
        *this += 1;
        return *this;
    }
    Mod operator++(int) // postfix
    {
        Mod temp = *this;
        *this += 1;
        return temp;
    }
    Mod operator--()
    {
        *this -= 1;
        return *this;
    }
    Mod operator--(int) // postfix
    {
        Mod temp = *this;
        *this -= 1;
        return temp;
    }
    Mod operator*=(const Mod &a)
    {
        x = (x * a.x) % mod;
        return *this;
    }
    Mod pow(long long b) const
    {
        Mod ans = 1;
        Mod a = *this;
        while (b > 0)
        {
            if (b & 1)
                ans *= a;
            a *= a;
            b /= 2;
        }
        return ans;
    }
    Mod inv() const
    {
        return pow(mod - 2);
    }
    Mod operator/(const Mod &a) const
    {
        return (*this) * a.inv();
    }
    Mod operator/=(const Mod &a)
    {
        return (*this) *= a.inv();
    }
    bool operator==(const Mod &o) const
    {
        return x == o.x;
    }
    bool operator!=(const Mod &o) const
    {
        return x != o.x;
    }
    long long operator()() const
    {
        return x;
    }
    template <int _mod>
    friend ostream &operator<<(ostream &os, const Mod<_mod> &num)
    {
        os << num.x;
        return os;
    }
    template <int _mod>
    friend istream &operator>>(istream &is, Mod<_mod> &num)
    {
        is >> num.x;
        if (abs(num.x) >= mod)
            num.x %= mod;
        if (num.x < 0)
            num.x += mod;
        return is;
    }
};
using base = Mod<MOD>;
using vbase = vector<base>;
using vvbase = vector<vector<base>>;
base two = 2;

std::vector<int> primes;

int miu(int num)
{
    int res = 1;
    for (int i = 0; i < gsz(primes) && num > 1; i++)
    {
        int cnt = 0;
        while (num % primes[i] == 0)
        {
            cnt++;
            num /= primes[i];
        }
        if (cnt > 1)
            return 0;
        if (cnt == 1)
            res = -res;
    }
    if (num > 1)
        res = -res;
    return res;
}

inline void __run_test()
{
    int n, m;
    cin >> n >> m;

    vi a(n);
    rep(i, n) cin >> a[i];

    base res = 1;
    repe(i, n - 1)
    {
        if (a[i - 1] % a[i])
        {
            cout << 0 << endl;
            return;
        }
        int nn = m / a[i];
        int v = a[i - 1] / a[i];

        base ways = 0;
        for (int d = 1; d * d > 0 && d * d <= v; d++)
            if (v % d == 0)
            {
                int other = v / d;
                if (d <= nn)
                    ways += base(miu(d)) * base(nn / d);
                if (other != d && other <= nn)
                    ways += base(miu(other)) * base(nn / other);
            }

        res *= ways;
    }

    cout << res << endl;
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
#endif
    bool is_composite[MAXN];

    std::fill(is_composite, is_composite + MAXN, false);
    for (int i = 2; i < MAXN; ++i)
    {
        if (!is_composite[i])
            primes.push_back(i);
        for (int j = 0; j < gsz(primes) && i * primes[j] < MAXN; ++j)
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