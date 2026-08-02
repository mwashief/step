/*
    07 March 2024
    Codeforces 1751-2000 1937 1937D
*/

#ifndef __DEBUG__
#pragma GCC optimize("Ofast")
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
#define MOD 1000000007 // 998244353
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

class Pinball
{
public:
    string s;
    int n;
    vi lt, gt;
    vl prel, preg;
    Pinball(string s, int n) : s{s}, n{n}
    {
        rep(i, n) if (s[i] == '<') lt.pb(i);
        else gt.pb(i);

        prel = {0};
        preg = {0};
        for (auto l : lt)
            prel.pb(prel.back() + l);
        for (auto g : gt)
            preg.pb(preg.back() + g);
    }

    ll getTime(int index)
    {
        int bouncesFromBack = lower_bound(a2z(gt), index) - gt.begin();
        int indexInG = bouncesFromBack;
        int indexInL = int(lower_bound(a2z(lt), index) - lt.begin());
        int bouncesFromFront = gsz(lt) - indexInL;

        bool sameDirExit = true;
        ll res = n - index;
        if (bouncesFromFront > bouncesFromBack)
        {
            sameDirExit = false;
            res = index + 1;
            bouncesFromFront = bouncesFromBack + 1;
        }
        else
            bouncesFromBack = bouncesFromFront;

        res += 2LL * bouncesFromBack * index - 2LL * (preg[indexInG] - preg[indexInG - bouncesFromBack]);
        res += 2LL * (prel[indexInL + bouncesFromFront] - prel[indexInL]) - 2LL * bouncesFromFront * index;

        return res;
    }
};

inline void __run_test()
{
    int n;
    cin >> n;
    string s, t;
    cin >> s;
    t = s;
    reverse(a2z(t));
    rep(i, n) t[i] = (t[i] == '<' ? '>' : '<');

    Pinball a(s, n), b(t, n);

    rep(i, n)
    {
        char ch = s[i];
        int sameDirReflections = 0;
        int oppositeDirReflections = 0;
        ll val = 0;

        if (ch == '<')
            val = b.getTime(n - 1 - i);
        else
            val = a.getTime(i);
        cout << val << " ";
    }

    cout << endl;
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
    int __tests;
    cin >> __tests;
    while (__tests--)
        __run_test();
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