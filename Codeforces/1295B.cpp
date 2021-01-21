/*
    Washief Hossain Mugdho
    21 January 2021
    Codeforces 1295B
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
    int n, x;
    cin >> n >> x;
    vi a(n);
    int prev = 0;
    int isPresent = 0;
    rep(i, n)
    {
        char c;
        cin >> c;
        if (c == '0')
            a[i] = prev + 1;
        else
            a[i] = prev - 1;
        if (a[i] == x)
            isPresent = 1;
        prev = a[i];
    }
    if (a[n - 1] == 0)
    {
        if (isPresent)
            cout << -1 << endl;
        else
            cout << 0 << endl;
        return;
    }
    ll res = 0;
    rep(i, n)
    {
        int y = x - a[i];
        if (abs(y) % abs(a[n - 1]) == 0)
        {
            int moves = y / a[n - 1];
            if (moves >= 0)
                res++;
        }
    }
    if (x == 0)
        res++;
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
