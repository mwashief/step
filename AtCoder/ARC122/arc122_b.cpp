/*
    Washief Hossain Mugdho
    15 July 2021
    AtCoder ARC122 arc122_b
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
    vi a(n);
    rep(i, n) cin >> a[i];
    sort(a2z(a));
    vl sum(n + 1);
    rep(i, n) sum[i + 1] = sum[i] + (ll)a[i];
    long double ans = sum[n];
    long double temp = 1.0 * (1.0 * a[0] / 2.0 - 1e-15) * n;
    ans -= temp;
    rep(i, n)
    {
        long double x = 1.0 * a[i] / 2.0;
        long double y = x;
        if (i != n - 1)
        {
            if (a[i] == a[i + 1])
                continue;
            y = 1.0 * a[i + 1] / 2.0;
        }
        if (i + 1 < n - 1 - i)
            x = y - 1e-15;
        ans = min<long double>(ans, 1.0 * (2.0 * i + 2.0 - n) * x + sum[n] - sum[i + 1]);
    }
    cout << fixed << setprecision(15) << 1.0 * ans / n << endl;
}