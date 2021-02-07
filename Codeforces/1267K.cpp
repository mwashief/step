/*
    Washief Hossain Mugdho
    07 February 2021
    Codeforces 1267K
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
ull fact[25];

inline void _()
{
    vl rem;
    ull k;
    cin >> k;
    map<ull, int> m;
    for (ull i = 2; k > 0ULL; i++)
    {
        rem.pb(k % i);
        m[k % i]++;
        k /= i;
    }
    sort(rem.begin(), rem.end());
    ull res = 1ULL;
    for (ull i = 2ULL; i < 1ULL + rem.size(); i++)
    {
        ull nums = lower_bound(rem.begin(), rem.end(), i) - rem.begin();
        nums -= (i - 2ULL);
        res = res * nums;
    }
    if (m[0ULL])
    {
        ull res2 = 1ULL;
        rem.erase(rem.begin());
        for (ull i = 2ULL; i < 2ULL + rem.size(); i++)
        {
            ull nums = lower_bound(rem.begin(), rem.end(), i) - rem.begin();
            nums -= (i - 2ULL);
            if (nums < 0ULL)
                nums = 0ULL;
            res2 = res2 * nums;
        }
        res -= m[0ULL] * res2;
    }
    for (auto x : m)
        res /= fact[x.sc];
    cout << res - 1 << endl;
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
    fact[0] = 1;
    for (ull i = 1; i < 25; i++)
        fact[i] = fact[i - 1] * i;
    int __;
    cin >> __;
    while (__--)
        _();
}
