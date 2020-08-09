#include <bits/stdc++.h>
using namespace std;
int arr[105][105];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int x;
            cin >> x;
            arr[i][j] = x + arr[i][j - 1];
        }
    }
    int ans = 0;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            sum = 0;
            for (int k = 0; k < n; k++)
            {
                int value = arr[k][j] - arr[k][i - 1];
                sum += value;
                if (sum <= 0)
                    sum = 0;
                else
                    ans = max(sum, ans);
            }
        }
    }
    cout << ans << endl;
}
