/*
    Washief Hossain Mugdho
    11 October 2022
    Codeforces 1501-1750 1741 1741F
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

inline void __run_test()
{
    int n;
    cin >> n;
    vi l(n), r(n), c(n), res(n, INT32_MAX);
    vector<pair<int, pii>> running;
    multiset<int> openedColors;
    mii closedColor;
    set<pii, greater<pii>> closedColorInv;
    set<int> distinct;
    seti opened;
    vi closed;

    rep(i, n)
    {
        cin >> l[i] >> r[i] >> c[i];
        running.pb({l[i], {0, i}});
        running.pb({r[i], {1, i}});
    }

    sort(a2z(running), [&](pair<int, pii> a, pair<int, pii> b) -> bool
         {
        if(a.fr < b.fr) return true;
        if(b.fr < a.fr) return false;
        return a.sc.fr < b.sc.fr; });

    for (auto a : running)
    {
        int cor = a.fr;
        int left = 1 - a.sc.fr;
        int index = a.sc.sc;

        if (left)
        {
            while (gsz(opened) && c[*opened.begin()] != c[index])
            {
                res[*opened.begin()] = 0;
                res[index] = 0;
                opened.erase(opened.begin());
            }

            while (gsz(closed) && c[closed.back()] != c[index])
            {
                res[closed.back()] = min(res[closed.back()], cor - r[closed.back()]);
                res[index] = min(res[index], cor - r[closed.back()]);
                closed.pop_back();
            }

            int i = 0;

            for (auto d : closedColorInv)
                if (i < 2)
                {
                    i++;
                    if (d.sc != c[index])
                        res[index] = min(res[index], cor - d.fr);
                }
                else
                    break;

            openedColors.insert(c[index]);
            distinct.insert(c[index]);

            if (gsz(distinct) > 1)
                res[index] = 0;

            opened.insert(index);
        }
        else
        {
            openedColors.erase(openedColors.find(c[index]));
            if (openedColors.find(c[index]) == openedColors.end())
                distinct.erase(c[index]);

            if (opened.count(index))
                opened.erase(index);

            closedColorInv.erase({closedColor[c[index]], c[index]});
            closedColorInv.insert({cor, c[index]});

            closedColor[c[index]] = cor;

            if (res[index])
                closed.pb(index);
        }
    }

    rep(i, n) cout << res[i] << " ";
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
-> Check simple logic errors
-> Read problem statements carefully
*/