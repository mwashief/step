/*
    Washief Hossain Mugdho
    22 March 2021
    Codeforces 1491 1491C
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

inline void _()
{
    int n;
    cin >> n;
    ll res = 0;
    vi s(n);
    rep(i, n) cin >> s[i];
    vl already(n);
    rep(i, n - 1)
    {
        ll toReduce = s[i];
        ll a = already[i];
        ll rest = n - 1LL - i;
        ll freeJumps = max(0LL, toReduce - rest);

        ll d = min(freeJumps, a);
        a -= d;
        toReduce -= freeJumps + 1;
        freeJumps -= d;
        res += freeJumps;
        res += max(0LL, toReduce - a);
        s[i] = 1;

        repe(j, toReduce) already[i + j + 1]++;

        d = min(toReduce, a);
        a -= d;
        already[i + 1] += a;
    }
    res += max(0LL, 0LL + s[n - 1] - 1LL - already[n - 1]);
    cout << res << endl;
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

    int __;
    cin >> __;
    while (__--)
        _();
}
