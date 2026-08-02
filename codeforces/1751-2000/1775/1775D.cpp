/*
    11 January 2023
    Codeforces 1751-2000 1775 1775D
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
    int n, s, t;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    cin >> s >> t;

    if (s == t)
    {
        cout << "1\n"
             << s << endl;
        return 0;
    }

    vi spf(300001);
    iota(a2z(spf), 0);
    for (int i = 2; i < 300001; i++)
        if (spf[i] == i)
        {
            for (int j = i; j < 300001; j += i)
                spf[j] = min(spf[j], i);
        }

    auto factors = [&](int num)
    {
        vi primes;
        while (num != 1)
        {
            primes.pb(spf[num]);
            num /= spf[num];
        }

        primes.erase(unique(primes.begin(), primes.end()), primes.end());
        return primes;
    };

    vvi adj(300001, vi());
    for (int num : a)
    {
        vi primes = factors(num);

        rep(i, gsz(primes)) for (int j = i + 1; j < gsz(primes); j++)
        {
            adj[primes[i]].pb(primes[j]);
            adj[primes[j]].pb(primes[i]);
        }
    }

    vi source = factors(a[s - 1]);
    vi destination = factors(a[t - 1]);
    vi dist(300001, INT32_MAX);
    vi parent(300001, -1);

    queue<int> q;
    for (auto sour : source)
    {
        dist[sour] = 0;
        q.push(sour);
    }

    while (gsz(q))
    {
        auto node = q.front();
        q.pop();

        for (auto nei : adj[node])
            if (dist[nei] > dist[node] + 1)
            {
                dist[nei] = dist[node] + 1;
                parent[nei] = node;
                q.push(nei);
            }
    }

    int last = -1;
    int dis = INT32_MAX;
    for (auto des : destination)
        if (dist[des] < dis)
        {
            dis = dist[des];
            last = des;
        }

    vi path;
    while (last != -1)
    {
        path.pb(last);
        last = parent[last];
    }

    if (gsz(path) == 0)
    {
        cout << -1 << endl;
        return 0;
    }

    reverse(a2z(path));
    cout << gsz(path) + 1 << endl;
    cout << s;
    rep(i, gsz(path) - 1)
    {
        ll k = 1LL * path[i] * path[i + 1];
        for (int j = 0; j < gsz(a); j++)
            if (((ll)a[j]) % k == 0LL)
            {
                cout << " " << j + 1;
                break;
            }
    }
    cout << " " << t << endl;
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