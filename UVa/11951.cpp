#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

long long area[105][105];

int main()
{
    int T, n, m;
    ull k;
    cin >> T;
    for (int tt = 1; tt <= T; tt++)
    {
        cin >> n >> m >> k;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                cin >> area[i][j];
                area[i][j] += area[i - 1][j] + area[i][j - 1] - area[i - 1][j - 1];
            }

        int plotSize = 0;
        int plotCost = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                for (int ii = i; ii <= n; ii++)
                    for (int jj = j; jj <= m; jj++)
                    {
                        int cost = area[ii][jj] - area[ii][j - 1] - area[i - 1][jj] + area[i - 1][j - 1];
                        if (cost > k)
                            break;

                        int plot = (ii - i + 1) * (jj - j + 1);
                        if (plot < plotSize)
                            continue;
                        else if (plot == plotSize)
                            plotCost = min(plotCost, cost);
                        else if (plot > plotSize)
                        {
                            plotSize = plot;
                            plotCost = cost;
                        }
                    }
        cout << "Case #" << tt << ": " << plotSize << " " << plotCost << endl;
    }
}
