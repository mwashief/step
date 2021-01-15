/*
    Washief Hossain Mugdho
    14 January 2021
    Edu102 D
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
int n, m;
string s;
vi h;
vi l;
vi c;

inline void run_tests()
{
    int n, m;
    string s;
    cin >> n >> m;
    vi hprefix(n + 2, 0);
    vi lprefix(n + 2, 0);
    vi cprefix(n + 2, 0);
    vi hsuffix(n + 2, 0);
    vi lsuffix(n + 2, 0);
    cin >> s;
    rep(i, s.size())
    {
        if (s[i] == '-')
            cprefix[i + 1] = cprefix[i] - 1;
        else
            cprefix[i + 1] = cprefix[i] + 1;
        hprefix[i + 1] = max(hprefix[i], cprefix[i + 1]);
        lprefix[i + 1] = min(lprefix[i], cprefix[i + 1]);
    }
    rrep(i, s.size())
    {
        int pos;
        if (s[i] == '-')
        {
            pos = -1;
            lsuffix[i + 1] = -1;
        }
        else
        {
            pos = 1;
            hsuffix[i + 1] = 1;
        }

        hsuffix[i + 1] = max(hsuffix[i + 1], pos + hsuffix[i + 2]);
        lsuffix[i + 1] = min(lsuffix[i + 1], pos + lsuffix[i + 2]);
    }
    rep(i, m)
    {
        int x, y;
        cin >> x >> y;
        int ll = min(lprefix[x - 1], cprefix[x - 1] + lsuffix[y + 1]);
        int hh = max(hprefix[x - 1], cprefix[x - 1] + hsuffix[y + 1]);
        cout << hh - ll + 1 << endl;
    }
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
