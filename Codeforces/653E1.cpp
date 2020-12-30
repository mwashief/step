/*
    Washief Hossain Mugdho
    30 December 2020
    Codeforces 653E1
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
    int n, k;
    cin >> n >> k;
    priority_queue<int, vector<int>, greater<int>> alice;
    priority_queue<int, vector<int>, greater<int>> bob;
    priority_queue<int, vector<int>, greater<int>> both;
    rep(i, n)
    {
        int t, a, b;
        cin >> t >> a >> b;
        if (a == 0 && b == 0)
            continue;
        if (a == 1 && b == 1)
            both.push(t);
        else if (a == 1)
            alice.push(t);
        else
            bob.push(t);
    }
    int taken = 0;
    int res = 0;
    while (taken < k)
    {
        if ((alice.size() == 0 || bob.size() == 0) && both.size() == 0)
            break;
        int a = INT32_MAX;
        int b = INT32_MAX;
        if (alice.size() != 0 && bob.size() != 0)
            a = alice.top() + bob.top();
        if (both.size())
            b = both.top();
        if (a < b)
        {
            res += a;
            alice.pop();
            bob.pop();
        }
        else
        {
            res += b;
            both.pop();
        }
        taken++;
    }
    if (taken == k)
        cout << res << endl;
    else
        cout << -1 << endl;
}
