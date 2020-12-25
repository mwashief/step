#pragma GCC optimize("O3")
#include <bits/stdc++.h>
typedef unsigned long long ull;
using namespace std;
#define mx 32

ull memo1[mx][mx];
ull memo2[mx][mx];

string s1, s2;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++)
    {
        memset(memo1, 0, sizeof(memo1));
        memset(memo2, 0, sizeof(memo2));
        cin >> s1 >> s2;
        for (int i = 0; i <= s1.size(); i++)
            memo1[i][0] = i, memo2[i][0] = 1;
        for (int i = 0; i <= s2.size(); i++)
            memo1[0][i] = i, memo2[0][i] = 1;
        for (int i = 0; i < s1.size(); i++)
        {
            for (int j = 0; j < s2.size(); j++)
            {
                if (s1[i] == s2[j])
                {
                    memo1[i + 1][j + 1] = memo1[i][j] + 1;
                    memo2[i + 1][j + 1] = memo2[i][j];
                }
                else
                {
                    memo1[i + 1][j + 1] = 1 + min(memo1[i + 1][j], memo1[i][j + 1]);
                    if (memo1[i][j + 1] <= memo1[i + 1][j])
                        memo2[i + 1][j + 1] = memo2[i][j + 1];
                    if (memo1[i + 1][j] <= memo1[i][j + 1])
                        memo2[i + 1][j + 1] += memo2[i + 1][j];
                }
            }
        }
        cout << "Case " << t << ": " << memo1[s1.size()][s2.size()] << " " << memo2[s1.size()][s2.size()] << "\n";
    }
}
