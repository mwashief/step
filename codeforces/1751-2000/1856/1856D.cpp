/*
    07 September 2023
    Codeforces 1751-2000 1856 1856D
*/

#ifndef __DEBUG__
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#endif

#define __INTERACTIVE__

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

int query(int i, int j)
{
    cout << "? " << i << " " << j << endl;
    int x;
    cin >> x;
    return x;
}

inline void __run_test()
{
    int n;
    cin >> n;
    vi right(n + 1, -1), left(n + 1, -1);
    map<int, seti> distanceToL;
    vi dir;
    dir.pb(0);
    repe(i, n - 1) dir.pb(query(i, i + 1));
    dir.pb(1);
    vi tops;
    repe(i, n) if (dir[i - 1] == 0 && dir[i] == 1) tops.pb(i);

    if (gsz(tops) == 1)
    {
        cout << "! " << tops[0] << endl;
        return;
    }
    rep(i, gsz(tops) - 1)
    {
        right[tops[i]] = tops[i + 1];
        left[tops[i + 1]] = tops[i];
        distanceToL[tops[i + 1] - tops[i]].insert(tops[i]);
    }

    auto deleteTop = [&](int top) -> void
    {
        int l = left[top];
        int r = right[top];

        distanceToL[r - top].erase(top);

        if (l != -1)
        {
            distanceToL[top - l].erase(l);
            right[l] = r;
            if (r != -1)
                distanceToL[r - l].insert(l);
        }

        if (r != -1)
            left[r] = l;
    };

    int res = 0;
    while (gsz(distanceToL))
    {
        if (distanceToL.begin()->sc.size() == 0)
        {
            distanceToL.erase(distanceToL.begin());
            continue;
        }

        auto it = distanceToL.begin()->sc.begin();
        int l = *it;
        int r = right[l];

        int whole = query(l, r);
        int partial = query(l + 1, r);

        int bigger = r;
        if (whole == partial + r - l)
            bigger = l;

        res = bigger;
        deleteTop(r + l - bigger);
    }

    cout << "! " << res << endl;
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