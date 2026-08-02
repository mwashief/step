/*
    Washief Hossain Mugdho
    29 October 2021
    Codeforces 1501-1750 1560 1560F2
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

inline void __run_test()
{
    int n, k;
    cin >> n >> k;
    int temp = n;
    vi all;
    while (temp)
    {
        all.pb(temp % 10);
        temp /= 10;
    }
    seti d;
    rep(i, gsz(all)) d.insert(all[i]);
    if (gsz(d) <= k)
    {
        cout << n << endl;
        return;
    }
    rep(i, gsz(all))
    {
        if (all[i] == 9)
            continue;
        d.clear();
        temp = 0;
        for (int j = gsz(all) - 1; j > i; j--)
        {
            d.insert(all[j]);
            temp = temp * 10 + all[j];
        }
        if (gsz(d) < k)
        {
            k -= gsz(d);
            if (!d.count(all[i] + 1))
                k--;
            temp = 10 * temp + all[i] + 1;
            if (k)
                d.insert(0);
            d.insert(all[i] + 1);
            rrep(j, i) temp = 10 * temp + *d.begin();
            cout << temp << endl;
            return;
        }
        else if (gsz(d) == k)
        {
            auto it = upper_bound(a2z(d), all[i]);
            if (it == d.end())
                continue;
            temp = 10 * temp + *it;
            rrep(j, i) temp = 10 * temp + *d.begin();
            cout << temp << endl;
            return;
        }
    }
    cout << 1;
    rep(i, gsz(all)) cout << (k == 1 ? 1 : 0);
    cout << endl;
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