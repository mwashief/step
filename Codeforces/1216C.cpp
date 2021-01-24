/*
    Washief Hossain Mugdho
    24 January 2021
    Codeforces 1216C
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

class Sheet
{
public:
    int xmin, ymin, xmax, ymax;
};

bool check(Sheet &a, Sheet &b)
{
    if (a.ymin <= b.ymin && a.ymax >= b.ymax)
    {
        if (a.xmin >= b.xmax || a.xmax <= b.xmin)
            return 0;
        if (a.xmin > b.xmin && a.xmax < b.xmax)
            return 0;
        if (a.xmin <= b.xmin && a.xmax >= b.xmax)
            return 1;
        if (a.xmax > b.xmin && a.xmax < b.xmax)
        {
            b.xmin = a.xmax;
            return 0;
        }
        else
        {
            b.xmax = a.xmin;
            return 0;
        }
    }
    if (a.xmin <= b.xmin && a.xmax >= b.xmax)
    {
        if (a.ymin >= b.ymax || a.ymax <= b.ymin)
            return 0;
        if (a.ymin > b.ymin && a.ymax < b.ymax)
            return 0;
        if (a.ymin <= b.ymin && a.ymax >= b.ymax)
            return 1;
        if (a.ymax > b.ymin && a.ymax < b.ymax)
        {
            b.ymin = a.ymax;
            return 0;
        }
        else
        {
            b.ymax = a.ymin;
            return 0;
        }
    }
    return 0;
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
    Sheet white, b1, b2;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    white = {x1, y1, x2, y2};
    cin >> x1 >> y1 >> x2 >> y2;
    b1 = {x1, y1, x2, y2};
    cin >> x1 >> y1 >> x2 >> y2;
    b2 = {x1, y1, x2, y2};
    if (check(b1, white) || check(b2, white))
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
}
