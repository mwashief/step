/*
    06 March 2024
    Codeforces 1751-2000 1934 1934C
*/

#ifndef __DEBUG__
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#endif

#define __INTERACTIVE__

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define pyes cout << "YES" //"Yes"
#define pno cout << "NO"   //"No"
#define fastio ios_base::sync_with_stdio(0)
#define untie cin.tie(0)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repe(i, n) for (int i = 1; i <= (n); i++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; i--)
#define rrepe(i, n) for (int i = (n); i > 0; i--)
#define ms(a, b) memset(a, b, sizeof a)
#define a2z(x) (x).begin(), (x).end()
#define z2a(x) (x).rbegin(), (x).rend()
#define gsz(v) ((int)(v).size())
#define MOD 1000000007 // 998244353
#define MAX 1000005

#if !defined(__INTERACTIVE__) && !defined(__DEBUG__)
#define endl "\n"
#endif

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

using pii = pair<int, int>;
using pll = pair<ll, ll>;

using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<ll>;
using vpii = vector<pair<int, int>>;

using vvb = vector<vector<bool>>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vvpii = vector<vector<pair<int, int>>>;

using mii = map<int, int>;
using umii = unordered_map<int, int>;
using seti = set<int>;
using useti = unordered_set<int>;

int n, m;

int query(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > m)
        return 100;
    cout << "? " << x << " " << y << endl;
    cin >> x;
    return x;
}

void res(int x, int y)
{
    cout << "! " << x << " " << y << endl;
}

inline void __run_test()
{
    cin >> n >> m;
    int a = query(1, 1);
    if (!a)
    {
        res(1, 1);
        return;
    }

    int b = query(n, m);
    if (!b)
    {
        res(n, m);
        return;
    }

    int c = query(1, m);
    if (!c)
    {
        res(1, m);
        return;
    }

    int x = (a + c + 3 - m) / 2;
    int y = a + 2 - x;

    int d = query(x, y);
    if (!d)
    {
        res(x, y);
        return;
    }

    y = (2 * m - b - c + n - 1) / 2;
    x = c + 1 - m + y;

    res(x, y);
}

int main()
{
    fastio;
#if !defined(__INTERACTIVE__) && !defined(__DEBUG__)
    untie;
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
#endif

    int __tests;
    cin >> __tests;
    while (__tests--)
        __run_test();
}

/*
-> Check for data types
-> Fix macro
-> Run test case
-> Check the copied part
-> Set or multiset?
-> Check statement order
-> Check simple logic errors
-> Read problem statements carefully
*/