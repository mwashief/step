/*
    Washief Hossain Mugdho
    14 January 2022
    Codeforces 1251-1500 1358 1358D
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
    ll n, x;
    cin >> n >> x;
    vl a(n);
    vl pc(n + 1), pv(n + 1);
    rep(i, n)
    {
        ll y;
        cin >> y;
        a[i] = y;
        pc[i + 1] += pc[i] + y;
        pv[i + 1] += pv[i] + ((y * (y + 1)) >> 1);
    }

    auto series = [](ll p, ll q) -> ll
    {
        return ((p + q) * (q - p + 1)) >> 1;
    };

    auto getCount = [&](int l, int r) -> ll
    {
        if (r >= l)
            return pc[r + 1] - pc[l];
        return pc[r + 1] + pc.back() - pc[l];
    };

    auto getValue = [&](int l, int r) -> ll
    {
        if (r >= l)
            return pv[r + 1] - pv[l];
        return pv[r + 1] + pv.back() - pv[l];
    };
    ll res = 0LL;
    rep(i, n)
    {
        if (a[i] >= x)
            res = max(res, series(a[i] - x + 1LL, a[i]));
        else
        {
            //start here
            int l = i;
            int r = (i + n - 1) % n;
            while (l != r)
            {
                int gap = (r - l + n) % n;
                int mid = (l + gap / 2 + 1) % n;
                if (getCount(i, mid) <= x)
                    l = mid;
                else
                    r = (mid + n - 1) % n;
            }
            ll val = getValue(i, l);
            ll cou = getCount(i, l);
            ll extra = x - cou;
            if (extra)
                val += series(1, extra);
            res = max(res, val);

            //end here
            r = i;
            l = (i + 1) % n;
            while (l != r)
            {
                int gap = (r - l + n) % n;
                int mid = (l + gap / 2) % n;
                if (getCount(mid, i) <= x)
                    r = mid;
                else
                    l = (mid + 1) % n;
            }
            val = getValue(l, i);
            cou = getCount(l, i);
            extra = x - cou;
            if (extra)
                val += series(a[(l + n - 1) % n] - extra + 1, a[(l + n - 1) % n]);
            res = max(res, val);
        }
    }
    cout << res << endl;
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