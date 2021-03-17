/*
    Washief Hossain Mugdho
    17 March 2021
    Codeforces 1155 1155E
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
#define MOD 1000003
#define N 11

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

int add(int a, int b)
{
    return (a + b) % MOD;
}

int mul(int a, int b)
{
    return 1LL * a * b % MOD;
}

int query(int a)
{
    cout << "? " << a << endl;
    cin >> a;
    return a;
}

int inv[N][N] = {{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 {288490, 10, 499979, 40, 499949, 200051, 999968, 714305, 874997, 222224, 700002},
                 {966058, 884904, 258984, 206246, 229308, 179863, 736210, 190429, 361624, 345236, 641153},
                 {570243, 545454, 393253, 44286, 339435, 125150, 644108, 731008, 361144, 778423, 467511},
                 {975668, 247866, 366198, 824416, 397192, 365192, 815575, 879997, 462537, 275649, 389728},
                 {5700, 4516, 230635, 968077, 876884, 46558, 820987, 851403, 694703, 559146, 941409},
                 {673781, 61516, 487069, 217358, 919974, 96591, 770667, 647916, 929778, 401795, 793573},
                 {905550, 799308, 83507, 356946, 856599, 777781, 46180, 928773, 951218, 682178, 611981},
                 {479598, 854781, 166940, 340874, 422918, 395140, 646877, 370636, 525200, 526407, 270644},
                 {730019, 650746, 292548, 630822, 426911, 850697, 488601, 274604, 617921, 258042, 779107},
                 {404910, 950915, 220896, 410947, 30845, 962989, 30845, 410947, 220896, 950915, 404910}};

int coEffs[N];

int getVal(int val)
{
    int res = 0;
    int term = 1;
    rep(i, N)
    {
        res = add(res, mul(coEffs[i], term));
        term = mul(term, val);
    }
    return res;
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
    int q[N];
    rep(i, N) q[i] = query(i);
    rep(i, N)
    {
        int val = 0;
        rep(j, N) val = add(val, mul(inv[i][j], q[j]));
        coEffs[i] = val;
    }
    rep(i, MOD) if (getVal(i) == 0)
    {
        cout << "! " << i << endl;
        return 0;
    }
    cout << "! -1" << endl;
}
