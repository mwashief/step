/*
    Washief Hossain Mugdho
    30 April 2022
    GCJ2022 Round1C C
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

bool p(string &res)
{
    vb done(26);
    int now = 0;
    while (now < gsz(res))
    {
        int ch = res[now] - 'A';
        if (done[ch])
            return false;
        int i;
        for (i = now; i < gsz(res); i++)
        {
            if (res[i] != res[now])
                break;
        }
        done[ch] = 1;
        now = i;
    }
    return true;
}

inline void __run_test(int &__test_case)
{
    cout << "Case #" << __test_case << ": ";
    int n;
    cin >> n;
    vector<string> vs(n);
    rep(i, n) cin >> vs[i];
    sort(a2z(vs));

    do
    {
        string s = "";
        rep(i, n) s.append(vs[i]);
        if (p(s))
        {
            cout << s << endl;
            return;
        }

    } while (next_permutation(a2z(vs)));

    cout << "IMPOSSIBLE" << endl;
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
    for (int __test_case = 1; __test_case <= __tests; __test_case++)
        __run_test(__test_case);
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