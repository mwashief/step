/*
    Washief Hossain Mugdho
    15 March 2021
    Codeforces 1158 1158C
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
void input(ArgTypes &...args);
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
void input(T &t, ArgTypes &...args)
{
    cin >> t;
    input(args...);
}

vvi prevI;
vi res;
int currentVal;
int currentI;

inline void _()
{
    int n;
    cin >> n;
    prevI = vvi(n + 2);
    res = vi(n + 2, 0);
    stack<int> big;
    bool impossible = false;
    repe(i, n)
    {
        int x;
        cin >> x;
        if (x == -1)
            continue;
        prevI[x].pb(i);
        while (!big.empty() && big.top() <= i)
            big.pop();

        if (big.size() && big.top() < x)
            impossible = 1;
        else
            big.push(x);
    }
    if (impossible)
    {
        cout << -1 << endl;
        return;
    }
    currentVal = n + 1;
    currentI = n + 1;
    if (prevI[n + 1].size() == 0)
    {
        res[n + 1] = n + 1;
        currentI = n;
        currentVal = n;
    }
    for (int i = currentI; i > 0; i--)
    {
        if (res[i] || prevI[i].size() == 0)
            continue;
        queue<int> Q;
        Q.push(i);
        while (!Q.empty())
        {
            int u = Q.front();
            Q.pop();
            res[u] = currentVal;
            currentVal--;
            for (auto v : prevI[u])
                Q.push(v);
        }
    }
    repe(i, n) if (!res[i]) res[i] = currentVal--;
    repe(i, n) cout << res[i] << " ";
    cout << endl;
}

int main()
{
    fastio;
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif

    int __;
    cin >> __;
    while (__--)
        _();
}
