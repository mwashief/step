/*
    Washief Hossain Mugdho
    10 April 2021
    Codeforces 1512 1512G
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
using umii = unordered_map<int, int>;
using seti = set<int>;
using useti = unordered_set<int>;

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
vi a(10000001);
vi ans(10000001);

inline void _()
{
    int c;
    cin >> c;
    if (ans[c] == INT32_MAX)
    {
        cout << -1 << endl;
        return;
    }
    cout << ans[c] << endl;
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

    a[1] = 0;
    for (int i = 2; i <= 10000000; i++)
    {
        for (int j = i; j <= 10000000; j += i)
            a[j] += i;
    }
    for (int i = 1; i <= 10000000; i++)
        ans[i] = INT32_MAX;
    for (int i = 1; i <= 10000000; i++)
    {
        if (a[i] + 1 > 10000000)
            continue;
        ans[a[i] + 1] = min(ans[a[i] + 1], i);
    }
    int __;
    cin >> __;
    while (__--)
        _();
}
