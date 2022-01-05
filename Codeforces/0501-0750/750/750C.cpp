/*
    Washief Hossain Mugdho
    14 January 2021
    Codeforces 750C
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
const int mxret = 200000000;
const int mnret = -200000000;

int add(int a, int b)
{
    if (a == mxret)
        return mxret;
    if (a == mnret)
        return mnret;
    return a + b;
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
    int hi = mxret;
    int low = mnret;
    int n;
    cin >> n;
    rep(i, n)
    {
        int c, d;
        cin >> c >> d;
        if (d == 1)
        {
            hi = min(mxret, hi);
            low = max(low, 1900);
        }
        else
        {
            hi = min(hi, 1899);
            low = max(low, mnret);
        }
        hi = add(hi, c);
        low = add(low, c);
    }
    if (hi < low)
        cout << "Impossible" << endl;
    else if (hi == mxret)
        cout << "Infinity" << endl;
    else
        cout << hi << endl;
}
