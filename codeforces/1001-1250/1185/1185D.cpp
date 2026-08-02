/*
    Washief Hossain Mugdho
    26 January 2021
    Codeforces 1185D
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
    vpii a(n);
    rep(i, n)
    {
        cin >> a[i].fr;
        a[i].sc = i + 1;
    }
    sort(a.begin(), a.end());
    vi prefix(n), suffix(n);
    prefix[1] = a[1].fr - a[0].fr;
    suffix[n - 2] = a[n - 1].fr - a[n - 2].fr;
    for (int i = 2; i < n; i++)
    {
        if (prefix[i - 1] == -1)
            prefix[i] = -1;
        else
        {
            if (a[i].fr - a[i - 1].fr == prefix[i - 1])
                prefix[i] = prefix[i - 1];
            else
                prefix[i] = -1;
        }
    }
    for (int i = n - 3; i >= 0; i--)
    {
        if (suffix[i + 1] == -1)
            suffix[i] = -1;
        else
        {
            if (a[i + 1].fr - a[i].fr == suffix[i + 1])
                suffix[i] = suffix[i + 1];
            else
                suffix[i] = -1;
        }
    }
    if (prefix[n - 2] != -1)
    {
        cout << a[n - 1].sc << endl;
        return 0;
    }
    if (suffix[1] != -1)
    {
        cout << a[0].sc << endl;
        return 0;
    }
    prefix[0] = suffix[n - 2];
    suffix[n - 1] = prefix[1];
    for (int i = 1; i < n - 1; i++)
    {
        if (prefix[i - 1] == -1 || suffix[i + 1] == -1)
            continue;
        if (prefix[i - 1] == suffix[i + 1] && a[i - 1].fr + prefix[i - 1] == a[i + 1].fr)
        {
            cout << a[i].sc << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
