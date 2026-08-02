/*
    23 July 2023
    Codeforces 1751-2000 1853 1853D
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
    vi a(n);
    mii m;
    rep(i, n)
    {
        cin >> a[i];
        m[a[i]]++;
    }
    vpii track;
    for (auto d : m)
        track.pb(d);

    reverse(a2z(track));
    if (track.back().fr == 0)
        track.pop_back();
    repe(i, gsz(track) - 1)
        track[i]
            .sc += track[i - 1].sc;

    auto findPre = [&](int k) -> int
    {
        if (k == 0)
            return -1;
        int l = 0, r = gsz(track) - 1;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (track[mid].sc == k)
                return mid;
            if (track[mid].sc < k)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -2;
    };

    vi sign(gsz(track));
    rep(i, gsz(track))
    {
        int k = findPre(track[i].fr);
        if (k == -2)
        {
            pno << endl;
            return;
        }
        if (k >= i)
            sign[i] = 1;
    }

    int highest1 = -1, lowest0 = gsz(track);
    rep(i, gsz(track)) if (sign[i]) highest1 = i;
    rrep(i, gsz(track)) if (!sign[i]) lowest0 = i;
    if (highest1 > lowest0)
    {
        pno << endl;
        return;
    }

    vi lastVal(gsz(track), INT32_MIN);
    int now = 1;

    rrep(i, gsz(track))
    {
        int k = findPre(track[i].fr);
        if ((sign[i] && k < highest1) || (!sign[i] && k >= lowest0))
        {
            pno << endl;
            return;
        }
        if (!sign[i])
            continue;
        for (int j = k; j >= 0 && lastVal[j] == INT32_MIN && sign[j] == 0; j--)
        {
            lastVal[j] = -now;
            now++;
        }
        lastVal[i] = now;
        now++;
    }

    mii mm;
    mm[0] = -now;

    rep(i, gsz(track))
    {
        if (lastVal[i] == INT32_MIN)
            lastVal[i] = -(now++);
        mm[track[i].fr] = lastVal[i];
    }
    pyes << endl;
    rep(i, n) cout << mm[a[i]] << " ";
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