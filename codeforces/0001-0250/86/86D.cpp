/*
    Washief Hossain Mugdho
    22 December 2020
    Codeforces 86D
*/

#ifndef DEBUG
#pragma GCC optimize("O3")
#endif

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ull unsigned long long
#define ll long long
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define fastio ios_base::sync_with_stdio(0)
#define untie cin.tie(0)
#define ms(a, b) memset(a, b, sizeof a)
using namespace std;
using namespace __gnu_pbds;
int n, q, segSize;
ll current;
vector<int> a;
vector<int> l;
vector<int> r;
cc_hash_table<int, int, hash<int>> track;

void add(int pos)
{
    ll element = a[pos];
    ll prev = track[element];
    track[element]++;
    current += ((prev << 1LL) + 1LL) * element;
}

void erase(int pos)
{
    ll element = a[pos];
    ll prev = track[element];
    track[element]--;
    current += (1LL - (prev << 1)) * element;
}

int main()
{
    fastio;
    untie;
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    cin >> n >> q;
    a = vector<int>(n);
    l = vector<int>(q);
    r = vector<int>(q);
    vector<ll> ans(q);
    vector<int> ordering(q);
    segSize = 2 * ceil(sqrt(n));
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < q; i++)
    {
        cin >> l[i] >> r[i];
        l[i]--;
        r[i]--;
        ordering[i] = i;
    }
    sort(ordering.begin(), ordering.end(), [](int x, int y) {
        int segx = l[x] / segSize;
        int segy = l[y] / segSize;
        if (segx == segy)
            return r[x] < r[y];
        return segx < segy;
    });
    int curl = 0, curr = 0;
    current = a[0];
    track[a[0]] = 1;
    for (int i = 0; i < q; i++)
    {
        int ql = l[ordering[i]];
        int qr = r[ordering[i]];
        while (curr < qr)
        {
            curr++;
            add(curr);
        }
        while (curr > qr)
        {
            erase(curr);
            curr--;
        }
        while (curl < ql)
        {
            erase(curl);
            curl++;
        }
        while (curl > ql)
        {
            curl--;
            add(curl);
        }
        ans[ordering[i]] = current;
    }
    for (int i = 0; i < q; i++)
        cout << ans[i] << endl;
}
