/*
    Washief Hossain Mugdho
    30 January 2021
    Codeforces 1400D
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
    vi a(n);
    unordered_map<int, ll> ini;
    rep(i, n)
    {
        cin >> a[i];
        ini[a[i]]++;
    }
    for (int i = 0; i <= n - 4; i++)
    {
        ini[a[i]]--;
        unordered_map<int, ll> left;
        unordered_map<int, ll> right;
        ll current = 0;
        for (auto x : ini)
            right[x.fr] = x.sc;
        right[a[i + 1]]--;
        for (int j = i + 2; j < n - 1; j++)
        {
            int prev = a[j - 1];
            int now = a[j];
            if (prev == now)
            {
                current = current - left[prev] * right[prev];
                left[prev]++;
                right[now]--;
                current = current + left[prev] * right[prev];
            }
            else
            {
                current = current - left[prev] * right[prev] - left[now] * right[now];
                left[prev]++;
                right[now]--;
                current = current + left[prev] * right[prev] + left[now] * right[now];
            }
            if (a[i] == a[j])
                res += current;
        }
    }
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
