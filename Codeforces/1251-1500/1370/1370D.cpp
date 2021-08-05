/*
    Washief Hossain Mugdho
    05 August 2021
    Codeforces 1251-1500 1370 1370D
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
#define MAX 1000000000

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

int subseqLen(vi &a, int val)
{
    int found = 0;
    int last = -2;
    rep(i, gsz(a)) if (a[i] <= val && i > last + 1)
    {
        found++;
        last = i;
    }
    return found;
}

int getHalfSub(vi &a, int cnt)
{
    int l = 1;
    int r = MAX;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (subseqLen(a, mid) >= cnt)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
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
    int n, k, res;
    cin >> n >> k;
    vi a(n);
    rep(i, n) cin >> a[i];
    if (k & 1)
    {
        res = getHalfSub(a, (k + 1) >> 1);
        a.pop_back();
        reverse(a2z(a));
        a.pop_back();
        res = min(res, getHalfSub(a, k >> 1));
    }
    else
    {
        int temp = a.back();
        a.pop_back();
        res = getHalfSub(a, k >> 1);
        a.pb(temp);
        reverse(a2z(a));
        a.pop_back();
        res = min(res, getHalfSub(a, k >> 1));
    }

    cout << res << endl;
}