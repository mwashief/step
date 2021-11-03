/*
    Washief Hossain Mugdho
    03 November 2021
    Codeforces 1607H
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

int bound(int a, int b, int m)
{
    int take = min(a, m);
    m -= take;
    a -= take;
    b -= m;
    return a - b;
}

inline void __run_test()
{
    int n;
    cin >> n;
    vi a(n), b(n), m(n);
    map<int, vi> category;
    rep(i, n)
    {
        cin >> a[i] >> b[i] >> m[i];
        category[a[i] + b[i] - m[i]].pb(i);
    }
    int res = 0;
    vpii ans(n);
    for (auto cat : category)
    {
        vector<pair<int, pii>> segments;
        for (auto dish : cat.sc)
            segments.pb({dish, {bound(a[dish], b[dish], m[dish]), -bound(b[dish], a[dish], m[dish])}});
        sort(a2z(segments), [](pair<int, pii> a, pair<int, pii> b)
             { return a.sc.sc < b.sc.sc; });
        int now = 0;
        while (now < gsz(segments))
        {
            int left = segments[now].sc.fr;
            int right = segments[now].sc.sc;
            int it = now;
            while (it < gsz(segments) && segments[it].sc.fr <= right)
            {
                left = max(left, segments[it].sc.fr);
                it++;
            }
            res++;
            int x = (cat.fr + right) >> 1;
            int y = cat.fr - x;
            for (int i = now; i < it; i++)
            {
                int dish = segments[i].fr;
                ans[dish].fr = a[dish] - x;
                ans[dish].sc = b[dish] - y;
            }
            now = it;
        }
    }
    cout << res << endl;
    rep(i, n) cout << ans[i].fr << " " << ans[i].sc << endl;
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
