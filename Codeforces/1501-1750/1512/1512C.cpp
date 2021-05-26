/*
    Washief Hossain Mugdho
    10 April 2021
    Codeforces 1512 1512C
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

inline void _()
{
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    int n = s.size();
    int pairs = 0;
    int single = 0;
    for (int i = 0; i < n / 2; i++)
    {
        int o = n - 1 - i;
        if (s[i] == '?' && s[o] == '?')
        {
            pairs++;
            continue;
        }
        else if ((s[i] == '?' && s[o] == '1') || (s[i] == '1' && s[o] == '?'))
        {
            b -= 2;
            s[i] = '1';
            s[o] = '1';
        }
        else if ((s[i] == '?' && s[o] == '0') || (s[i] == '0' && s[o] == '?'))
        {
            a -= 2;
            s[i] = '0';
            s[o] = '0';
        }
        else if (s[i] != s[o])
        {
            cout << -1 << endl;
            return;
        }
        else if (s[i] == '0')
        {
            a -= 2;
        }
        else if (s[i] == '1')
        {
            b -= 2;
        }
    }
    if (a < 0 || b < 0)
    {
        cout << -1 << endl;
        return;
    }
    if (n % 2 == 1)
    {
        if (s[n / 2] == '?')
            single = 1;
        else if (s[n / 2] == '0')
        {
            a--;
        }
        else
            b--;
    }
    if (single)
    {
        if (a & 1)
        {
            s[n / 2] = '0';
            a--;
            single = 0;
        }
        else if (b & 1)
        {
            s[n / 2] = '1';
            b--;
            single = 0;
        }
    }
    if (single || (a + b) != 2 * pairs || (a & 1) || (b & 1))
    {
        cout << -1 << endl;
        return;
    }
    for (int i = 0; i < n / 2; i++)
    {
        int o = n - 1 - i;
        if (s[i] == '?' && s[o] == '?')
        {
            if (a)
            {
                a -= 2;
                s[i] = '0';
                s[o] = '0';
            }
            else if (b)
            {
                b -= 2;
                s[i] = '1';
                s[o] = '1';
            }
        }
    }
    cout << s << endl;
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
