/*
    Washief Hossain Mugdho
    18 February 2021
    1383 1383A
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
    vvi all(20, vi(20));
    cin >> n;
    string a, b;
    cin >> a >> b;
    bool impo = 0;
    rep(i, n)
    {
        int x = a[i] - 'a';
        int y = b[i] - 'a';
        if (y < x)
            impo = 1;
        if (y > x)
            all[x][y]++;
    }
    if (impo)
    {
        cout << -1 << endl;
        return;
    }
    int res = 0;
    for (int i = 0; i < 20; i++)
    {
        int j = i + 1;
        while (j < 20)
        {
            if (all[i][j])
                break;
            j++;
        }
        if (j == 20)
            continue;
        res++;
        for (int k = j + 1; k < 20; k++)
            all[j][k] += all[i][k];
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
