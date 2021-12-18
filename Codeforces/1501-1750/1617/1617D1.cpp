/*
    Washief Hossain Mugdho
    16 December 2021
    Codeforces 1501-1750 1617 1617D1
*/

#ifndef __DEBUG__
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
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
int n;
bool q(int a, int b, int c)
{
    cout << "? " << a << " " << b << " " << c << endl;
    int x;
    cin >> x;
    return !x;
}

inline void __run_test()
{
    cin >> n;
    int inno = -1;
    int impo = -1;
    for (int i = 1; i <= n - 2 && (inno == -1 || impo == -1); i += 3)
    {
        int d = q(i, i + 1, i + 2);
        if (d)
            impo = i;
        else
            inno = i;
    }
    vi res(n + 1, -1);
    vi k = {inno, inno + 1, inno + 2};
    vi z = {impo, impo + 1, impo + 2};
    int kk, zz;
    auto find = [&]() -> void
    {
        int d = q(k[0], k[1], z[0]);
        if (d)
        {
            kk = k[2];
            zz = z[0];
            res[z[0]] = 1;
            res[k[2]] = 0;
            return;
        }
        d = q(k[0], k[1], z[1]);
        if (d)
        {
            kk = k[2];
            zz = z[1];
            res[z[1]] = 1;
            res[k[2]] = 0;
            res[z[0]] = 0;
            return;
        }
        else
        {
            kk = k[0];
            res[k[0]] = 0;
            res[k[1]] = 0;
            d = q(z[0], z[1], k[0]);
            if (d)
            {
                zz = z[0];
                res[z[0]] = 1;
                res[z[1]] = 1;
            }
            else
            {
                zz = z[2];
                res[z[2]] = 1;
            }
        }
    };
    find();
    repe(i, n) if (res[i] == -1) res[i] = q(kk, zz, i);
    int sum = 0;
    repe(i, n) sum += res[i];
    cout << "! " << sum;
    repe(i, n) if (res[i]) cout << " " << i;
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
*/