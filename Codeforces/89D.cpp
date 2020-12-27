/*
    Washief Hossain Mugdho
    28 December 2020
    Codeforces 89D
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
#define MOD 100000000

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
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
int n[2], k[2];
int memo[105][105][2];

int dp(vector<int> arr, int now)
{
    if (arr[now] == 0)
    {
        if (arr[1 - now] == 0)
            return 1;
        return 0;
    }
    if (memo[arr[0]][arr[1]][now] != -1)
        return memo[arr[0]][arr[1]][now];
    int res = 0;
    for (int i = 1; i <= min(k[now], arr[now]); i++)
        if (now)
            res = (res + dp({arr[0], arr[1] - i}, 1 - now)) % MOD;
        else
            res = (res + dp({arr[0] - i, arr[1]}, 1 - now)) % MOD;
    return memo[arr[0]][arr[1]][now] = res;
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
    ms(memo, -1);
    cin >> n[0] >> n[1] >> k[0] >> k[1];
    cout << (dp({n[0], n[1]}, 0) + dp({n[0], n[1]}, 1)) % MOD << endl;
}
