/*
    Washief Hossain Mugdho
    03 June 2022
    Codeforces 1501-1750 1685 1685B
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
    vvi param = {{0, 0}, {0, 0}};
    rep(i, 2) rep(j, 2) cin >> param[i][j];
    auto temp = param;
    string s;
    cin >> s;
    string t = s;
    vi cnt = {0, 0};
    for (auto c : s)
        cnt[c - 'A']++;
    if (cnt[0] != param[0][0] + param[1][0] + param[1][1])
    {
        pno << endl;
        return;
    }
    reverse(a2z(s));
    vpii all = {{s.back() - 'A', 0}};
    while (s.size())
    {
        int last = s.back();
        s.pop_back();
        all.back().sc++;
        if (s.size() == 0)
            break;
        if (s.back() == last)
            all.pb({last - 'A', 0});
    }
    sort(a2z(all), [&](pii a, pii b)
         { return a.sc < b.sc; });
    for (auto d : all)
    {
        if (d.sc % 2)
        {
            if (param[0][d.fr] > 0)
                param[0][d.fr]--;
            else
            {
                pno << endl;
                return;
            }
        }
        else
        {
            int k = d.sc / 2;
            if (param[1][d.fr] >= k)
                param[1][d.fr] -= k;
            else if (param[0][0] > 0 && param[0][1] > 0)
            {
                param[0][0]--;
                param[0][1]--;
            }
            else
            {
                pno << endl;
                return;
            }
        }
    }

    pyes << endl;
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
