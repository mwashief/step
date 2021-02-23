/*
    Washief Hossain Mugdho
    23 February 2021
    1492 1492D
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

int main()
{
    fastio;
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif

    int a, b, k, n;
    cin >> a >> b >> k;
    vb aa(a + b), bb(a + b);
    n = a + b;
    aa[0] = 1;
    bb[0] = 1;
    b--;
    if (k)
    {
        if (k + 1 >= n || b == 0)
        {
            cout << "No" << endl;
            return 0;
        }
        aa[1] = 1;
        bb[k + 1] = 1;
        b--;
        for (int i = 2; i < n && b; i++)
            if (i != k + 1)
            {
                aa[i] = bb[i] = 1;
                b--;
            }
    }
    else
    {
        for (int i = 1; i < n && b; i++)
        {
            aa[i] = bb[i] = 1;
            b--;
        }
    }

    if (b)
    {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    rep(i, n) cout << aa[i];
    cout << endl;
    rep(i, n) cout << bb[i];
    cout << endl;
}
