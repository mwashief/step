/*
    Washief Hossain Mugdho
    06 February 2022
    Codeforces 1501-1750 1634 1634D
*/

#ifndef __DEBUG__
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
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

int q(int i, int j, int k)
{
    cout << "? " << i << " " << j << " " << k << endl;
    int d;
    cin >> d;
    return d;
}

inline void __run_test()
{
    int n;
    cin >> n;
    vi a(n + 1, INT32_MIN), b(n + 1, INT32_MIN);
    for (int i = 3; i <= n; i++)
        a[i] = q(1, 2, i);

    int same = 1;
    for (int j = 4; j <= n; j++)
        if (a[j] != a[3])
            same = 0;

    int ff = INT32_MIN;
    int ind = -1;
    for (int i = 3; i <= n; i++)
        if (a[i] > ff)
        {
            ff = a[i];
            ind = i;
        }

    if (same)
        ind = 2;

    int fr = 2;
    if (ind == 2)
        fr = n;

    for (int i = 1; i <= n; i++)
        if (i != ind && i != fr)
            b[i] = q(ind, fr, i);

    int d = b[1];

    same = 1;
    for (int i = 1; i <= n; i++)
        if (i != ind && i != fr && b[i] != d)
            same = 0;
    if (same)
    {
        cout << "! " << fr << " " << ind << endl;
        return;
    }

    ff = INT32_MIN;
    int ind2 = -1;
    repe(i, n) if (b[i] > ff)
    {
        ff = b[i];
        ind2 = i;
    }
    int last = -1;
    repe(i, n) if (i != fr && i != ind && i != ind2) last = i;
    vi jk = {fr, ind, ind2};
    int cul = 2;
    rep(i, 2)
    {
        cout << "?";
        rep(j, 3) if (j != i) cout << " " << jk[j];
        cout << " " << last << endl;
        int qq;
        cin >> qq;
        if (qq == ff)
        {
            cul = i;
            break;
        }
    }
    cout << "!";
    rep(i, 3) if (i != cul) cout << " " << jk[i];
    cout << endl;
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