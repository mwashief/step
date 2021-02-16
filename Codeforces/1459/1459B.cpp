/*
    Washief Hossain Mugdho
    20 December 2020
    Codeforces 1459B
*/

#ifndef DEBUG
#pragma GCC optimize("O2")
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

void run_tests()
{
    int n;
    cin >> n;
    int xpos = (n + 1) / 2 + 1;
    int ypos = (n / 2) + 1;
    if (xpos > ypos)
        swap(xpos, ypos);
    if (n & 1)
        cout << 2 * xpos * ypos << endl;
    else
        cout << xpos * ypos + 2 * xpos * (ypos - xpos) << endl;
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
    run_tests();
}
