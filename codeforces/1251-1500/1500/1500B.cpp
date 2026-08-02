/*
    Washief Hossain Mugdho
    15 March 2021
    1500B
*/

#ifndef DEBUG
#pragma GCC optimize("O2")
#endif

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define fastio ios_base::sync_with_stdio(0)
#define untie cin.tie(0)
#define rep(i, n) for (int i = 0; i < n; i++)
#define repe(i, n) for (int i = 1; i <= n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
#define rrepe(i, n) for (int i = n; i > 0; i--)
#define ms(a, b) memset(a, b, sizeof a)
#define MOD 1000000007

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

int main()
{
    fastio;
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    ll n, m, k;
    cin >> n >> m >> k;
    ll gcd = (ll)__gcd(n, m);
    ll lcm = 1LL * n * m / gcd;
    ll total = 0LL;
    vl b(m), shift(n), pos(2 * max(n, m) + 1, -1LL);
    rep(i, n)
    {
        int x;
        cin >> x;
        pos[x] = i;
    }
    rep(i, m)
    {
        cin >> b[i];
        ll sh = pos[b[i]];
        if (sh == -1LL)
            continue;

        sh = 1LL * (sh - i + lcm) % n;
        if (sh % gcd)
            continue;
        shift[sh]++;
        total++;
    }
    total = lcm - total;
    ll res = k / total;
    if (k % total == 0LL)
        res--;
    k -= res * total;
    res *= lcm;
    ll sh = 0;
    while (k)
    {
        ll conflict = m - shift[sh];
        if (conflict < k)
        {
            res += m;
            sh = (sh + m) % n;
            k -= conflict;
            continue;
        }
        for (ll i = 0; k; i++)
        {
            if (pos[b[i % m]] != (sh + i) % n)
                k--;
            res++;
        }
    }
    cout << res << endl;
}
