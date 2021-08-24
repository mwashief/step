/*
    Washief Hossain Mugdho
    13 August 2021
    Codeforces 1501-1750 1551 1551F
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

inline void __run_test()
{
    int n, k;
    cin >> n >> k;

    vvi adj(n);
    rep(i, n - 1)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    if (k == 2)
    {
        cout << base(n) * base(n - 1) / two << endl;
        return;
    }

    vvi upMemo(n, vi(n + 1)), downMemo(n, vi(n + 1));
    vector<vvi> blocks(n, vvi(n + 1));

    y_combinator([&](auto self, int node, int parent) -> void
                 {
                     downMemo[node][0] = 1;
                     for (auto child : adj[node])
                         if (child != parent)
                         {
                             self(child, node);
                             rep(i, n)
                             {
                                 downMemo[node][i + 1] += downMemo[child][i];
                                 blocks[node][i + 1].pb(downMemo[child][i]);
                             }
                         }
                 })(0, -1);

    y_combinator([&](auto self, int node, int parent) -> void
                 {
                     upMemo[node][0] = 1;
                     vi children;
                     for (auto child : adj[node])
                         if (child != parent)
                             children.pb(child);

                     vvi prefix(children.size() + 1, vi(n + 1)), suffix(children.size() + 1, vi(n + 1));
                     rep(i, gsz(children)) rep(j, n + 1)
                     {
                         prefix[i + 1][j] += downMemo[children[i]][j];
                         suffix[i][j] += downMemo[children[i]][j];
                     }
                     repe(i, gsz(children)) rep(j, n + 1) prefix[i][j] += prefix[i - 1][j];
                     rrep(i, gsz(children)) rep(j, n + 1) suffix[i][j] += suffix[i + 1][j];
                     rep(i, gsz(children)) rep(j, n - 1) upMemo[children[i]][j + 2] += prefix[i][j] + suffix[i + 1][j];
                     rep(i, gsz(children)) rep(j, n) upMemo[children[i]][j + 1] += upMemo[node][j];

                     rep(i, gsz(children)) self(children[i], node);
                 })(0, -1);

    base res = 0;
    rep(i, n) repe(j, n)
    {
        if (upMemo[i][j])
            blocks[i][j].pb(upMemo[i][j]);
        vvl memo(blocks[i][j].size(), vl(k + 1, -1));

        res += base(y_combinator([&](auto self, int index, int take) -> ll
                                 {
                                     if (take == 0)
                                         return 1;
                                     if (index == gsz(blocks[i][j]))
                                         return 0;

                                     if (memo[index][take] != -1)
                                         return memo[index][take];
                                     base ans = 0;
                                     ans = base(self(index + 1, take - 1)) * base(blocks[i][j][index]) + base(self(index + 1, take));
                                     return memo[index][take] = (ll)ans;
                                 })(0, k));
    }
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
    int __tests;
    cin >> __tests;
    while (__tests--)
        __run_test();
}