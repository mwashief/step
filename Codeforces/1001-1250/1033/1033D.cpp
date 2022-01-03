/*
    Washief Hossain Mugdho
    03 January 2022
    Codeforces 1001-1250 1033 1033D
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
#define MOD 998244353
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
    Mod operator++(int) //postfix
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
    Mod operator--(int) //postfix
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
    int n;
    cin >> n;
    map<ull, int> cnt;
    map<ull, int> twoPrimes;
    rep(i, n)
    {
        ull x;
        cin >> x;
        ull l = 1, r = 37606;
        while (l < r)
        {
            ull mid = (l + r) >> 1;
            if (mid * mid * mid * mid < x)
                l = mid + 1;
            else
                r = mid;
        }
        if (l * l * l * l == x)
        {
            cnt[l] += 4;
            continue;
        }
        l = 1, r = 1414213562;
        while (l < r)
        {
            ull mid = (l + r) >> 1;
            if (mid * mid < x)
                l = mid + 1;
            else
                r = mid;
        }
        if (l * l == x)
        {
            cnt[l] += 2;
            continue;
        }
        l = 1, r = 1259921;
        while (l < r)
        {
            ull mid = (l + r) >> 1;
            if (mid * mid * mid < x)
                l = mid + 1;
            else
                r = mid;
        }
        if (l * l * l == x)
        {
            cnt[l] += 3;
            continue;
        }
        bool done = false;
        for (auto p : cnt)
            if (x % p.fr == 0)
            {
                done = true;
                cnt[p.fr]++;
                cnt[x / p.fr]++;
                break;
            }
        if (done)
            continue;
        for (auto p : twoPrimes)
        {
            auto g = __gcd(x, p.fr);
            if (g != ull(1) && g != x)
            {
                done = true;
                cnt[g] += p.sc + 1;
                cnt[p.fr / g] += p.sc;
                cnt[x / g]++;
                twoPrimes.erase(p.fr);
                break;
            }
        }
        if (done)
            continue;

        twoPrimes[x]++;
    }
    for (auto p : twoPrimes)
        for (auto d : cnt)
            if (p.fr % d.fr == 0)
            {
                cnt[d.fr] += p.sc;
                cnt[p.fr / d.fr] += p.sc;
                twoPrimes[p.fr] = 0;
                break;
            }

    base res = base(1);
    for (auto d : cnt)
        res *= base(d.sc + 1);
    for (auto d : twoPrimes)
        res *= base(d.sc + 1) * base(d.sc + 1);
    cout << res << endl;
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