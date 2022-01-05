/*
    Washief Hossain Mugdho
    05 January 2022
    Codeforces 1501-1750 1621 1621F
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
ll n, a, b, c;

ll find(ll blackPairs, vl whites, ll stupid1, ll stupid2, int now)
{
    ll singles = 0;
    ll res = 0;
    ll ans = 0;
    while (true)
    {
        while (gsz(whites) && whites.back() == 1)
        {
            singles++;
            whites.pop_back();
        }
        if (now)
        {
            if (blackPairs)
            {
                res += b;
                blackPairs--;
            }
            else
                return max(res, ans);
        }
        else
        {
            ll temp = (b - c) * singles;
            ll temp2 = max(0LL, (b - c) * min(blackPairs, stupid1 + stupid2));
            ll take = 0;
            if (temp2 > 0LL)
                take = min(blackPairs, stupid1 + stupid2);
            if (gsz(whites) || ((stupid1 >= 2 || stupid2 >= 2) && stupid1 + stupid2 - take >= 2))
                temp += a;
            ans = max(ans, res + temp + temp2);
            if (gsz(whites))
            {
                res += a;
                whites.back()--;
            }
            else if (stupid1 >= 2)
            {
                res += a;
                stupid1--;
            }
            else if (stupid2 >= 2)
            {
                res += a;
                stupid2--;
            }
            else
                return max(res, ans);
        }
        now = 1 - now;
    }
    return max(res, ans);
}

inline void __run_test()
{
    cin >> n >> a >> b >> c;
    string s;
    cin >> s;
    ll blackPairs = 0;
    rep(i, n - 1) if (s[i] == s[i + 1] && s[i] == '1') blackPairs++;
    int firstBlack = n;
    rep(i, n) if (s[i] == '1')
    {
        firstBlack = i + 1;
        break;
    }
    vl whites;
    ll cnt = 0;
    for (int i = firstBlack; i < n; i++)
        if (s[i] == '1')
        {
            if (cnt)
                whites.pb(cnt);
            cnt = 0;
        }
        else
            cnt++;
    sort(a2z(whites), greater<ll>());
    ll stupid1 = 0;
    ll stupid2 = 0;
    rep(i, n) if (s[i] == '1') break;
    else stupid1++;
    rrep(i, n) if (s[i] == '1') break;
    else stupid2++;
    if (stupid1 == n)
        stupid2 = 0;

    cout << max(find(blackPairs, whites, stupid1, stupid2, 0), find(blackPairs, whites, stupid1, stupid2, 1)) << endl;
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