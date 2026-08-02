/*
    Washief Hossain Mugdho
    20 January 2022
    Codeforces 1501-1750 1558 1558C
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
    int n, temp;
    cin >> n;
    temp = n;
    vi a(n + 1);
    vi res;
    repe(i, n) cin >> a[i];
    auto rev = [&](int len)
    {
        if (len == 1)
            return;
        if (gsz(res) && res.back() == len)
            res.pop_back();
        else
            res.pb(len);
        repe(i, len / 2) swap(a[i], a[len - i + 1]);
    };
    auto find = [&](int num) -> int
    {
        repe(i, n) if (a[i] == num) return i;
        return 0;
    };

    while (n > 1)
    {
        int x = find(n);
        int y = find(n - 1);
        if ((x & 1) == 0 || y & 1)
        {
            cout << -1 << endl;
            return;
        }
        if (x > y)
        {
            if (x == n && y == n - 1)
            {
                n -= 2;
                continue;
            }
            rev(x);
            x = find(n);
            y = find(n - 1);
        }
        if (x < y)
        {
            if (x == 1 && y == 2)
            {
                rev(n);
                n -= 2;
                continue;
            }
            if (y - x > 1)
            {
                rev(x);
                rev(y - 1);
            }
            rev(y + 1);
            x = find(n);
            y = find(n - 1);
        }
        if (x > y)
        {
            if (x == n && y == n - 1)
            {
                n -= 2;
                continue;
            }
            if (x == y + 1)
            {
                rev(x);
                rev(n);
            }
            else
            {
                cout << -1 << endl;
                return;
            }
        }
        n -= 2;
    }
    if (gsz(res) > 5 * temp / 2)
    {
        cout << -1 << endl;
        return;
    }
    cout << gsz(res) << endl;
    for (auto d : res)
        cout << d << " ";
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