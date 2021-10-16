/*
    Washief Hossain Mugdho
    16 October 2021
    Codeforces 1501-1750 1556 1556D
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

ll qand(ll a, ll b)
{
    cout << "and " << a + 1 << " " << b + 1 << endl;
    ll x;
    cin >> x;
    return x;
}

ll qor(ll a, ll b)
{
    cout << "or " << a + 1 << " " << b + 1 << endl;
    ll x;
    cin >> x;
    return x;
}

ll sum(ll o, ll a)
{
    bool carry = false;
    ll res = 0;
    rep(i, 32)
    {
        if (a & (1 << i))
        {
            if (carry)
                res |= (1 << i);
            carry = true;
        }
        else if (o & (1 << i))
        {
            if (!carry)
                res |= (1 << i);
            else
                carry = true;
        }
        else if (carry)
        {
            res |= (1 << i);
            carry = false;
        }
    }
    return res;
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

    int n, k;
    cin >> n >> k;

    ll ab = sum(qor(0, 1), qand(0, 1));
    ll bc = sum(qor(1, 2), qand(1, 2));
    ll ca = sum(qor(0, 2), qand(0, 2));
    ll abc = (ab + bc + ca) >> 1;
    ll a = abc - bc;
    ll b = abc - ca;
    ll c = abc - ab;

    vl all;
    all.pb(a);
    all.pb(b);
    all.pb(c);
    for (int i = 3; i < n; i++)
        all.pb(sum(qor(0, i), qand(0, i)) - a);
    sort(a2z(all));
    cout << "finish " << all[k - 1] << endl;
}

/*
-> Check for data types
-> Fix macro
-> Run test case
-> Check the copied part again (imp**)
-> Set or multiset?
*/