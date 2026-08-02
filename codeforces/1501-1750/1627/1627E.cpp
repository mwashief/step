/*
    Washief Hossain Mugdho
    17 January 2022
    Codeforces 1501-1750 1627 1627E
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
    int n, m, k;
    cin >> n >> m >> k;
    vl x(n);
    rep(i, n) cin >> x[i];

    vector<vector<pair<pair<int, ll>, pii>>> ladders(n);
    vector<vector<pair<int, ll>>> memo(n);
    memo[n - 1].pb({m - 1, 0LL});
    rep(i, k)
    {
        int a, b, c, d, h;
        cin >> a >> b >> c >> d >> h;
        a--;
        b--;
        c--;
        d--;
        ladders[c].pb({{d, h}, {a, b}});
    }

    rrep(i, n)
    {
        sort(a2z(memo[i]));
        sort(a2z(ladders[i]), [&](pair<pair<int, ll>, pii> a, pair<pair<int, ll>, pii> b) -> bool
             { return a.fr.fr < b.fr.fr; });
        if (gsz(memo[i]) == 0 || gsz(ladders[i]) == 0)
            continue;

        vector<pair<int, ll>> left;
        for (auto d : memo[i])
            if (gsz(left) == 0)
                left.pb(d);
            else if (d.sc < left.back().sc + x[i] * (d.fr - left.back().fr))
                left.pb(d);

        pair<int, ll> right = {-1, -1};
        for (int j = gsz(ladders[i]) - 1; j >= 0; j--)
        {
            int b = ladders[i][j].fr.fr;
            ll h = ladders[i][j].fr.sc;
            int c = ladders[i][j].sc.fr;
            int d = ladders[i][j].sc.sc;

            while (gsz(left) && left.back().fr > b)
                left.pop_back();
            while (gsz(memo[i]) && memo[i].back().fr > b)
            {
                if (right.fr == -1)
                    right = memo[i].back();
                else if (memo[i].back().sc < right.sc + x[i] * (right.fr - memo[i].back().fr))
                    right = memo[i].back();
                memo[i].pop_back();
            }
            ll cost = INT64_MAX;
            if (gsz(left))
                cost = left.back().sc + x[i] * (b - left.back().fr);
            if (right.fr != -1)
                cost = min(cost, right.sc + x[i] * (right.fr - b));
            cost -= h;
            memo[c].pb({d, cost});
        }
    }
    if (gsz(memo[0]) == 0)
    {
        cout << "NO ESCAPE" << endl;
        return;
    }
    pair<int, ll> right = {-1, -1};
    while (gsz(memo[0]))
    {
        if (right.fr == -1)
            right = memo[0].back();
        else if (memo[0].back().sc < right.sc + x[0] * (right.fr - memo[0].back().fr))
            right = memo[0].back();
        memo[0].pop_back();
    }
    cout << right.sc + x[0] * right.fr << endl;
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