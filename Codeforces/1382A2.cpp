/*
    Washief Hossain Mugdho
    03 January 2021
    Codeforces 1382A2
*/

#ifndef DEBUG
#pragma GCC optimize("O2")
#endif

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define fastio ios_base::sync_with_stdio(0)
#define untie cin.tie(0)
#define rep(i, n) for (int i = 0; i < n; i++)
#define repe(i, n) for (int i = 1; i <= n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
#define rrepe(i, n) for (int i = n; i > 0; i--)
#define ms(a, b) memset(a, b, sizeof a)
#define MOD 1000000007

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

/***********IO Utility**************/
template <typename... ArgTypes>
void print(ArgTypes... args);
template <typename... ArgTypes>
void input(ArgTypes &... args);
template <>
void print() {}
template <>
void input() {}
template <typename T, typename... ArgTypes>
void print(T t, ArgTypes... args)
{
    cout << t;
    print(args...);
}
template <typename T, typename... ArgTypes>
void input(T &t, ArgTypes &... args)
{
    cin >> t;
    input(args...);
}

inline void run_tests()
{
    int n;
    string s1, s2;
    cin >> n >> s1 >> s2;
    vb a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        a[i] = s1[i] - '0';
        b[i] = s2[i] - '0';
    }
    vi res;
    int l = 0;
    int r = n - 1;
    bool reversed = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[r] ^ reversed == b[i])
        {
            if (l < r)
                r--;
            else
                r++;
            continue;
        }
        if (a[l] ^ reversed == b[i])
            res.pb(1);
        res.pb(i + 1);
        int temp = l;
        l = r;
        r = temp;
        if (l < r)
            r--;
        else
            r++;
        reversed ^= 1;
    }
    cout << res.size();
    for (auto x : res)
        cout << " " << x;
    cout << endl;
}

int main()
{
    fastio;
    untie;
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif

    int tc;
    cin >> tc;
    while (tc--)
        run_tests();
}
