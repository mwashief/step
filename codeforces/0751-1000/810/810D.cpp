/*
    Washief Hossain Mugdho
    16 January 2021
    Codeforces 810D
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
int n, k, dish1, dish2, dish3;

bool call(int a, int b)
{
    cout << "1 " << a << " " << b << endl;
    string s;
    cin >> s;
    if (s == "TAK")
        return 1;
    return 0;
}

int findDish(int l, int r)
{
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (call(mid, mid + 1))
            r = mid;
        else
            l = mid + 1;
    }
    return l;
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
    cin >> n >> k;
    dish1 = findDish(1, n);
    dish2 = findDish(1, dish1 - 1);
    dish3 = findDish(dish1 + 1, n);
    if (dish1 == 1)
    {
        cout << 2 << " " << dish1 << " " << dish3 << endl;
        return 0;
    }
    if (dish1 == n)
    {
        cout << 2 << " " << dish1 << " " << dish2 << endl;
        return 0;
    }
    dish2 = call(dish2, dish3) ? dish2 : dish3;
    cout << 2 << " " << dish1 << " " << dish2 << endl;
}
