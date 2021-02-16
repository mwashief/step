/*
    Washief Hossain Mugdho
    08 December 2020
    Codeforces 1454D
*/

#ifndef DEBUG
#pragma GCC optimize("O3")
#endif

#include <bits/stdc++.h>
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
bool isPrime[100005];

void sieve()
{
    isPrime[2] = 1;
    for (int i = 3; i < 100005; i++)
        isPrime[i] = i % 2;
    for (int i = 3; i < 100005; i += 2)
        if (isPrime[i])
        {
            for (int j = i * i; j < 100005 && j > 1; j += i)
                isPrime[j] = 0;
        }
}

ull countN(ull x, ull y)
{
    ull res = 0;
    while (x % y == 0)
    {
        res++;
        x /= y;
    }
    return res;
}

void solve()
{
    ull n;
    cin >> n;
    ull maxi = countN(n, 2ULL);
    ull divi = 2;

    for (ull i = 3; i < 100005; i += 2)
        if (isPrime[i])
        {
            ull c = countN(n, i);
            if (c > maxi)
            {
                maxi = c;
                divi = i;
            }
        }
    if (maxi == 0)
    {
        cout << 1 << endl
             << n << endl;
        return;
    }
    cout << maxi << endl;
    for (int i = 1; i < maxi; i++)
    {
        cout << divi << " ";
        n /= divi;
    }
    cout << n << endl;
}

int main()
{
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    sieve();
    int tc;
    cin >> tc;
    while (tc--)
        solve();
}
