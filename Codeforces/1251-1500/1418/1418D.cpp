/*
    Washief Hossain Mugdho
    25 April 2021
    Codeforces 1418 1418D
*/

#ifndef DEBUG
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")
#endif

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define pyes cout << "YES"
#define pno cout << "NO"
#define fastio ios_base::sync_with_stdio(0)
#define untie cin.tie(0)
#define rep(i, n) for (int i = 0; i < (n); (i)++)
#define repe(i, n) for (int i = 1; i <= (n); (i)++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; (i)--)
#define rrepe(i, n) for (int i = (n); i > 0; (i)--)
#define ms(a, b) memset(a, b, sizeof a)
#define a2z(x) (x).begin(), (x).end()
#define z2a(x) (x).rbegin(), (x).rend()
#define endl "\n"
#define gsz(v) ((int)(v).size())
#define MOD 1000000007
#define MAX 1000005

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
using umii = unordered_map<int, int>;
using seti = set<int>;
using useti = unordered_set<int>;

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

    int n, q;
    cin >> n >> q;
    vi arr(n);
    rep(i, n) cin >> arr[i];
    sort(a2z(arr));
    seti inc;
    set<int, greater<int>> dec;
    multiset<int, greater<int>> gaps;
    gaps.insert(0);
    repe(i, n - 1)
    {
        inc.insert(arr[i]);
        dec.insert(arr[i]);
        gaps.insert(arr[i] - arr[i - 1]);
    }
    inc.insert(arr[0]);
    dec.insert(arr[0]);
    cout << *inc.rbegin() - *inc.begin() - *gaps.begin() << endl;
    rep(qq, q)
    {
        int t, x;
        cin >> t >> x;
        auto a = inc.upper_bound(x);
        auto b = dec.upper_bound(x);
        if (t)
        {
            if (inc.size() == 0)
            {
            }
            else if (a == inc.end())
            {
                int g = x - *inc.rbegin();
                gaps.insert(g);
            }
            else if (b == dec.end())
            {
                int g = *dec.rbegin() - x;
                gaps.insert(g);
            }
            else
            {
                int pre = *a - *b;
                auto preIt = gaps.find(pre);
                gaps.erase(preIt);
                gaps.insert(*a - x);
                gaps.insert(x - *b);
            }
            inc.insert(x);
            dec.insert(x);
        }
        else
        {
            if (dec.size() == 1)
            {
            }
            else if (a == inc.end())
            {
                auto g = gaps.find(x - *b);
                gaps.erase(g);
            }
            else if (b == dec.end())
            {
                auto g = gaps.find(*a - x);
                gaps.erase(g);
            }
            else
            {
                auto preIt1 = gaps.find(*a - x);
                gaps.erase(preIt1);
                auto preIt2 = gaps.find(x - *b);
                gaps.erase(preIt2);
                gaps.insert(*a - *b);
            }
            inc.erase(x);
            dec.erase(x);
        }
        int res = 0;
        if (inc.size())
            res = *inc.rbegin() - *inc.begin() - *gaps.begin();
        cout << res << endl;
    }
}
