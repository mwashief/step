#include <bits/stdc++.h>
using namespace std;
vector<int> primes;
int ans[1000005];
int track[1000005];

void sieve()
{
    bitset<1005UL> visited;
    primes.push_back(2);
    for (int i = 3; i <= 1002; i += 2)
    {
        if (visited[i] == 0)
        {
            primes.push_back(i);
            for (int j = i * i; j <= 1002; j += 2 * i)
            {
                visited[j] = 1;
            }
        }
    }
}

int power(int n, int m)
{
    if (m == 0)
        return 1;
    int half = power(n, m / 2);
    half *= half;
    if (m & 1)
        half *= n;
    return half;
}

int main()
{
    sieve();
    unordered_map<int, int> factors;
    track[1] = ans[1] = 1;
    for (int i = 2; i <= 1000000; i++)
    {
        int temp = i;
        track[i] = track[i - 1];
        for (int j = 0; j < primes.size() && primes[j] <= temp; j++)
        {
            if (temp % primes[j] == 0)
            {
                int t = 0;
                while (temp % primes[j] == 0)
                {
                    t++;
                    temp /= primes[j];
                }
                if (primes[j] == 2)
                {
                    factors[2] = max(factors[2], t);
                }
                else if (primes[j] == 5)
                {
                    factors[5] = max(factors[5], t);
                }
                else
                {
                    int extra = t - factors[primes[j]];
                    if (extra > 0)
                    {
                        track[i] = (track[i] * power(primes[j], extra)) % 10;
                        factors[primes[j]] = t;
                    }
                }
            }
        }
        if (temp != 1)
        {
            if (factors[temp] == 0)
            {
                factors[temp] = 1;
                track[i] = (track[i] * temp) % 10;
            }
        }
        ans[i] = (track[i] * power(2, (factors[2] - factors[5]))) % 10;
    }
    int x;
    while (cin >> x && x)
    {
        cout << ans[x] << endl;
    }
}