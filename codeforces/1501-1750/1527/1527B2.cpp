/*
    Washief Hossain Mugdho
    21 May 2021
    Codeforces 1527 1527B2
*/

#ifndef DEBUG
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
#define rep(i, n) for (int i = 0; i < (n); (i)++)
#define repe(i, n) for (int i = 1; i <= (n); (i)++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; (i)--)
#define rrepe(i, n) for (int i = (n); i > 0; (i)--)
#define ms(a, b) memset(a, b, sizeof a)
#define a2z(x) (x).begin(), (x).end()
#define z2a(x) (x).rbegin(), (x).rend()
#define gsz(v) ((int)(v).size())
#define MOD 1000000007 //998244353
#define MAX 1000005

#ifndef __INTERACTIVE__
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

bool visited[505][505][2][2];

int memo[505][505][2][2];

int dp(int x, int y, int z, int must)
{
    if (x + y + z == 0)
        return 0;
    if (visited[x][y][z][must])
        return memo[x][y][z][must];
    visited[x][y][z][must] = 1;
    int res = INT32_MAX;
    if (must == 0 && x != 0)
        res = min(res, -dp(x, y, z, 1));
    if (x)
        res = min(res, 1 - dp(x - 1, y, z, 0));
    if (y)
        res = min(res, 1 - dp(x + 1, y - 1, z, 0));
    if (z)
        res = min(res, 1 - dp(x, y, 0, 0));
    return memo[x][y][z][must] = res;
}

inline void __run_test()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int x = 0, y = 0, z = 0;
    rep(i, n >> 1)
    {
        if (s[i] == '0' && s[n - 1 - i] == '0')
            y++;
        else if (s[i] == '0' || s[n - 1 - i] == '0')
            x++;
    }
    if (n & 1 && s[n >> 1] == '0')
        z = 1;
    int temp = dp(x, y, z, 0);
    if (temp < 0)
        cout << "ALICE";
    else if (temp > 0)
        cout << "BOB";
    else
        cout << "DRAW";
    cout << endl;
}

int main()
{
    fastio;
#ifndef __INTERACTIVE__
    untie;
#endif
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    ms(visited, 0);
    int __tests;
    cin >> __tests;
    while (__tests--)
        __run_test();
}