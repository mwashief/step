/*
    Washief Hossain Mugdho
    16 August 2021
    Codeforces 1501-1750 1543 1543D2
*/

#ifndef __DEBUG__
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")
#endif

#define __INTERACTIVE__

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

int n, k, digits;

auto getKits(int x)
{
    vi ans;
    while (x)
    {
        ans.pb(x % k);
        x /= k;
    }
    while (gsz(ans) < digits)
        ans.pb(0);
    return ans;
}

auto kitsToNumber(const vi &a)
{
    int res = 0;
    int t = 1;
    rep(i, digits)
    {
        res += a[i] * t;
        t *= k;
    }
    return res;
}

auto sub(vi &a, vi &b)
{
    vi ans;
    rep(i, digits) ans.pb((b[i] - a[i] + k) % k);

    return ans;
}

auto add(vi &a, vi &b)
{
    vi ans;
    rep(i, digits) ans.pb((a[i] + b[i]) % k);
    return ans;
}

auto go(int guess)
{
    cout << guess << endl;
    int g;
    cin >> g;
    return g;
}

inline void __run_test()
{
    cin >> n >> k;
    digits = 0;
    int t = 1;
    while (t < n)
    {
        digits++;
        t *= k;
    }

    vi taken(digits);
    rep(i, n)
    {
        int guess;
        auto kits = getKits(i);
        if (i & 1)
            guess = kitsToNumber(sub(kits, taken));
        else
            guess = kitsToNumber(add(kits, taken));
        if (go(guess))
            return;
        auto guessKits = getKits(guess);
        taken = sub(taken, guessKits);
    }
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