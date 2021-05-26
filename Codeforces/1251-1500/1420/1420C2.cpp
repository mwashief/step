/*
    Washief Hossain Mugdho
    13 May 2021
    Codeforces 1420 1420C2
*/

#ifndef DEBUG
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")
#endif

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define pyes cout << "YES"
#define pno cout << "NO"
#define fastio ios_base::sync_with_stdio(0)
#define untie cin.tie(0)
#define rep(i, n) for (int i = 0; i < (n); (i)++)
#define repe(i, n) for (int i = 1; i <= (n); (i)++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; (i)--)
#define rrepe(i, n) for (int i = (n); i > 0; (i)--)
#define ms(a, b) memset(a, b, sizeof a)
#define a2z(x) (x).begin(), (x).end()
#define z2a(x) (x).rbegin(), (x).rend()
#define endl "\n"
#define gsz(v) ((int)(v).size())
#define MOD 1000000007
#define MAX 1000005

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<ll>;
using vvb = vector<vector<bool>>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vpii = vector<pair<int, int>>;
using mii = map<int, int>;
using umii = unordered_map<int, int>;
using seti = set<int>;
using useti = unordered_set<int>;

inline void _()
{
    int n, q;
    cin >> n >> q;
    vi a(n);
    rep(i, n) cin >> a[i];

    auto getVal = [&](int ind)
    {
        if (ind < 0 || ind >= n)
            return 0;
        if (n == 1)
            return a[0];
        if (ind == 0)
        {
            if (a[0] > a[1])
                return a[0];
            return 0;
        }
        if (ind == n - 1)
        {
            if (a[n - 1] > a[n - 2])
                return a[n - 1];
            return 0;
        }
        if (a[ind] > a[ind - 1] && a[ind] >= a[ind + 1])
            return a[ind];
        if (a[ind] <= a[ind - 1] && a[ind] < a[ind + 1])
            return -a[ind];
        return 0;
    };
    ll ans = 0;
    rep(i, n) ans += getVal(i);
    cout << ans << endl;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        if (r - l > 3)
        {
            ans -= getVal(l) + getVal(r) + getVal(l - 1) + getVal(r - 1) + getVal(l + 1) + getVal(r + 1);
            swap(a[l], a[r]);
            ans += getVal(l) + getVal(r) + getVal(l - 1) + getVal(r - 1) + getVal(l + 1) + getVal(r + 1);
        }
        else
        {
            for (int i = l - 1; i <= r + 1; i++)
                ans -= getVal(i);
            swap(a[l], a[r]);
            for (int i = l - 1; i <= r + 1; i++)
                ans += getVal(i);
        }

        cout << ans << endl;
    }
}

int main()
{
    fastio;
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif

    int __;
    cin >> __;
    while (__--)
        _();
}
