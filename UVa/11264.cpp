#include <bits/stdc++.h>
using namespace std;
int deno[1005];

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        unsigned long long sum = 0;
        int coins = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> deno[i];

        for (int i = 0; i < n - 1; i++)
        {
            if (sum + deno[i] < deno[i + 1])
            {
                sum += deno[i];
                coins++;
            }
        }
        cout << coins + 1 << endl;
    }
}
