/*
    Washief Hossain Mugdho
    12 August 2021
    Codeforces 1251-1500 1427 1427D
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
    vi a(n + 1);
    repe(i, n) cin >> a[i];

    auto check = [&]() -> bool
    {
        repe(i, n) if (a[i] != i) return false;
        return true;
    };

    vvi res;
    bool leftSide = n & 1;
    int fixed = 0;
    while (!check())
    {
        res.pb(vi());
        if (!leftSide)
        {
            repe(i, fixed) res.back().pb(1);

            int index = 0;
            repe(i, n) if (a[i] == fixed + 1)
            {
                index = i;
                break;
            }
            res.back().pb(index - fixed);
            if (index != n)
                res.back().pb(n - index);

            vi b;
            b.pb(0);
            for (int i = index + 1; i <= n; i++)
                b.pb(a[i]);
            for (int i = fixed + 1; i <= index; i++)
                b.pb(a[i]);
            for (int i = fixed; i >= 1; i--)
                b.pb(a[i]);
            a = b;
        }
        else
        {
            int index = 0;
            repe(i, n) if (a[i] == fixed + 1)
            {
                index = i;
                break;
            }
            if (index != 1)
                res.back().pb(index - 1);
            res.back().pb(n - fixed - index + 1);
            rep(i, fixed) res.back().pb(1);

            vi b;
            b.pb(0);

            for (int i = 0; i < fixed; i++)
                b.pb(a[n - i]);
            for (int i = index; i <= n - fixed; i++)
                b.pb(a[i]);
            for (int i = 1; i < index; i++)
                b.pb(a[i]);
            a = b;
        }
        if (res.back().size() == 1)
            res.pop_back();

        leftSide = true ^ leftSide;
        fixed++;
    }
    cout << res.size() << endl;
    for (vi &x : res)
    {
        cout << x.size();
        for (auto y : x)
            cout << " " << y;
        cout << endl;
    }
}