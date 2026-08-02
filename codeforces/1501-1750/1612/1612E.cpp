/*
    Washief Hossain Mugdho
    22 November 2021
    Codeforces 1501-1750 1612 1612E
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
    vvi messages(200000);
    rep(i, n)
    {
        int m, k;
        cin >> m >> k;
        m--;
        messages[m].pb(k);
    }
    long double expected = 0;
    int take = 0;
    repe(i, 20)
    {
        vi bag;
        rep(j, 200000)
        {
            int d = 0;
            for (auto c : messages[j])
                d += min(i, c);
            bag.pb(d);
        }
        sort(a2z(bag), greater<int>());
        ll total = 0;
        rep(j, i) total += bag[j];
        long double e = 1.0 * total / i;
        if (e > expected)
        {
            expected = e;
            take = i;
        }
    }

    vpii all;
    rep(i, 200000)
    {
        int d = 0;
        for (auto c : messages[i])
            d += c;
        all.pb({d, i});
    }
    sort(a2z(all));
    reverse(a2z(all));
    ll sum = 0;
    rep(i, 20) sum += all[i].fr;
    for (int i = 20; i < 200000; i++)
    {
        sum += all[i].fr;
        long double e = 1.0 * sum / (i + 1);
        if (e > expected)
        {
            expected = e;
            take = i + 1;
        }
    }
    cout << take << endl;
    if (take <= 20)
    {
        vpii bag;
        rep(j, 200000)
        {
            int d = 0;
            for (auto c : messages[j])
                d += min(take, c);
            bag.pb({d, j});
        }
        sort(a2z(bag));
        reverse(a2z(bag));
        rep(i, take) cout << bag[i].sc + 1 << " ";
    }
    else
        rep(i, take) cout << all[i].sc + 1 << " ";
    cout << endl;
}

/*
-> Check for data types
-> Fix macro
-> Run test case
-> Check the copied part
-> Set or multiset?
-> Check statement order
*/