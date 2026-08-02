#include <bits/stdc++.h>
using namespace std;
int table[100][200];

int main()
{
    int T, n;
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                cin >> table[i][j];
                table[i][j + n] = table[i][j];
            }

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= 2 * n; j++)
                table[i][j] += table[i][j - 1];

        int ans = INT32_MIN;

        for (int i = 1; i <= n; i++)
        {
            for (int l = 0; l < n; l++)
            {
                int sum = 0;
                int negMax = INT32_MAX;
                int posMax = INT32_MIN;
                int curNeg = 0;
                int curPos = 0;
                for (int j = 1; j <= n; j++)
                {
                    int line = table[j][i + l] - table[j][i - 1];
                    sum += line;
                    curNeg += line;
                    curPos += line;
                    negMax = min(negMax, curNeg);
                    posMax = max(posMax, curPos);
                    if (curPos < 0)
                        curPos = 0;
                    if (curNeg > 0)
                        curNeg = 0;
                }
                ans = max(ans, max(posMax, sum - negMax == 0 ? INT32_MIN : sum - negMax));
            }
        }

        cout << ans << endl;
    }
}
