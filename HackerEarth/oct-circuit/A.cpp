/*
    Washief Hossain Mugdho
    20 October 2021
    HackerEarth oct-circuit A
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

pair<string, string> get(string s)
{
    reverse(a2z(s));
    return {s.substr(0, 2), s.substr(2, 2)};
}

inline void __run_test()
{
    string s;
    cin >> s;
    string day = s.substr(0, 2);
    string month = s.substr(2, 2);
    string year = s.substr(4, 4);
    auto k = get(year);
    if (k.fr >= "01" && k.fr <= "30" && k.sc >= "01" && k.sc <= "12")
    {
        if (k.sc < month)
        {
            cout << k.fr << k.sc << year << endl;
            return;
        }
        if (k.sc == month && k.fr < day)
        {
            cout << k.fr << k.sc << year << endl;
            return;
        }
    }

    int d = stoi(year);
    rrepe(i, d - 1)
    {
        auto yy = to_string(i);
        while (gsz(yy) < 4)
            yy = "0" + yy;
        k = get(yy);
        if (k.fr >= "01" && k.fr <= "30" && k.sc >= "01" && k.sc <= "12")
        {
            cout << k.fr << k.sc << yy << endl;
            return;
        }
    }

    cout << -1 << endl;
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
-> Check the copied part again (imp**)
-> Set or multiset?
*/