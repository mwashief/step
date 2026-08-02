/*
    Washief Hossain Mugdho
    16 December 2021
    HackerEarth dec-circuit E
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

ll bamer[10][50], daner[10][50], memo[10][50][2];

ll dpb(int dig, int sum)
{
    if (sum < 0)
        return 0;
    if (dig == 1)
    {
        if (sum > 9 || sum == 0)
            return 0;
        return 1;
    }
    if (bamer[dig][sum] != -1)
        return bamer[dig][sum];
    ll res = 0;
    rep(i, 10) res += dpb(dig - 1, sum - i);
    return bamer[dig][sum] = res;
}

ll dpd(int dig, int sum)
{
    if (dig == 0)
        return !sum;
    if (sum < 0)
        return 0;
    if (dig == 1)
    {
        if (sum > 9)
            return 0;
        return 1;
    }
    if (daner[dig][sum] != -1)
        return daner[dig][sum];
    ll res = 0;
    rep(i, 10) res += dpd(dig - 1, sum - i);
    return daner[dig][sum] = res;
}

ll getVal(ll temp)
{
    vi digs;
    while (temp)
    {
        digs.pb(temp % 10LL);
        temp /= 10LL;
    }
    int dig = (gsz(digs) - 1) >> 1;
    ll res = 0;
    repe(i, 46) repe(j, dig) res += 1LL * dpb(j, i) * dpd(j, i);

    if (gsz(digs) && gsz(digs) % 2 == 0)
    {
        reverse(a2z(digs));
        dig = gsz(digs) >> 1;
        int sum = 0;
        rep(i, dig) sum += digs[i];
        ms(memo, 0);

        repe(i, digs[0] - 1) memo[0][i][1] = 1;
        memo[0][digs[0]][0] = 1;

        for (int i = 0; i < dig - 1; i++)
            for (int j = 1; j < 45; j++)
                for (int k = 0; k < 2; k++)
                    if (memo[i][j][k])
                    {
                        if (k)
                            rep(t, 10) memo[i + 1][j + t][1] += memo[i][j][k];
                        else
                        {
                            rep(t, digs[i + 1]) memo[i + 1][j + t][1] += memo[i][j][k];
                            memo[i + 1][j + digs[i + 1]][0] += memo[i][j][k];
                        }
                    }

        repe(i, 46) res += 1LL * memo[dig - 1][i][1] * dpd(dig, i);
        for (int i = dig; i < gsz(digs); i++)
        {
            for (int j = 0; j < digs[i]; j++)
                res += dpd(2 * dig - i - 1, sum - j);
            sum -= digs[i];
        }
        res += (sum == 0);
    }
    return res;
}

inline void __run_test()
{
    ll l, r;
    cin >> l >> r;
    cout << getVal(r) - getVal(l - 1) << endl;
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
    ms(bamer, -1);
    ms(daner, -1);
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