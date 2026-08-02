/*
    Washief Hossain Mugdho
    28 December 2020
    Codeforces 1061B
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
    int n, m;
    cin >> n >> m;
    vi a(n);
    ll sum = 0;
    ll taken = 0;
    rep(i, n)
    {
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin(), a.end(), greater<int>());
    int highestHeightCovered = a[0] + 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (highestHeightCovered > a[i + 1] + 1)
        {
            taken += highestHeightCovered - a[i + 1] - 1;
            highestHeightCovered = a[i + 1] + 1;
        }
        else
        {
            taken++;
            highestHeightCovered--;
        }
    }
    cout << sum - taken - max(1, highestHeightCovered - 1) << endl;
}
