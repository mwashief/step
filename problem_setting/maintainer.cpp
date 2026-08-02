/*
    Washief Hossain Mugdho
    09 November 2021
    Codeforces 1251-1500 1295 1295E
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

class Maintainer
{
    multiset<int, greater<int>> smallHalf;
    multiset<int> bigHalf;
    ll sum[2] = {0LL, 0LL};

public:
    void fix()
    {
        rep(i, 3) if (gsz(smallHalf))
        {
            auto k = *smallHalf.begin();
            smallHalf.erase(smallHalf.begin());
            sum[0] -= k;
            sum[1] += k;
            bigHalf.insert(k);
        }
        while (gsz(bigHalf) > gsz(smallHalf) + 1)
        {
            auto k = *bigHalf.begin();
            bigHalf.erase(bigHalf.begin());
            sum[0] += k;
            sum[1] -= k;
            smallHalf.insert(k);
        }
    }

    void insert(int k)
    {
        bigHalf.insert(k);
        fix();
    }

    void erase(int k)
    {
        if (smallHalf.find(k) != smallHalf.end())
        {
            smallHalf.erase(smallHalf.find(k));
            sum[0] -= k;
        }
        else
        {
            bigHalf.erase(bigHalf.find(k));
            sum[1] -= k;
        }
        fix();
    }

    ll getRes()
    {
        return sum[0];
    }
};

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
    vi p(n), a(n), pos(n);
    rep(i, n)
    {
        cin >> p[i];
        p[i]--;
        pos[p[i]] = i;
    }
    rep(i, n) cin >> a[i];

    Maintainer m;
    set<int> sets[2];

    auto insertInSet = [&](int num, int val, int s)
    {
        sets[s].insert(num);
        m.insert(val);
    };

    auto eraseFromSet = [&](int num, int val, int s)
    {
        sets[s].erase(num);
        m.erase(val);
    };

    ll res = INT64_MAX;
    rep(i, n - 1) if (p[i] != i)
    {
        if (sets[0].count(i))
            eraseFromSet(i, a[pos[i]], 0);
        else
            insertInSet(i, a[pos[i]], 1);

        if (p[i] < i)
            eraseFromSet(p[i], a[i], 1);
        else
            insertInSet(p[i], a[i], 0);
        res = min(res, m.getRes());
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
*/