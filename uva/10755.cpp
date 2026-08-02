#include <bits/stdc++.h>
using namespace std;

long long heap[25][25][25];
int A, B, C;

int main()
{
    int T;
    cin >> T;
    for (int tt = 1; tt <= T; tt++)
    {
        cin >> A >> B >> C;
        for (int i = 1; i <= A; i++)
            for (int j = 1; j <= B; j++)
                for (int k = 1; k <= C; k++)
                    cin >> heap[i][j][k];

        for (int i = 1; i <= A; i++)
            for (int j = 1; j <= B; j++)
                for (int k = 1; k <= C; k++)
                    heap[i][j][k] += heap[i][j - 1][k] + heap[i][j][k - 1] - heap[i][j - 1][k - 1];

        long long ans = LLONG_MIN;
        long long current = 0;
        for (int i = 1; i <= B; i++)
            for (int j = 1; j <= C; j++)
                for (int i2 = i; i2 <= B; i2++)
                    for (int j2 = j; j2 <= C; j2++)
                    {
                        current = 0;
                        for (int k = 1; k <= A; k++)
                        {
                            long long rect = heap[k][i2][j2] - heap[k][i - 1][j2] - heap[k][i2][j - 1] + heap[k][i - 1][j - 1];
                            current += rect;
                            ans = max(ans, current);
                            if (current < 0)
                                current = 0;
                        }
                    }
        cout << ans << endl;
        if (tt != T)
            cout << endl;
    }
}
