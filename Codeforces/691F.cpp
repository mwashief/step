/*
    Washief Hossain Mugdho
    20 December 2020
    Codeforces 691F
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

    int tc;
    cin >> tc;
    while (tc--)
    {
        string s;
        cin >> s;
        vector<int> bam(2 * s.size() + 1, 0);
        vector<int> dan(2 * s.size() + 1, 0);
        int pos = s.size();
        for (auto c : s)
        {
            if (c == '0')
                dan[pos++]++;
            else
                bam[pos--]++;
        }
        pos = s.size();
        while (bam[pos] | dan[pos])
        {
            if (dan[pos] && (!bam[pos] || bam[pos + 1]))
            {
                dan[pos++]--;
                cout << 0;
            }
            else
            {
                bam[pos--]--;
                cout << 1;
            }
        }
        cout << endl;
    }
}
