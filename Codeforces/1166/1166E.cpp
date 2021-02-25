/*
    Washief Hossain Mugdho
    24 February 2021
    1166 1166E
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

int main()
{
    fastio;
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    int m, n;
    cin >> m >> n;
    vvb all(m, vb(n));
    rep(mm, m)
    {
        int x;
        cin >> x;
        rep(i, x)
        {
            int y;
            cin >> y;
            all[mm][y - 1] = 1;
        }
    }
    rep(i, m) for (int j = i + 1; j < m; j++)
    {
        int k = 0;
        for (; k < n; k++)
            if (all[i][k] == 1 && all[j][k] == 1)
                break;
        if (k == n)
        {
            cout << "impossible" << endl;
            return 0;
        }
    }
    cout << "possible" << endl;
}
