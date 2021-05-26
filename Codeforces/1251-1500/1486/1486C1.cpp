/*
    Washief Hossain Mugdho
    18 February 2021
    1486 1486C1
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
int n, sMax;

int query(int l, int r)
{
    cout << "? " << l << " " << r << endl;
    int pos;
    cin >> pos;
    return pos;
}

int traverse(int l, int r, int sb)
{
    if (l == r)
        return l;
    if (sb == -1)
        sb = query(l, r);
    if (r - l == 1)
        return r + l - sb;
    if (sb == l)
    {
        int mid = (l + r) >> 1;
        int ch = query(l, mid);
        if (ch == sb)
            return traverse(l, mid, sb);
        return traverse(mid + 1, r, -1);
    }
    else if (sb == r)
    {
        int mid = (l + r) >> 1;
        int ch = query(mid, r);
        if (ch == sb)
            return traverse(mid, r, sb);
        return traverse(l, mid - 1, -1);
    }
    else
    {
        int mid = (l + r) >> 1;
        if (sb <= mid)
        {
            int ql = query(l, mid);
            if (ql == sb)
                return traverse(l, mid, sb);
            return traverse(mid + 1, r, -1);
        }
        else
        {
            int qr = query(mid, r);
            if (qr == sb)
                return traverse(mid, r, sb);
            return traverse(l, mid - 1, -1);
        }
    }
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
    cin >> n;
    int res = traverse(1, n, -1);
    cout << "! " << res << endl;
}
