/*
    Washief Hossain Mugdho
    07 January 2021
    Codeforces 1407C
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
int n;
vi ans;
void traverse(int now, int previous)
{
    if (now > n)
    {
        ans[previous - 1] = n;
        return;
    }
    int a;
    int b;
    cout << "? " << now << " " << previous << endl;
    cout.flush();
    cin >> a;
    cout << "? " << previous << " " << now << endl;
    cout.flush();
    cin >> b;
    if (a > b)
    {
        ans[now - 1] = a;
        return traverse(now + 1, previous);
    }
    ans[previous - 1] = b;
    traverse(now + 1, now);
}

int main()
{
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif

    cin >> n;
    if (n == 1)
    {
        cout << "! 1" << endl;
        cout.flush();
        return 0;
    }
    ans = vi(n);
    traverse(2, 1);
    cout << "!";
    rep(i, n) cout << " " << ans[i];
    cout << endl;
    cout.flush();
}
