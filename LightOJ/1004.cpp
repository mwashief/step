#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

ull arr[2][106], a;
int t, N;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> t;
    for (int k = 1; k <= t; k++)
    {
        cin >> N;
        memset(arr[1], 0, sizeof(arr[1]));
        memset(arr[0], 0, sizeof(arr[0]));

        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                cin >> a;
                arr[(i + 1) & 1][j] = max(arr[i & 1][j - 1], arr[i & 1][j]) + a;
            }
        }
        for (int i = N - 1; i >= 1; i--)
        {
            for (int j = 1; j <= i; j++)
            {
                cin >> a;
                arr[(i + 1) & 1][j] = max(arr[i & 1][j], arr[i & 1][j + 1]) + a;
            }
        }
        cout << "Case " << k << ": " << max(arr[N & 1][1], arr[(N + 1) & 1][1]) << "\n";
    }
}