/*
    Washief Hossain Mugdho
    25 December 2020
    Codeforces Edu94C
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

void run_tests()
{
    int x;
    string s;
    cin >> s >> x;
    vector<bool> visi(s.size(), false);
    vector<bool> res(s.size(), false);
    rep(i, s.size())
    {
        bool now = s[i] - '0';
        if (!now)
        {
            if (i - x >= 0)
            {
                if (!visi[i - x])
                {
                    visi[i - x] = 1;
                    res[i - x] = 0;
                }
                else if (res[i - x] != 0)
                {
                    cout << -1 << endl;
                    return;
                }
            }
            if (i + x < s.size())
            {
                visi[i + x] = 1;
                res[i + x] = 0;
            }
        }
        else
        {
            bool done = false;
            if (i - x >= 0)
            {
                if (!visi[i - x])
                {
                    visi[i - x] = 1;
                    res[i - x] = now;
                    done = true;
                }
                else if (res[i - x])
                    done = true;
            }
            if (!done && i + x < s.size())
            {
                visi[i + x] = 1;
                res[i + x] = now;
                done = 1;
            }
            if (!done)
            {
                cout << -1 << endl;
                return;
            }
        }
    }
    rep(i, res.size()) cout << res[i];
    cout << endl;
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

    int tc;
    cin >> tc;
    while (tc--)
        run_tests();
}
