/*
    Washief Hossain Mugdho
    12 April 2021
    Codeforces 1511 1511E
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
#define MOD 998244353

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vb = vector<bool>;
using vi = vector<int>;
using vc = vector<char>;
using vl = vector<ll>;
using vvb = vector<vector<bool>>;
using vvc = vector<vector<char>>;
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

int main()
{
    fastio;
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif

    int n, m;
    cin >> n >> m;
    vvc mat(n, vc(m));
    int whites = 0;
    rep(i, n) rep(j, m)
    {
        cin >> mat[i][j];
        if (mat[i][j] == 'o')
            whites++;
    }
    ll res = 0LL;
    vl powa(whites + 5);
    powa[0] = 1LL;
    repe(i, whites + 4) powa[i] = 2LL * powa[i - 1] % MOD;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 'o')
            {
                ll x = 0LL;
                int k = j;
                for (k = j; k < m; k++)
                {
                    if (mat[i][k] != 'o')
                        break;
                    x++;
                }
                j = k;
                ll sign = 1LL;
                int d = 2;
                while (x > 1LL)
                {
                    ll term = 1LL * (x - 1LL) * powa[whites - d] % MOD;
                    res = 1LL * (1LL * res + sign * term + MOD) % MOD;
                    d++;
                    sign *= -1LL;
                    x--;
                }
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[j][i] == 'o')
            {
                ll x = 0LL;
                int k = j;
                for (k = j; k < n; k++)
                {
                    if (mat[k][i] != 'o')
                        break;
                    x++;
                }
                j = k;
                ll sign = 1LL;
                int d = 2;
                while (x > 1)
                {
                    ll term = 1LL * (x - 1LL) * powa[whites - d] % MOD;
                    res = 1LL * (1LL * res + sign * term + MOD) % MOD;
                    d++;
                    sign *= -1LL;
                    x--;
                }
            }
        }
    }
    cout << res << endl;
}
