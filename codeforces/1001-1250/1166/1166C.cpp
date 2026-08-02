/*
    Washief Hossain Mugdho
    21 October 2021
    Codeforces 1001-1250 1166 1166C
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
    vi neg, pos;
    rep(i, n)
    {
        int x;
        cin >> x;
        if (x < 0)
            neg.pb(x);
        else
            pos.pb(x);
    }
    sort(a2z(neg), greater<int>());
    sort(a2z(pos));

    ll res = 0;
    rep(i, gsz(neg))
    {
        int l = i;
        int r = gsz(neg) - 1;
        while (l < r)
        {
            int mid = (l + r + 1) >> 1;
            if ((neg[i] << 1) <= neg[mid])
                l = mid;
            else
                r = mid - 1;
        }
        res += l - i;

        l = lower_bound(a2z(pos), (-neg[i] + 1) / 2) - pos.begin();
        r = lower_bound(a2z(pos), -2 * neg[i] + 1) - pos.begin() - 1;
        res += r - l + 1;
    }

    rep(i, gsz(pos))
    {
        int l = i;
        int r = gsz(pos) - 1;
        while (l < r)
        {
            int mid = (l + r + 1) >> 1;
            if (pos[mid] <= (pos[i] << 1))
                l = mid;
            else
                r = mid - 1;
        }
        res += l - i;
    }
    cout << res << endl;
}

/*
-> Check for data types
-> Fix macro
-> Run test case
-> Check the copied part again (imp**)
-> Set or multiset?
*/
