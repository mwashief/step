/*
    Washief Hossain Mugdho
    26 February 2021
    1138 1138B
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
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    vi a, c, ac, useless;
    rep(i, n)
    {
        if (s[i] == t[i])
        {
            if (s[i] == '0')
                useless.pb(i + 1);
            else
                ac.pb(i + 1);
        }
        else if (s[i] == '1')
            c.pb(i + 1);
        else
            a.pb(i + 1);
    }
    int A = a.size();
    int AC = ac.size();
    int U = useless.size();
    rep(i, AC + 1)
    {
        int j = n / 2 - A - AC + i;
        if (j < 0 || j > U || (i + j + a.size() + c.size() < n / 2) || (i + j) > n / 2)
            continue;
        vi res;
        for (int k = 0; k < i; k++)
            res.pb(ac[k]);
        for (int k = 0; k < j; k++)
            res.pb(useless[k]);
        for (int k = 0; k < c.size() && res.size() < n / 2; k++)
            res.pb(c[k]);
        for (int k = 0; k < a.size() && res.size() < n / 2; k++)
            res.pb(a[k]);
        for (auto troupe : res)
            cout << troupe << " ";
        cout << endl;
        return 0;
    }
    cout << "-1" << endl;
}
