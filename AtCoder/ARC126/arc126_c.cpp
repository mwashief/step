/*
    Washief Hossain Mugdho
    29 September 2021
    AtCoder ARC126 arc126_c
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
    ll k;
    cin >> n >> k;
    vi a(n);
    rep(i, n) cin >> a[i];
    sort(a2z(a));
    vl prefix(n + 1);
    rep(i, n) prefix[i + 1] = prefix[i] + a[i];
    if (k >= 1LL * a.back() * n - prefix[n])
    {
        k -= 1LL * a.back() * n - prefix[n];
        cout << a.back() + k / n << endl;
        return 0;
    }

    rrep(i, a.back())
    {
        int l = 0;
        int r = n;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (a[mid] <= i)
                l = mid + 1;
            else
                r = mid;
        }
        ll behind = 1LL * i * l - prefix[l];
        if (behind > k)
            continue;
        int multiple = 0;
        while (++multiple && behind <= k)
        {
            int rangel = multiple * i;
            int ranger = rangel + i;
            rangel++;
            if (rangel > a.back())
                break;
            int indl = lower_bound(a2z(a), rangel) - a.begin();
            int indr = upper_bound(a2z(a), ranger) - a.begin() - 1;
            ll now = 1LL * (indr - indl + 1) * i * (multiple + 1) - prefix[indr + 1] + prefix[indl];
            behind += now;
        }
        if (behind <= k)
        {
            cout << i << endl;
            return 0;
        }
    }
}