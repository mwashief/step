/*
    13 October 2023
    Codeforces 1751-2000 1881 1881G
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
    int n, m;
    string s;
    cin >> n >> m >> s;
    vi dist(n, -1);

    seti even, odd;

    auto check = [&](int k) -> void
    {
        if (k > 0 && k < n && dist[k] == 0)
            even.insert(k);
        if (k > 1 && k < n && (dist[k] + dist[k - 1]) % 26 == 0)
            odd.insert(k);
    };

    repe(i, n - 1)
    {
        dist[i] = (s[i] - s[i - 1] + 26) % 26;
        check(i);
    }

    auto isBeautiful = [&](int l, int r)
    {
        if (l == r)
            return true;
        auto itEven = even.lower_bound(l + 1);
        if (itEven != even.end() && *itEven <= r)
            return false;
        auto itOdd = odd.lower_bound(l + 2);
        if (itOdd != odd.end() && *itOdd <= r)
            return false;
        return true;
    };

    auto add = [&](int l, int r, int x)
    {
        even.erase(l);
        odd.erase(l);
        odd.erase(l + 1);
        even.erase(r + 1);
        odd.erase(r + 1);
        odd.erase(r + 2);

        if (l)
            dist[l] = (dist[l] + x) % 26;
        if (r + 1 < n)
            dist[r + 1] = (dist[r + 1] - (x % 26) + 26) % 26;

        check(l);
        check(l + 1);
        check(r + 1);
        check(r + 2);
    };

    while (m--)
    {
        int t, l, r;
        cin >> t >> l >> r;
        l--;
        r--;
        if (t == 1)
        {
            int x;
            cin >> x;
            add(l, r, x);
        }
        else if (isBeautiful(l, r))
            pyes << endl;
        else
            pno << endl;
    }
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