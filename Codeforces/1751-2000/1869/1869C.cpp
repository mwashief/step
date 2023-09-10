/*
    10 September 2023
    Codeforces 1751-2000 1869 1869C
*/

#ifndef __DEBUG__
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#endif

#undef __INTERACTIVE__

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

inline void __run_test()
{
    int n, m;
    cin >> n >> m;
    vvi mat(n, vi(m));

    int r = min(n, m);
    rep(i, r) rep(j, r)
        mat[i][j] = (-i + j + r + (i == 0)) % r;

    if (n > m)
        for (int i = r; i < n; i++)
            rep(j, m) mat[i][j] = (j + 1) % m;
    else
        rep(i, n) for (int j = r; j < m; j++) mat[i][j] = j;

    if (m > n && n != 1)
    {
        swap(mat[0][r - 1], mat[0][r]);
        repe(i, n - 1) swap(mat[i][0], mat[i][r]);
    }

    if (n == 1 && m > 1)
        cout << 2 << endl;
    else if (m == 1)
        cout << 0 << endl;
    else if (m > n)
        cout << r + 1 << endl;
    else
        cout << r << endl;
    rep(i, n) rep(j, m) cout << mat[i][j] << " \n"[j == m - 1];
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