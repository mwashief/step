/*
    Washief Hossain Mugdho
    25 December 2020
    Codeforces 642D
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
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
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
vi a;

bool Compare(pii x, pii y)
{
    if (x.fr == y.fr)
        return x.sc > y.sc;
    return x.fr < y.fr;
}

void run_tests()
{
    int n;
    cin >> n;
    a = vi(n, 0);
    priority_queue<pii, vector<pii>, function<bool(pii, pii)>> Q(Compare);
    Q.push({n, 0});
    int num = 1;
    while (!Q.empty())
    {
        int len = Q.top().fr;
        int l = Q.top().sc;
        Q.pop();
        if (len <= 0)
            continue;
        if (len == 0)
        {
            a[l] = num++;
            continue;
        }
        int mid = (2 * l + len - 1) >> 1;
        Q.push({mid - l, l});
        Q.push({l + len - 1 - mid, mid + 1});
        a[mid] = num++;
    }
    rep(i, n) cout << a[i] << " ";
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
