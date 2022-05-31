/*
    Washief Hossain Mugdho
    28 March 2021
    Others jam2
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
#define endl "\n"
#define MOD 1000000007
#define MAX 100000

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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll getRand(ll a, ll b)
{
    uniform_int_distribution<ll> uid(a, b);
    return uid(rng);
}

int main()
{
    fastio;
    untie;
    cout.tie(0);

#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "w", stdout);
#endif
    int n = 1000000;
    cout << n << endl;
    rep(i, n) cout << getRand(2, 5) << " ";
    cout << endl;
}
