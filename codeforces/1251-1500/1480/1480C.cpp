/*
    Washief Hossain Mugdho
    13 February 2021
    Codeforces 1480C
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
int n;
vi arr;
int query(int a, int b, int c)
{
    if (!arr[a])
    {
        cout << "? " << a << endl;
        cin >> arr[a];
    }
    if (!arr[b])
    {
        cout << "? " << b << endl;
        cin >> arr[b];
    }
    if (!arr[c])
    {
        cout << "? " << c << endl;
        cin >> arr[c];
    }
    if (arr[a] < arr[b] && arr[b] < arr[c])
        return 1;
    if (arr[a] > arr[b] && arr[b] > arr[c])
        return 2;
    if (arr[a] < arr[b] && arr[b] > arr[c])
        return 3;
    if (arr[a] > arr[b] && arr[c] > arr[b])
        return 4;
    return 3;
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
    if (n < 3)
    {
        for (int i = 1; i <= n; i++)
        {
            int x;
            cout << "? " << i << endl;
            cin >> x;
            if (x == 1)
            {
                cout << "! " << i << endl;
                return 0;
            }
        }
    }
    arr = vi(n + 1);
    int l = 1, r = n;
    while (r - l > 2)
    {
        int mid = (r + l) >> 1;
        int res = query(mid - 1, mid, mid + 1);
        if (res == 4)
        {
            cout << "! " << mid << endl;
            return 0;
        }
        if (res & 1)
            r = mid;
        else
            l = mid;
    }
    int res = query(l, l + 1, l + 2);
    if (res == 4)
        cout << "! " << l + 1 << endl;
    else if (res & 1)
        cout << "! " << l << endl;
    else
        cout << "! " << l + 2 << endl;
}
