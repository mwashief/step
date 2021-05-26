/*
    Washief Hossain Mugdho
    19 January 2021
    Codeforces 1474D
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
void println(ArgTypes... args);
template <typename... ArgTypes>
void print(ArgTypes... args);
template <typename... ArgTypes>
void input(ArgTypes &...args);
template <>
void println() { cout << endl; }
template <>
void print() {}
template <>
void input() {}
template <typename T, typename... ArgTypes>
void println(T t, ArgTypes... args)
{
    cout << t;
    println(args...);
}
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
int n;

bool check(vi a)
{
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i - 1] < 0)
            return 0;
        a[i] -= a[i - 1];
    }
    if (a.back() != 0)
        return 0;
    return 1;
}

inline void _()
{
    cin >> n;
    vi a(n + 1);
    repe(i, n) cin >> a[i];
    a.pb(0);
    if (check(a))
    {
        cout << "YES" << endl;
        return;
    }
    vi forward(n + 2);
    vi backward(n + 2);
    repe(i, n)
    {
        if (forward[i - 1] < 0)
            forward[i] = -1;
        else
            forward[i] = a[i] - forward[i - 1];
        if (backward[n + 2 - i] < 0)
            backward[n + 1 - i] = -1;
        else
            backward[n + 1 - i] = a[n + 1 - i] - backward[n + 2 - i];
    }
    for (int i = 1; i < n; i++)
    {
        if (forward[i - 1] < 0)
            break;
        if (backward[i + 2] < 0)
            continue;
        vi b;
        b.pb(0);
        b.pb(forward[i - 1]);
        b.pb(a[i + 1]);
        b.pb(a[i]);
        b.pb(backward[i + 2]);
        b.pb(0);
        if (check(b))
        {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
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
