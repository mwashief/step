/*
    10 September 2023
    Codeforces 1751-2000 1869 1869D1
*/

#ifndef __DEBUG__
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#endif

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
#define rrep(i, n) for (int i = (n)-1; i >= 0; i--)
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

class Exchange
{
public:
    map<int, multiset<int>> exchange[2];

    void insert(pii a)
    {
        vi edge = {a.fr, a.sc};
        rep(side, 2) while (exchange[1 - side].find(edge[side]) != exchange[1 - side].end() && edge[1 - side] != edge[side])
        {
            auto it = exchange[1 - side][edge[side]].begin();
            int other = *it;
            exchange[1 - side][edge[side]].erase(it);
            exchange[side][other].erase(exchange[side][other].find(edge[side]));

            if (gsz(exchange[1 - side][edge[side]]) == 0)
                exchange[1 - side].erase(edge[side]);
            if (gsz(exchange[side][other]) == 0)
                exchange[side].erase(other);

            edge[side] = other;
        }

        if (edge[0] != edge[1])
        {
            exchange[1][edge[1]].insert(edge[0]);
            exchange[0][edge[0]].insert(edge[1]);
        }
    }

    bool check()
    {
        while (gsz(exchange[1]))
        {
            if (exchange[1].begin()->sc.size() == 0)
                exchange[1].erase(exchange[1].begin());
            else
                break;
        }

        if (gsz(exchange[1]) == 0)
            return true;

        int start = exchange[1].begin()->fr;
        int now = exchange[1].begin()->fr;
        while (exchange[1][now].size())
        {
            int next = *exchange[1][now].begin();
            exchange[1][now].erase(exchange[1][now].begin());
            if (next == start)
                return check();
            now = next;
        }

        return false;
    }
};

inline void __run_test()
{
    int n;
    cin >> n;
    vl a(n);
    rep(i, n) cin >> a[i];
    ll sum = accumulate(a2z(a), 0LL);
    if (sum % n)
    {
        pno << endl;
        return;
    }

    ll average = sum / (ll)n;

    Exchange e;
    rep(i, n) if (a[i] != average)
    {
        ll diff = abs(average - a[i]);
        vi bits;
        int bit = 0;
        while (diff)
        {
            if (diff & 1)
                bits.pb(bit);
            bit++;
            diff >>= 1;
        }

        if (bits.back() - bits[0] != gsz(bits) - 1)
        {
            pno << endl;
            return;
        }
        int x = bits.back() + 1;
        int y = bits[0];

        if (average > a[i])
            e.insert({x, y});
        else
            e.insert({y, x});
    }

    if (e.check())
        pyes << endl;
    else
        pno << endl;
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