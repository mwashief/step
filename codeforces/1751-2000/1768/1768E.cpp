/*
    05 January 2023
    Codeforces 1751-2000 1768 1768E
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

ll MOD;

struct Mod
{
    long long x;
    Mod() : x(0) {}
    Mod(long long xx) : x(xx)
    {
        if (abs(x) >= MOD)
            x %= MOD;
        if (x < 0)
            x += MOD;
    }
    operator int() const { return (int)x; }
    operator long long() const { return x; }
    Mod operator+(const Mod &a) const
    {
        Mod n;
        n.x = x + a.x;
        if (n.x >= MOD)
            n.x -= MOD;
        return n;
    }
    Mod operator-(const Mod &a) const
    {
        Mod n;
        n.x = x - a.x;
        if (n.x < 0)
            n.x += MOD;
        return n;
    }
    Mod operator*(const Mod &a) const
    {
        return x * a.x;
    }
    Mod operator+=(const Mod &a)
    {
        x += a.x;
        if (x >= MOD)
            x -= MOD;
        return *this;
    }
    Mod operator-=(const Mod &a)
    {
        x -= a.x;
        if (x < 0)
            x += MOD;
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
        x = (x * a.x) % MOD;
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
        return pow(MOD - 2);
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
};
using base = Mod;
using vbase = vector<base>;
using vvbase = vector<vector<base>>;
int main()
{
    fastio;
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    int n;
    cin >> n >> MOD;
    vbase fact(3 * n + 1);
    vbase invFact(3 * n + 1);
    fact[0] = base(1);
    repe(i, 3 * n) fact[i] = fact[i - 1] * base(i);
    invFact[3 * n] = base(1) / fact[3 * n];
    rrep(i, 3 * n) invFact[i] = base(i + 1) * invFact[i + 1];

    auto comb = [&](int x, int y) -> base
    {
        if (x < y || y < 0)
            return base(0);
        return fact[x] * invFact[y] * invFact[x - y];
    };

    base c0 = base(1);
    base c1 = fact[2 * n] * base(2) - fact[n] - base(1);
    base c2 = base(2) * comb(2 * n, n) * fact[n] * fact[2 * n];

    rep(i, n + 1)
        c2 -= comb(n, i) *
              comb(2 * n - i, n) *
              comb(n, n - i) *
              fact[n] * fact[n] * fact[n];
    c2 -= c1 + c0;

    base c3 = fact[3 * n] - c0 - c1 - c2;

    cout << (c1 + c2 * base(2) + c3 * base(3)).x << endl;
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