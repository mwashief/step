/*
    Washief Hossain Mugdho
    01 October 2021
    Codeforces 1501-1750 1581 1581C
*/

#ifndef __DEBUG__
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
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
#define MOD 1000000007 //998244353
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

int mat[405][405];
int last[405];

int whites(int l, int r, int h1, int h2)
{
    int res = mat[h2 + 1][r + 1] - mat[h2 + 1][l];
    res -= mat[h1][r + 1] - mat[h1][l];
    return res;
};

int blacks(int l, int r, int h1, int h2)
{
    return (r - l + 1) * (h2 - h1 + 1) - whites(l, r, h1, h2);
};

inline void __run_test()
{
    int n, m;
    char c;
    cin >> n >> m;

    repe(i, n) rep(j, m)
    {
        cin >> c;
        mat[i][j + 1] = c - '0';
        mat[i][j + 1] = 1 - mat[i][j + 1] + mat[i][j];
    }
    repe(i, n) rep(j, m + 1) mat[i][j] += mat[i - 1][j];

    int res = 16;
    rep(l, m) for (int r = l + 3; r < m; r++)
    {
        last[n - 1] = whites(l + 1, r - 1, n - 1, n - 1);
        for (int k = n - 2; k >= 0; k--)
        {
            last[k] = whites(l + 1, r - 1, k, k);
            int extra = blacks(l + 1, r - 1, k, k) + whites(l, l, k, k) + whites(r, r, k, k);
            if (last[k] > last[k + 1] + extra)
                last[k] = last[k + 1] + extra;
        }
        rep(i, n - 4) res = min(res, whites(l + 1, r - 1, i, i) +
                                         blacks(l + 1, r - 1, i + 1, i + 3) +
                                         whites(l, l, i + 1, i + 3) +
                                         whites(r, r, i + 1, i + 3) +
                                         last[i + 4]);
    }
    cout << res << endl;
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