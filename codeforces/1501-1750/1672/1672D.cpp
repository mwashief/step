/*
    Washief Hossain Mugdho
    24 April 2022
    Codeforces 1501-1750 1672 1672D
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

void read(vpii &a, int n)
{
    rep(i, n)
    {
        int x;
        cin >> x;
        if (gsz(a) == 0)
            a.pb({x, 1});
        else if (a.back().fr == x)
            a.back().sc++;
        else
            a.pb({x, 1});
    }
}

inline void __run_test()
{
    int n;
    cin >> n;
    vpii a, b;
    read(a, n);
    read(b, n);
    if (gsz(b) > gsz(a))
    {
        pno << endl;
        return;
    }
    vi borrow(n + 1);
    for (int i = gsz(b) - 1; i >= 0; i--)
    {
        while (gsz(a) > 0 && a.back().fr != b.back().fr)
        {
            if (borrow[a.back().fr] >= a.back().sc)
            {
                borrow[a.back().fr] -= a.back().sc;
                a.pop_back();
            }
            else
            {
                pno << endl;
                return;
            }
        }

        if (gsz(a) == 0)
        {
            pno << endl;
            return;
        }

        int prev = min(a.back().sc - 1, borrow[a.back().fr]);
        borrow[a.back().fr] -= prev;
        a.back().sc -= prev;

        if (a.back().sc > b.back().sc)
        {
            pno << endl;
            return;
        }

        borrow[a.back().fr] += b.back().sc - a.back().sc;
        a.pop_back();
        b.pop_back();
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