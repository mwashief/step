/*
    Washief Hossain Mugdho
    07 March 2021
    1389 1389D
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
    ll x1, y1, x2, y2, n, k;
    cin >> n >> k >> x1 >> y1 >> x2 >> y2;
    if (x1 > x2)
    {
        swap(x1, x2);
        swap(y1, y2);
    }
    if (x2 > y1)
    {
        ll gap = x2 - y1;
        ll per = max(y1, y2) - min(x1, x2);
        if (gap >= per)
        {
            ll taken = min(per, k);
            k -= taken;
            cout << gap + taken + 2LL * k << endl;
            return;
        }
        ll full = min(n, k / per);
        if (full)
        {
            ll extra = k - full * per;
            if (full == n)
                cout << full * (per + gap) + 2LL * extra << endl;
            else
                cout << full * (per + gap) + min(2LL * extra, gap + extra) << endl;
            return;
        }
        cout << gap + k << endl;
    }
    else
    {
        ll common = min(y1, y2) - max(x1, x2);
        k -= common * n;
        if (k <= 0)
        {
            cout << "0" << endl;
            return;
        }
        ll per = max(y1, y2) - min(x1, x2) - common;
        ll full = n;
        if (per)
            full = min(full, k / per);
        k -= full * per;
        if (full == n)
            cout << full * per + k * 2LL << endl;
        else
            cout << full * per + k << endl;
    }
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
