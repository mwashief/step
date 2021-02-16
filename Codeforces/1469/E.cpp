/*
    Washief Hossain Mugdho
    29 December 2020
    Edu101 E
*/

#ifndef DEBUG
#pragma GCC optimize("O2")
#endif

#include <bits/stdc++.h>
#include <random>
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

set<pii> S;
int n, k;
string s;
int base1 = 2, base2 = 3, bpk1, bpk2;
int mod1 = 1000000007, mod2 = 1000001021;

inline string incStr(string s)
{
    rrep(i, s.size()) if (s[i] == '0')
    {
        s[i] = '1';
        return s;
    }
    else s[i] = '0';
    return "";
}

int calcPow(int a, int p, int m)
{
    int ans = 1;
    while (p != 0)
    {
        if (p & 1)
            ans = (ll)((ll)ans * (ll)a) % m;
        a = (ll)((ll)a * (ll)a) % m;
        p >>= 1;
    }
    return ans;
}

pii getHash(string subStr)
{
    pii ans = {0, 0};
    rep(i, subStr.size())
    {
        ans.fr = (ll)((ll)ans.fr * (ll)base1) % mod1;
        ans.sc = (ll)((ll)ans.sc * (ll)base2) % mod2;
        if (subStr[i] == '1')
        {
            ans.fr = (ans.fr + 1) % mod1;
            ans.sc = (ans.sc + 1) % mod2;
        }
    }
    return ans;
}

void initList()
{
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    base1 = 889 + uniform_int_distribution<int>(0, 100000)(rng);
    base2 = 641 + uniform_int_distribution<int>(0, 100001)(rng);
    S.clear();
    bpk1 = calcPow(base1, k - 1, mod1);
    bpk2 = calcPow(base2, k - 1, mod2);
    pii last = getHash(s.substr(0, k));
    S.insert(last);
    for (int i = 1; i < n - k + 1; i++)
    {
        if (s[i - 1] == '1')
        {
            last.fr = (last.fr - bpk1 + mod1) % mod1;
            last.sc = (last.sc - bpk2 + mod2) % mod2;
        }
        last.fr = (ll)((ll)last.fr * (ll)base1) % mod1;
        last.sc = (ll)((ll)last.sc * (ll)base2) % mod2;
        if (s[i + k - 1] == '1')
        {
            last.fr = (last.fr + 1) % mod1;
            last.sc = (last.sc + 1) % mod2;
        }
        S.insert(last);
    }
}

inline void run_tests()
{
    cin >> n >> k >> s;
    rep(i, s.size()) if (s[i] == '0') s[i] = '1';
    else s[i] = '0';
    initList();
    string temp(k, '0');
    while (S.find(getHash(temp)) != S.end() && temp != "")
        temp = incStr(temp);
    if (temp == "")
        cout << "NO" << endl;
    else
    {
        cout << "YES" << endl
             << temp << endl;
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
