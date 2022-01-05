/*
    Washief Hossain Mugdho
    09 October 2020
    Codeforces 674F
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
#define MOD 1000000007
using namespace std;

int main()
{
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    fastio;
    untie;
    int n, a = 0, b = 0, c = 0, qmarks = 0;
    char ch;
    cin >> n;
    int three[n + 1];
    three[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        three[i] = (1LL * three[i - 1] * 3) % MOD;
        cin >> ch;
        if (ch == 'a')
            a = (1LL * a + three[qmarks]) % MOD;
        else if (ch == 'b')
            b = (1LL * b + a) % MOD;
        else if (ch == 'c')
            c = (1LL * c + b) % MOD;
        else
        {
            c = (1LL * 3 * c + b) % MOD;
            b = (1LL * 3 * b + a) % MOD;
            a = (1LL * 3 * a + three[qmarks]) % MOD;
            qmarks++;
        }
    }
    cout << c << endl;
}
