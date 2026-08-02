/*
    18 January 2023
    Codeforces 1751-2000 1782 1782C
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
    string s;
    cin >> n >> s;

    vector<pair<int, char>> freqs(26);
    rep(i, 26) freqs[i].sc = 'a' + i;
    for (auto c : s)
        freqs[c - 'a'].fr++;
    sort(z2a(freqs));

    auto getCost = [&](int slots) -> int
    {
        int res = 0;
        rep(i, slots)
            res += max(0, n / slots - freqs[i].fr);
        return res;
    };

    int cost = INT32_MAX;
    int res = -1;
    repe(slots, 26) if (n % slots == 0)
    {
        int now = getCost(slots);
        if (now < cost)
        {
            cost = now;
            res = slots;
        }
    }

    int per = n / res;

    int i = 0, j = res - 1;
    while (i < j)
    {
        if (freqs[i].fr <= per)
            i++;
        else if (freqs[j].fr >= per)
            j--;
        else
        {
            int ii = freqs[i].fr - per;
            int jj = per - freqs[j].fr;
            int now = min(ii, jj);
            freqs[i].fr -= now;
            freqs[j].fr += now;

            for (char &c : s)
                if (c == freqs[i].sc && now > 0)
                {
                    now--;
                    c = freqs[j].sc;
                }
        }
    }
    i = 0;
    j = gsz(freqs) - 1;
    while (i < j)
    {
        if (freqs[j].fr == 0)
            j--;
        else if (freqs[i].fr >= per)
            i++;
        else
        {
            int ii = per - freqs[i].fr;
            int jj = freqs[j].fr;
            int now = min(ii, jj);
            freqs[i].fr += now;
            freqs[j].fr -= now;

            for (char &c : s)
                if (c == freqs[j].sc && now > 0)
                {
                    now--;
                    c = freqs[i].sc;
                }
        }
    }
    cout << cost << endl;
    cout << s << endl;
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