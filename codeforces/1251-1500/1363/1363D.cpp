/*
    Washief Hossain Mugdho
    03 February 2021
    Codeforces 1363D
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
vvi segs;
int query(int l, int r)
{
    vi all;
    for (int i = l; i <= r; i++)
        for (auto x : segs[i])
            all.pb(x);
    cout << "? " << all.size();
    for (auto x : all)
        cout << " " << x;
    cout << endl;
    int res;
    cin >> res;
    return res;
}

inline void _()
{
    int n, k;
    cin >> n >> k;
    segs = vvi(k, vi());
    rep(i, k)
    {
        int nn;
        cin >> nn;
        rep(j, nn)
        {
            int pos;
            cin >> pos;
            segs[i].pb(pos);
        }
    }
    cout << "? " << n;
    repe(i, n) cout << " " << i;
    cout << endl;
    int maxi;
    cin >> maxi;
    int l = 0, r = k - 1;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        int maxEle = query(l, mid);
        if (maxEle == maxi)
            r = mid;
        else
            l = mid + 1;
    }
    set<int> all;
    repe(j, n) all.insert(j);
    for (auto x : segs[l])
        all.erase(x);
    cout << "? " << all.size();
    for (auto x : all)
        cout << " " << x;
    cout << endl;
    int diff;
    cin >> diff;
    cout << "!";
    rep(i, k)
    {
        if (i == l)
            cout << " " << diff;
        else
            cout << " " << maxi;
    }
    cout << endl;
    string correctness;
    cin >> correctness;
    if (correctness == "Correct")
        return;
    exit(0);
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
