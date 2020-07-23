#include <bits/stdc++.h>
using namespace std;
int beeperX[14];
int beeperY[14];

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> beeperX[0] >> beeperY[0];
        cin >> beeperX[0] >> beeperY[0];
        int n;
        cin >> n;
        int arr[n + 1] = {0};
        for (int i = 1; i <= n; i++)
        {
            cin >> beeperX[i] >> beeperY[i];
            arr[i] = i;
        }
        int result = INT32_MAX;
        do
        {
            int cost = 0;
            for (int i = 0; i <= n; i++)
                cost += abs(beeperX[arr[i]] - beeperX[arr[(i + n) % (n + 1)]]) + abs(beeperY[arr[i]] - beeperY[arr[(i + n) % (n + 1)]]);
            result = min(result, cost);
        } while (next_permutation(arr + 1, arr + n + 1));
        cout << "The shortest path has length " << result << endl;
    }
}