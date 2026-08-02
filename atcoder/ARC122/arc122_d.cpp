/*
    Washief Hossain Mugdho
    16 July 2021
    AtCoder ARC122 arc122_d
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
#define MOD 2000000007 //998244353
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

ll getRes(vi &one, vi &zero, int bit)
{
    if (gsz(one) == 0 || gsz(zero) == 0)
        return (ll)INT32_MAX;
    if (bit < 0)
        return 0;
    vvi ones(2, vi());
    vvi zeros(2, vi());
    for (auto x : one)
        ones[(x & (1 << bit)) != 0].pb(x);
    for (auto x : zero)
        zeros[(x & (1 << bit)) != 0].pb(x);
    ll ans = INT32_MAX;
    rep(i, 2)
        ans = min(ans, getRes(ones[i], zeros[i], bit - 1));

    if (ans == INT32_MAX)
        rep(i, 2) ans = min(ans, (1LL << bit) + getRes(ones[i], zeros[(i + 1) % 2], bit - 1));

    return ans;
}

ll find(vi &a, int bit)
{
    if (bit < 0 || gsz(a) == 0)
        return 0;
    vi zeros;
    vi ones;
    for (auto x : a)
        if (x & (1 << bit))
            ones.pb(x);
        else
            zeros.pb(x);
    if (gsz(ones) & 1)
        return (1LL << bit) + getRes(ones, zeros, bit - 1);

    return max(find(zeros, bit - 1), find(ones, bit - 1));
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
    int n;
    cin >> n;
    n <<= 1;
    vi a(n);
    rep(i, n) cin >> a[i];
    cout << find(a, 30) << endl;
}