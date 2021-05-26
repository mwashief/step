/*
    Washief Hossain Mugdho
    08 March 2021
    1338 1338C
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
ll nx[3][4] = {{0, 1, 2, 3}, {0, 2, 3, 1}, {0, 3, 1, 2}};
inline void _()
{
    ll n;
    cin >> n;
    ll s = (n - 1LL) / 3LL;
    int d = -1;
    ll f = 1;
    ll child = (n - 1) % 3;
    while ((f - 1) / 3 - 1 < s)
    {
        f <<= 2;
        d++;
    }
    ll extra = s - ((1LL << (2 * d)) - 1) / 3;
    ll parent = (1LL << (2 * d)) + extra;
    //cout << parent << " " << child << endl;
    if (!child)
    {
        cout << parent << endl;
        return;
    }
    ll ans = (1LL << (2 * d + 1));
    if (child == 2)
        ans |= (1LL << (2 * d));
    for (int i = 0; i < d; i++)
    {
        ll mask = (1LL << (2 * i)) | (1LL << (2 * i + 1));
        mask = parent & mask;
        mask >>= (2 * i);
        mask = nx[child][mask];
        mask <<= (2 * i);
        ans |= mask;
    }
    cout << ans << endl;
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
