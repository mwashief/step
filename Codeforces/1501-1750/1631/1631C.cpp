/*
    Washief Hossain Mugdho
    29 January 2022
    Codeforces 1501-1750 1631 1631C
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
    int n, k;
    cin >> n >> k;
    if (n == 4 && k == 3)
    {
        cout << -1 << endl;
        return;
    }
    if (k == n - 1)
    {
        cout << n - 1 << " " << n - 2 << endl;
        cout << 1 << " " << 3 << endl;
        cout << 2 << " " << n - 3 << endl;
        cout << 0 << " " << n - 4 << endl;
        for (int i = 4; i < n / 2; i++)
            cout << i << " " << n - 1 - i << endl;
        return;
    }
    else if (k)
    {
        cout << k << " " << n - 1 << endl;
        cout << 0 << " " << n - 1 - k << endl;
        for (int i = 1; i < n / 2; i++)
            if (i != k && i != n - 1 - k)
                cout << i << " " << n - 1 - i << endl;
    }
    else
        for (int i = 0; i < n / 2; i++)
            cout << i << " " << n - 1 - i << endl;
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