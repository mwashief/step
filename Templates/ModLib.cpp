/*
    Washief Hossain Mugdho
    22 April 2021
    Algorithm ModLib
*/

#ifndef DEBUG
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")
#endif

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define pyes cout << "YES"
#define pno cout << "NO"
#define fastio ios_base::sync_with_stdio(0)
#define untie cin.tie(0)
#define rep(i, n) for (int i = 0; i < (n); (i)++)
#define repe(i, n) for (int i = 1; i <= (n); (i)++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; (i)--)
#define rrepe(i, n) for (int i = (n); i > 0; (i)--)
#define ms(a, b) memset(a, b, sizeof a)
#define a2z(x) (x).begin(), (x).end()
#define z2a(x) (x).rbegin(), (x).rend()
#define endl "\n"
#define gsz(v) ((int)(v).size())
#define MOD 1000000007
#define MAX 1000005

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<ll>;
using vvb = vector<vector<bool>>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vpii = vector<pair<int, int>>;
using mii = map<int, int>;
using umii = unordered_map<int, int>;
using seti = set<int>;
using useti = unordered_set<int>;

/***********IO Utility**************/
template <typename... ArgTypes>
void print(ArgTypes... args);
template <typename... ArgTypes>
void input(ArgTypes &...args);
template <>
void print() {}
template <>
void input() {}
template <typename T, typename... ArgTypes>
void print(T t, ArgTypes... args)
{
    cout << t;
    print(args...);
}
template <typename T, typename... ArgTypes>
void input(T &t, ArgTypes &...args)
{
    cin >> t;
    input(args...);
}

template <int m>
struct mod
{
    long long x;
    mod() : x(0) {}
    mod(long long xx) : x(xx)
    {
        if (abs(x) >= m)
            x %= m;
        if (x < 0)
            x += m;
    }
    mod operator+(const mod &a) const
    {
        mod n;
        n.x = x + a.x;
        if (n.x >= m)
            n.x -= m;
        return n;
    }
    mod operator-(const mod &a) const
    {
        mod n;
        n.x = x - a.x;
        if (n.x < 0)
            n.x += m;
        return n;
    }
    mod operator*(const mod &a) const
    {
        return x * a.x;
    }
    mod operator+=(const mod &a)
    {
        x += a.x;
        if (x >= m)
            x -= m;
        return *this;
    }
    mod operator-=(const mod &a)
    {
        x -= a.x;
        if (x < 0)
            x += m;
        return *this;
    }
    mod operator*=(const mod &a)
    {
        x = (x * a.x) % m;
        return *this;
    }
    mod pow(long long b) const
    {
        mod ans = 1;
        mod a = *this;
        while (b > 0)
        {
            if (b & 1)
                ans *= a;
            a *= a;
            b /= 2;
        }
        return ans;
    }
    mod inv() const
    {
        return pow(m - 2);
    }
    mod operator/(const mod &a) const
    {
        return (*this) * a.inv();
    }
    mod operator/=(const mod &a)
    {
        return (*this) *= a.inv();
    }
    bool operator==(const mod &o) const
    {
        return x == o.x;
    }
    bool operator!=(const mod &o) const
    {
        return x != o.x;
    }
    long long operator()() const
    {
        return x;
    }
};

using base = mod<MOD>;

int main()
{
    fastio;
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
}