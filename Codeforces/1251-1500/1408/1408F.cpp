/*
    Washief Hossain Mugdho
    22 April 2021
    Codeforces 1408 1408F
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

vpii res;

vi merge(vi &a, vi &b)
{
    vi ans;
    rep(i, a.size())
    {
        res.pb({a[i], b[i]});
        ans.pb(a[i]);
        ans.pb(b[i]);
    }
    return ans;
}

void done(vi &a, int l, int r)
{
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    done(a, l, mid);
    done(a, mid + 1, r);
    for (int i = l; i <= mid; i++)
        res.pb({a[i], a[mid + i - l + 1]});
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
    vvi all;
    int n;
    cin >> n;
    int cur = 0;
    vi a(n);
    rep(i, n) a[i] = i + 1;

    for (int i = 15; i >= 0; i--)
        if (n & (1 << i))
        {
            all.pb(vi());
            for (int j = 0; j < (1 << i); j++)
            {
                all.back().pb(a[cur]);
                cur++;
            }
        }

    for (vi &d : all)
        done(d, 0, gsz(d) - 1);

    while (gsz(all) > 2)
    {
        if (gsz(all[gsz(all) - 1]) == gsz(all[gsz(all) - 2]))
        {
            all[gsz(all) - 2] = merge(all[gsz(all) - 2], all[gsz(all) - 1]);
            all.pop_back();
        }
        else
        {
            vi temp;
            while (gsz(temp) < gsz(all.back()))
            {
                temp.pb(all[0].back());
                all[0].pop_back();
            }
            all.back() = merge(all.back(), temp);
        }
    }
    cout << gsz(res) << endl;
    for (auto d : res)
        cout << d.fr << " " << d.sc << endl;
}