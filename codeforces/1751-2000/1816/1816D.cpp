/*
    09 April 2023
    Codeforces 1751-2000 1816 1816D
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

int q1(int x)
{
    cout << "+ " << x << endl;
    cin >> x;
    return x;
}

int q2(int i, int j)
{
    cout << "? " << i << " " << j << endl;
    cin >> i;
    return i;
}

inline void __run_test()
{
    int n;
    cin >> n;
    q1(n + 1);
    q1(n);
    vi path(n);
    vi res(n, -1);
    for (int i = 0; i < n; i += 2)
        path[i] = n - i / 2;
    for (int i = 1; i < n; i += 2)
        path[i] = (i + 1) / 2;

    vi ini;
    repe(i, n - 1) ini.pb(q2(1, i + 1));
    int pos = *max_element(a2z(ini));

    auto sswap = [&](int dis)
    {
        swap(res[pos - dis], res[pos + dis]);
    };

    int cnt = n - 1;

    rep(i, n - 1)
    {
        if (res[pos - ini[i]] != -1)
            sswap(ini[i]);
        res[pos - ini[i]] = i + 1;
    }
    res[pos] = 0;

    rep(i, n - 2) if (i != pos && i != pos - 1 && cnt)
    {
        cnt--;
        int dis = abs(i + 1 - pos);
        int found = q2(res[i] + 1, res[i + 1] + 1);
        if (found != 1)
            sswap(dis);
    }

    vi all(n);
    rep(i, n) all[res[i]] = i;

    auto print = [&]()
    {
        rep(i, n) cout << path[all[i]] << " ";
    };
    cout << "! ";
    print();
    reverse(a2z(path));
    print();
    cout << endl;
    int dummy;
    cin >> dummy;
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