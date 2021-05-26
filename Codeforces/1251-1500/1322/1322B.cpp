/*
    Washief Hossain Mugdho
    25 April 2021
    Codeforces 1322 1322B
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

    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    int res = 0;
    rrep(i, 26)
    {
        int cnt = 0;
        sort(a2z(a));
        rep(j, n - 1)
        {
            int x, y;
            int l = j + 1;
            int r = n;
            while (l < r)
            {
                int mid = (l + r) >> 1;
                if (a[j] + a[mid] >= (1 << i))
                    r = mid;
                else
                    l = mid + 1;
            }
            x = l;
            l = x - 1;
            r = n - 1;
            while (l < r)
            {
                int mid = (l + r + 1) >> 1;
                if (a[j] + a[mid] < (1 << (i + 1)))
                    l = mid;
                else
                    r = mid - 1;
            }
            y = l;
            l = j + 1;
            r = n;
            while (l < r)
            {
                int mid = (l + r) >> 1;
                if (a[j] + a[mid] >= (1 << i) + (1 << (i + 1)))
                    r = mid;
                else
                    l = mid + 1;
            }
            cnt += max(0, y - x + 1) + n - l;
        }
        if (cnt & 1)
            res |= (1 << i);

        rep(j, n) a[j] = a[j] & (~(1 << i));
    }
    cout << res << endl;
}
