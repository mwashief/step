/*
    Washief Hossain Mugdho
    28 December 2020
    Codeforces 666A
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
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vpii = vector<pair<int, int>>;
using mii = map<int, int>;

/***********IO Utility**************/
template <typename... ArgTypes>
void print(ArgTypes... args);
template <typename... ArgTypes>
void input(ArgTypes &... args);
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
void input(T &t, ArgTypes &... args)
{
    cin >> t;
    input(args...);
}

int main()
{
    fastio;
    untie;
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif

    int n;
    cin >> n;
    vll a(n);
    rep(i, n) cin >> a[i];
    if (n == 1)
    {
        cout << 1 << " " << 1 << endl
             << 0 << endl
             << 1 << " " << 1 << endl
             << 0 << endl
             << 1 << " " << 1 << endl
             << -a[0] << endl;
        return 0;
    }
    cout << 1 << " " << n - 1 << endl;
    for (int i = 0; i < n - 1; i++)
        cout << (n - 1) * a[i] << " ";
    cout << endl;
    cout << n << " " << n << endl;
    cout << n - a[n - 1] << endl;
    cout << 1 << " " << n << endl;
    for (int i = 0; i < n - 1; i++)
        cout << -n * a[i] << " ";
    cout << -n << endl;
}
