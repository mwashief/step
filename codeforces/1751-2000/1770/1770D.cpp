/*
    12 January 2023
    Codeforces 1751-2000 1770 1770D
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
    int n;
    cin >> n;
    vi a(n), b(n);
    vb visited(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    map<pii, int> track;
    rep(i, n)
    {
        a[i]--;
        b[i]--;
        if (a[i] > b[i])
            swap(a[i], b[i]);
        track[{a[i], b[i]}]++;
        visited[a[i]] = true;
        visited[b[i]] = true;
    }

    visited.assign(n, false);
    base res = 1;

    vpii processed;

    for (auto [p, z] : track)
    {
        if (z > 2)
        {
            cout << 0 << endl;
            return;
        }
        processed.pb(p);
        auto [x, y] = p;
        if (x == y)
        {
            if (z > 1)
            {
                cout << 0 << endl;
                return;
            }
            if (visited[x])
            {
                cout << 0 << endl;
                return;
            }
            visited[x] = true;
            res *= base(n);
        }
        else if (z == 2)
        {
            if (visited[x] || visited[y])
            {
                cout << 0 << endl;
                return;
            }
            visited[x] = true;
            visited[y] = true;
            res *= two;
        }
        else
            processed.pop_back();
    }

    for (auto p : processed)
        track.erase(p);

    vvi adj(n);
    for (auto [p, z] : track)
    {
        auto [x, y] = p;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    vi starts;
    rep(i, n) if (visited[i]) starts.pb(i);

    for (auto node : starts)
        y_combinator(
            [&](auto self, int now, int parent) -> void
            {
                for (auto nei : adj[now])
                    if (nei != parent)
                    {
                        if (visited[nei])
                            res = 0;
                        else
                        {
                            visited[nei] = true;
                            self(nei, now);
                        }
                    }
            })(node, -1);

    rep(i, n) if (!visited[i])
    {
        visited[i] = true;
        int cnt = 1;
        int edges = 0;

        y_combinator(
            [&](auto self, int node) -> void
            {
                for (auto nei : adj[node])
                {
                    edges++;
                    if (!visited[nei])
                    {
                        visited[nei] = true;
                        cnt++;
                        self(nei);
                    }
                }
            })(i);
        edges >>= 1;
        if (edges == cnt)
            res *= two;
        else
            res = 0;
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