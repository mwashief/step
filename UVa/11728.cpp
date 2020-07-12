#include <bits/stdc++.h>
using namespace std;
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
int ans[1005];

void gen()
{
    for (int i = 1; i <= 1004; i++)
    {
        int temp = i;
        int result = 1;
        for (int j = 0; j < 12 && primes[j] <= temp; j++)
        {
            if (temp % primes[j] == 0)
            {
                int k = 1;
                while (temp % primes[j] == 0)
                {
                    temp /= primes[j];
                    k *= primes[j];
                }
                result = result * (k * primes[j] - 1) / (primes[j] - 1);
            }
        }
        if (temp != 1)
        {
            result *= (temp + 1);
        }
        if (result < 1001 && result > 0)
            ans[result] = i;
    }
}

int main(int argc, char const *argv[])
{
    gen();
    for (int t = 1;; t++)
    {
        int x;
        cin >> x;
        if (x == 0)
            return 0;
        cout << "Case " << t << ": ";
        if (ans[x])
            cout << ans[x];
        else
            cout << -1;
        cout << endl;
    }
    return 0;
}
