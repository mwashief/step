/*
    Washief Hossain Mugdho
    08 October 2021
    Codeforces 1501-1750 1594 1594E2
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
    int m;
    cin >> m;

    vl memo(m + 2, -1);
    memo[0] = base(4).inv();
    memo[1] = 1;
    y_combinator([&](auto self, int d) -> base
                 {
                     if (memo[d] != -1)
                         return base(memo[d]);
                     base res = base(16) * self(d - 1) * self(d - 1);
                     memo[d] = res.x;
                     return res;
                 })(m);
    reverse(a2z(memo));
    map<string, int> mm;
    mm["white"] = 0;
    mm["yellow"] = 5;
    mm["green"] = 1;
    mm["blue"] = 4;
    mm["red"] = 2;
    mm["orange"] = 3;

    int n;
    cin >> n;
    vl fixed;
    map<ll, int> check;

    rep(i, n)
    {
        ll x;
        string s;
        cin >> x >> s;

        fixed.pb(x);
        check[x] = mm[s];
    }

    sort(a2z(fixed));
    map<ll, vbase, greater<ll>> weird;
    rrepe(i, m)
    {
        ll start = 1LL << (i - 1);

        while (gsz(fixed) && fixed.back() >= start)
        {
            auto now = fixed.back();
            fixed.pop_back();
            vbase val(6);
            int col = check[now];
            base lhs = 0;
            base rhs = 0;

            if (weird.find(now << 1) != weird.end())
            {
                rep(j, 6) if (j != col && j != 5 - col)
                    lhs += weird[now << 1][j];
                weird.erase(now << 1);
            }
            else
                lhs += base(4) * base(memo[i + 1]);
            if (weird.find((now << 1) + 1) != weird.end())
            {
                rep(j, 6) if (j != col && j != 5 - col)
                    rhs += weird[(now << 1) + 1][j];
                weird.erase((now << 1) + 1);
            }
            else
                rhs += base(4) * base(memo[i + 1]);
            val[col] = lhs * rhs;
            weird[now] = val;
        }
        vector<pair<ll, vbase>> temp;
        while (gsz(weird) && weird.begin()->fr >= (1LL << i))
        {
            temp.pb(*weird.begin());
            weird.erase(weird.begin());
        }
        while (gsz(temp))
        {
            auto k = temp.back();
            temp.pop_back();

            if ((k.fr & 1LL) == 0LL)
            {
                if (gsz(temp) && temp.back().fr == k.fr + 1)
                {
                    auto kk = temp.back();
                    vbase res(6);
                    rep(j, 6)
                    {
                        base lhs = 0;
                        base rhs = 0;
                        rep(p, 6) if (p != j && p != 5 - j) rhs += k.sc[p];
                        rep(p, 6) if (p != j && p != 5 - j) lhs += kk.sc[p];
                        res[j] = rhs * lhs;
                    }

                    weird[k.fr >> 1] = res;
                    temp.pop_back();
                }
                else
                {
                    vbase res(6);
                    rep(j, 6)
                    {
                        base lhs = base(4) * base(memo[i + 1]);
                        base rhs = 0;
                        rep(p, 6) if (p != j && p != 5 - j) rhs += k.sc[p];
                        res[j] = rhs * lhs;
                    }
                    weird[k.fr >> 1] = res;
                }
            }
            else
            {
                vbase res(6);
                rep(j, 6)
                {
                    base lhs = base(4) * base(memo[i + 1]);
                    base rhs = 0;
                    rep(p, 6) if (p != j && p != 5 - j) rhs += k.sc[p];
                    res[j] = rhs * lhs;
                }
                weird[k.fr >> 1] = res;
            }
        }
    }
    assert(gsz(weird) == 1);
    base ans = 0;
    rep(i, 6) ans += weird.begin()->sc[i];
    cout << ans << endl;
}

/*
-> Check for data types
-> Fix macro
-> Run test case
*/