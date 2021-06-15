/*
    Washief Hossain Mugdho
    14 June 2021
    Codeforces 1501-1750 1534 1534E
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
    int d = MAX;
    for (int i = 0; i <= n * 250; i++)
        if ((n + 2 * i) % k == 0 && ((i + n - 1) / n) * 2 + 1 <= (n + 2 * i) / k)
        {
            d = i;
            break;
        }
    if (d == MAX)
    {
        cout << -1 << endl;
        return 0;
    }
    multiset<pii> s;
    repe(i, n) s.insert({1, i});
    rep(i, d)
    {
        auto x = *s.begin();
        s.erase(s.begin());
        x.fr += 2;
        s.insert(x);
    }
    int res = 0;
    while (!s.empty())
    {
        vpii temp;
        cout << "?";
        rep(i, k)
        {
            auto x = *s.rbegin();
            s.erase(s.find(x));
            cout << " " << x.sc;
            x.fr--;
            if (x.fr)
                temp.pb(x);
        }
        cout << endl;
        int t;
        cin >> t;
        res ^= t;
        for (auto x : temp)
            s.insert(x);
    }
    cout << "!" << endl
         << res << endl;
}