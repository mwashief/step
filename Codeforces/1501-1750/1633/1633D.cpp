/*
    Washief Hossain Mugdho
    31 January 2022
    Codeforces 1501-1750 1633 1633D
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

int memo[1004][1004];
vvi all(1004);
int dp(int a, int b)
{
    if (a == b)
        return 0;
    if (memo[a][b] != -1)
        return memo[a][b];
    int res = INT32_MAX;
    for (auto d : all[a])
    {
        int porer = a + d;
        if (porer <= b)
            res = min(res, 1 + dp(porer, b));
    }
    return memo[a][b] = res;
}
ll dp2[1000004];
inline void __run_test()
{
    int n, k;
    cin >> n >> k;
    vi wt(n), val(n);
    int tot = 0;
    rep(i, n)
    {
        int x;
        cin >> x;
        wt[i] = dp(1, x);
        tot += wt[i];
    }
    rep(i, n) cin >> val[i];

    if (k >= tot)
    {
        cout << accumulate(a2z(val), 0LL) << endl;
        return;
    }

    rep(i, k + 2) dp2[i] = 0;

    for (int i = 0; i < n; i++)
        for (int j = k; j >= wt[i]; j--)
            dp2[j] = max(dp2[j], dp2[j - wt[i]] + val[i]);

    cout << dp2[k] << endl;
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
    ms(memo, -1);
    for (int i = 1; i <= 1003; i++)
        for (int j = 1; j <= i; j++)
        {
            int d = i / j;
            if (gsz(all[i]) == 0)
                all[i].pb(d);
            else if (all[i].back() != d)
                all[i].pb(d);
        }
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