/*
    Washief Hossain Mugdho
    23 December 2021
    Codeforces 1501-1750 1593 1593F
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

bool memo[42][42][42][42];
bool parent[42][42][42][42];
int n, a, b;

inline void __run_test()
{
    cin >> n >> a >> b;
    string s;
    cin >> s;
    vi d;
    for (auto c : s)
        d.pb(c - '0');
    ms(memo, false);
    memo[0][d[0] % a][0][1] = true;
    parent[0][d[0] % a][0][1] = true;
    memo[0][0][d[0] % b][0] = true;
    parent[0][0][d[0] % b][0] = false;
    rep(i, n - 1) rep(j, a) rep(k, b) rep(as, n) if (memo[i][j][k][as])
    {
        //taking a
        memo[i + 1][(j * 10 + d[i + 1]) % a][k][as + 1] = true;
        parent[i + 1][(j * 10 + d[i + 1]) % a][k][as + 1] = true;

        //taking b
        memo[i + 1][j][(k * 10 + d[i + 1]) % b][as] = true;
        parent[i + 1][j][(k * 10 + d[i + 1]) % b][as] = false;
    }
    int taken = -1;
    int gap = n + 1;
    repe(as, n - 1) if (memo[n - 1][0][0][as] && abs(n - 2 * as) < gap)
    {
        taken = as;
        gap = abs(n - 2 * as);
    }
    if (taken == -1)
    {
        cout << -1 << endl;
        return;
    }
    string res;
    int now = n - 1;
    int x = 0, y = 0;
    while (true)
    {
        int p = parent[now][x][y][taken];
        if (p)
            res.pb('R');
        else
            res.pb('B');
        taken -= p;
        now--;
        if (now < 0)
            break;
        if (p)
        {
            rep(i, a) if (memo[now][i][y][taken] && (i * 10 + d[now + 1]) % a == x)
            {
                x = i;
                break;
            }
        }
        else
        {
            rep(i, b) if (memo[now][x][i][taken] && (i * 10 + d[now + 1]) % b == y)
            {
                y = i;
                break;
            }
        }
    }
    reverse(a2z(res));
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

/*
-> Check for data types
-> Fix macro
-> Run test case
-> Check the copied part
-> Set or multiset?
-> Check statement order
*/