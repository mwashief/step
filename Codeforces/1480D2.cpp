/*
    Washief Hossain Mugdho
    13 February 2021
    Codeforces 1480D2
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
    vi a;
    a.pb(0);
    rep(i, n)
    {
        int x;
        cin >> x;
        if (a.back() != x)
            a.pb(x);
    }
    a.pb(0);
    map<int, set<int>> positions;
    rep(i, a.size()) positions[a[i]].insert(i);
    int x = 0;
    int y = 0;
    int res = 0;
    repe(i, a.size() - 2)
    {
        int num = a[i];
        if (x == num || y == num)
            continue;
        if (positions[x].upper_bound(i) == positions[x].end())
        {
            res++;
            x = num;
        }
        else if (positions[y].upper_bound(i) == positions[y].end())
        {
            res++;
            y = num;
        }
        else if (*positions[x].upper_bound(i) < *positions[y].upper_bound(i))
        {
            res++;
            y = num;
        }
        else
        {
            res++;
            x = num;
        }
    }
    cout << res << endl;
}
