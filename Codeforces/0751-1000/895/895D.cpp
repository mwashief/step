/*
    Washief Hossain Mugdho
    18 January 2022
    Codeforces 0751-1000 895 895D
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
    string s, t;
    cin >> s >> t;
    reverse(a2z(s));
    reverse(a2z(t));
    while (gsz(s) && s.back() == t.back())
    {
        s.pop_back();
        t.pop_back();
    }
    if (gsz(s) == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    int n = gsz(s);
    reverse(a2z(s));
    reverse(a2z(t));
    vbase fact(n + 1);
    vbase inv(n + 1);
    fact[0] = 1;
    repe(i, n) fact[i] = fact[i - 1] * base(i);
    repe(i, n) inv[i] = base(1) / base(i);

    vi cnt(26);
    for (auto c : s)
        cnt[c - 'a']++;

    base res = 0;
    if (cnt[t[0] - 'a'])
    {
        cnt[t[0] - 'a']--;
        repe(i, gsz(t))
        {
            base temp = 1;
            for (int j = 0; j < 26; j++)
                temp *= fact[cnt[j]];
            for (char c = 'a'; c < t[i]; c++)
                if (cnt[c - 'a'])
                {
                    base temp2 = temp * inv[cnt[c - 'a']];
                    res += fact[n - i - 1] / temp2;
                }
            if (cnt[t[i] - 'a'])
                cnt[t[i] - 'a']--;
            else
                break;
        }
    }
    cnt = vi(26);
    for (auto c : s)
        cnt[c - 'a']++;

    for (char c = s[0] + 1; c < t[0]; c++)
        if (cnt[c - 'a'])
        {
            base now = fact[n - 1];
            for (int j = 0; j < 26; j++)
                now /= fact[cnt[j] - ((j == c - 'a') ? 1 : 0)];
            res += now;
        }
    cnt[s[0] - 'a']--;
    repe(i, n - 1)
    {
        base temp = 1;
        for (int j = 0; j < 26; j++)
            temp *= fact[cnt[j]];
        for (char c = s[i] + 1; c <= 'z'; c++)
            if (cnt[c - 'a'])
            {
                base temp2 = temp * inv[cnt[c - 'a']];
                res += fact[n - i - 1] / temp2;
            }
        cnt[s[i] - 'a']--;
    }
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