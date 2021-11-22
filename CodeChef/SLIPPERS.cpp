/*
    Washief Hossain Mugdho
    21 November 2021
    CodeChef SLIPPERS
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

template <class T, class OP>
class SegmentTree
{
    vector<T> t;
    void build()
    {
        for (int i = n - 1; i > 0; --i)
            t[i] = OP()(t[i << 1], t[i << 1 | 1]);
    }

public:
    int n;

    SegmentTree(int nn)
    {
        n = nn;
        t = vector<T>(n << 1);
    }

    SegmentTree(vector<T> v)
    {
        n = v.size();
        t = vector<T>(n << 1);
        for (int i = 0; i < n; ++i)
            t[i + n] = v[i];
        build();
    }

    void update(int p, T value)
    {
        for (t[p += n] = value; p > 1; p >>= 1)
            t[p >> 1] = OP()(t[p], t[p ^ 1]);
    }

    void inc(int p)
    {
        t[p += n]++;
        for (; p > 1; p >>= 1)
            t[p >> 1] = OP()(t[p], t[p ^ 1]);
    }

    T query(int l, int r)
    {
        r++;
        T res = T(0);
        for (l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                res = OP()(res, t[l++]);
            if (r & 1)
                res = OP()(res, t[--r]);
        }
        return res;
    }
};

template <class T>
class Add
{
public:
      T operator()(T x, T y)
    {
        return x + y;
    }
};

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
    SegmentTree<base, Add<base>> st(200001);
    st.update(0, 1);
    base res = 1;
    rep(i, n)
    {
        int x;
        cin >> x;
        auto d = st.query(0, x - 1);
        res += d;
        st.update(x, st.query(x, x) + d);
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
*/