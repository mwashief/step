/*
    Washief Hossain Mugdho
    24 October 2021
    Codeforces 1567D
*/

#ifndef __DEBUG__
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
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
#define MOD 1000000007 //998244353
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

ll br(ll num, ll slot)
{
    if (slot == 1LL)
    {
        cout << num << " ";
        return 0LL;
    }
    if (num <= slot)
    {
        rep(i, num) cout << 1 << " ";
        return slot - num;
    }
    ll per = num / 10LL;
    if (slot <= 10LL)
    {
        rep(i, slot - 1) cout << per << " ";
        cout << per * (10LL - slot + 1) << " ";
        return 0;
    }
    slot -= 10;
    rep(i, 10) slot = br(per, slot + 1LL);
    return 0LL;
}

inline void __run_test()
{
    ll s, n;
    cin >> s >> n;
    ll temp = s, sum = 0LL;
    vl digits;
    while (temp && n)
    {
        ll d = temp % 10LL;
        sum += d;
        digits.pb(d);
        temp /= 10LL;
    }

    auto print = [&](ll slots)
    {
        if (slots == 0)
            return;
        slots--;
        ll power = 1LL;
        for (int i = 0; i < gsz(digits) && slots; i++, power *= 10LL)
        {
            ll take = min(slots, digits[i]);
            rep(j, take) cout << power << " ";
            s -= take * power;
            slots -= take;
        }
        cout << s;
    };

    if (n <= sum)
    {
        print(n);
        cout << endl;
        return;
    }

    ll power = 1LL;
    ll rem = n - sum;
    rep(i, gsz(digits))
    {
        while (digits[i] && rem)
        {
            rem = br(power, rem + 1);
            digits[i]--;
            sum--;
            s -= power;
        }
        power *= 10LL;
    }

    print(sum);
    cout << endl;
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
*/