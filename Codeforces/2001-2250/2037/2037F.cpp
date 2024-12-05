/*
    04 December 2024
    Codeforces 2001-2250 2037 2037F
*/

// https://codeforces.com/problemset/problem/2037/F

#undef __INTERACTIVE__

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define pyes cout << "YES" //"Yes"
#define pno cout << "NO"   //"No"
#define fastio ios_base::sync_with_stdio(0)
#define untie cin.tie(0)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repe(i, n) for (int i = 1; i <= (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define rrepe(i, n) for (int i = (n); i > 0; i--)
#define ms(a, b) memset(a, b, sizeof a)
#define a2z(x) (x).begin(), (x).end()
#define z2a(x) (x).rbegin(), (x).rend()
#define gsz(v) ((int)(v).size())
#define MOD 1000000007 // 998244353
#define MAX 1000005

#if !defined(__INTERACTIVE__) && !defined(__DEBUG__)
#define endl "\n"
#endif

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

using pii = pair<int, int>;
using pll = pair<ll, ll>;

using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<ll>;
using vpii = vector<pair<int, int>>;

using vvb = vector<vector<bool>>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vvpii = vector<vector<pair<int, int>>>;

using mii = map<int, int>;
using umii = unordered_map<int, int>;
using seti = set<int>;
using useti = unordered_set<int>;

inline void __run_test()
{
    int n, m, k;
    cin >> n >> m >> k;
    vi h(n), x(n);

    rep(i, n) cin >> h[i];
    rep(i, n) cin >> x[i];

    auto isPossible = [&](int stomps) -> bool
    {
        vi xs = x;
        rep(i, n)
        {
            int pos = x[i];

            int minimumHealthReducePerStomp = (h[i] + stomps - 1) / stomps;
            int maximumDistFromP = m - minimumHealthReducePerStomp;
            if (maximumDistFromP < 0)
                continue;

            xs.pb(max(x[0], pos - maximumDistFromP));
            xs.pb(min(x.back(), pos + maximumDistFromP));
        }

        sort(a2z(xs));
        xs.erase(unique(a2z(xs)), xs.end());

        vi cnt(xs.size());
        rep(i, n)
        {
            int pos = x[i];

            int minimumHealthReducePerStomp = (h[i] + stomps - 1) / stomps;
            int maximumDistFromP = m - minimumHealthReducePerStomp;
            if (maximumDistFromP < 0)
                continue;

            int l = lower_bound(a2z(xs), max(x[0], pos - maximumDistFromP)) - xs.begin();
            int r = lower_bound(a2z(xs), min(x.back(), pos + maximumDistFromP)) - xs.begin();

            cnt[r]++;
            if (l != 0)
                cnt[l - 1]--;
        }

        rrep(i, cnt.size() - 1) cnt[i] += cnt[i + 1];

        return *max_element(a2z(cnt)) >= k;
    };

    isPossible(6969697);

    int l = 1, r = MOD;

    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (isPossible(mid))
            r = mid;
        else
            l = mid + 1;
    }

    if (l == MOD)
        l = -1;

    cout << l << endl;
}

int main()
{
    fastio;
#if !defined(__INTERACTIVE__) && !defined(__DEBUG__)
    untie;
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
#endif
    int __tests;
    cin >> __tests;
    while (__tests--)
        __run_test();
}

/*
-> Check for data types
-> Fix macro
-> Run test case
-> Check the copied part
-> Set or multiset?
-> Check statement order
-> Check simple logic errors
-> Read problem statements carefully
*/
