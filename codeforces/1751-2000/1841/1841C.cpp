/*
    16 June 2023
    Codeforces 1751-2000 1841 1841C
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

vl val = {1, 10, 100, 1000, 10000};

inline void __run_test()
{
    string s;
    cin >> s;
    int n = gsz(s);

    string suffixMax(n + 1, 'A');
    vl currentVal(n);
    rrep(i, n)
    {
        suffixMax[i] = max(s[i], suffixMax[i + 1]);
        currentVal[i] = val[s[i] - 'A'];
        if (s[i] < suffixMax[i + 1])
            currentVal[i] = -currentVal[i];
    }

    ll total = accumulate(a2z(currentVal), 0LL);
    ll res = total;
    vector<pair<char, int>> stk;
    ll prevVal = 0;

    rep(i, n)
    {
        total -= currentVal[i];

        for (char c = 'A'; c <= 'E'; c += 1)
        {
            ll stkVal = 0;
            rrep(j, gsz(stk)) if (stk[j].fr < max(c, suffixMax[i + 1]))
                stkVal -= val[stk[j].fr - 'A'] * stk[j].sc;
            else stkVal += val[stk[j].fr - 'A'] * stk[j].sc;

            res = max(res, total + (suffixMax[i + 1] > c ? -val[c - 'A'] : val[c - 'A']) + stkVal + prevVal);
        }

        while (gsz(stk) && stk.back().fr < s[i])
        {
            prevVal -= val[stk.back().fr - 'A'] * stk.back().sc;
            stk.pop_back();
        }
        if (gsz(stk) && stk.back().fr == s[i])
            stk.back().sc++;
        else
            stk.pb({s[i], 1});
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