/*
    Washief Hossain Mugdho
    29 January 2022
    Codeforces 1501-1750 1631 1631D
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
    vi a(n + 1);
    vi b(n);
    rep(i, n)
    {
        cin >> b[i];
        a[b[i]]++;
    }
    repe(i, n) a[i] += a[i - 1];
    int res = n - 1;
    int p = 1, q = n;
    repe(i, n)
    {
        int l = i, r = n + 1;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (2 * a[mid] - 2 * a[i - 1] - n >= k)
                r = mid;
            else
                l = mid + 1;
        }
        if (l != n + 1 && l - i < res)
        {
            res = l - i;
            p = i;
            q = l;
        }
    }
    cout << p << " " << q << endl;
    int start = 0;
    while (k > 1)
    {
        int in = 0;
        int out = 0;
        int j;
        for (int i = start; i < n; i++)
        {
            if (b[i] >= p && b[i] <= q)
                in++;
            else
                out++;
            if (in > out)
            {
                j = i;
                break;
            }
        }
        cout << start + 1 << " " << j + 1 << endl;
        start = j + 1;
        k--;
    }
    cout << start + 1 << " " << n << endl;
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