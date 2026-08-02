/*
    Washief Hossain Mugdho
    21 December 2021
    Codeforces 1501-1750 1618 1618F
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

bool check(vb a, vb b)
{
    if (gsz(a) > gsz(b))
        return false;
    int za = -1, zb = -1;
    rep(i, gsz(a)) if (!a[i])
    {
        za = i;
        break;
    }
    rep(i, gsz(b)) if (!b[i])
    {
        zb = i;
        break;
    }

    if (za == -1 && zb == -1)
        return true;
    if (za == -1 || zb == -1)
        return false;
    if (za > zb)
        return false;
    reverse(a2z(a));
    while (za < zb)
    {
        a.pb(true);
        za++;
    }
    reverse(a2z(a));
    while (gsz(a) < gsz(b))
        a.pb(true);
    rep(i, gsz(a)) if (a[i] != b[i]) return false;
    return true;
}

bool getRes(vb a, vb b)
{
    if (check(a, b))
        return true;
    reverse(a2z(a));
    return check(a, b);
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
    ll x, y;
    cin >> x >> y;
    if (x == y)
    {
        pyes << endl;
        return 0;
    }

    if (!(y & 1LL))
    {
        pno << endl;
        return 0;
    }
    vb b;
    while (y)
    {
        b.pb(y & 1LL);
        y >>= 1;
    }
    reverse(a2z(b));

    vb a;
    ll temp = x;
    while (!(temp & 1LL))
        temp >>= 1;
    while (temp)
    {
        a.pb(temp & 1LL);
        temp >>= 1;
    }
    if (getRes(a, b))
    {
        pyes << endl;
        return 0;
    }

    if (!(x & 1LL))
    {
        temp = (x << 1) | 1LL;
        a.clear();
        while (temp)
        {
            a.pb(temp & 1LL);
            temp >>= 1;
        }
        if (getRes(a, b))
        {
            pyes << endl;
            return 0;
        }
    }
    pno << endl;
}

/*
-> Check for data types
-> Fix macro
-> Run test case
-> Check the copied part
-> Set or multiset?
-> Check statement order
*/