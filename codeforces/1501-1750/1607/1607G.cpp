/*
    Washief Hossain Mugdho
    02 November 2021
    Codeforces 1607G
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
using vpll = vector<pair<ll, ll>>;

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
    vpii dishes;
    auto convert = [&](pii x)
    {
        int take = min(x.fr, m);
        int temp = m - take;
        x.fr -= take;
        x.sc -= temp;
        return x.fr - x.sc;
    };
    vpll ranges;
    ranges.pb({0, 0});
    ll left = 0, right = 0;
    ll current;
    rep(i, n)
    {
        int a, b;
        cin >> a >> b;
        dishes.pb({a, b});
        pii now = {convert({a, b}), -convert({b, a})};
        left += (ll)now.fr;
        right += (ll)now.sc;
        ranges.pb({left, right});
    }
    if (right < 0LL)
        current = -right;
    else if (left > 0LL)
        current = left;
    else if (right & 1LL)
        current = 1;
    else
        current = 0;
    ranges.pop_back();
    vpii res;
    cout << current << endl;
    rrep(i, n)
    {
        ll r = min<ll>(dishes[i].fr, m);
        ll l = max<ll>(0LL, m - dishes[i].sc);

        while (l < r)
        {
            ll mid = (l + r) >> 1;
            ll previ = current - dishes[i].fr + mid + dishes[i].sc - (m - mid);
            if (previ > ranges[i].sc)
                r = mid - 1;
            else if (previ < ranges[i].fr)
                l = mid + 1;
            else
            {
                l = mid;
                break;
            }
        }
        res.pb({l, m - l});
        current = current - dishes[i].fr + l + dishes[i].sc - (m - l);
    }
    reverse(a2z(res));
    rep(i, n) cout << res[i].fr << " " << res[i].sc << endl;
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
