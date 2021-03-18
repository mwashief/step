/*
    Washief Hossain Mugdho
    17 March 2021
    Codeforces 1497 1497E1
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

vi primes;

inline void _()
{
    int n, k, x;
    cin >> n >> k;
    int ans = 1;
    unordered_set<int> pre;
    rep(i, n)
    {
        cin >> x;
        for (int prime : primes)
        {
            int d = 0;
            while (x % prime == 0)
            {
                x /= prime;
                d = 1 - d;
            }
            if (d)
                x *= prime;
        }
        if (pre.find(x) != pre.end())
        {
            pre.clear();
            ans++;
            pre.insert(x);
        }
        else
            pre.insert(x);
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
    primes.pb(2);
    vb v(3200);
    for (int i = 3; i < 3200; i += 2)
    {
        if (v[i])
            continue;
        primes.pb(i);
        for (int j = i * i; j < 3200; j += i)
            v[j] = 1;
    }
    int __;
    cin >> __;
    while (__--)
        _();
}
