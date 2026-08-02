#include <bits/stdc++.h>
using namespace std;
vector<int> primes;

void sieve()
{
    bitset<15900UL> visited;
    primes.push_back(2);
    for (int i = 3; i <= 31630; i += 2)
    {
        if (visited[(i - 3) / 2] == 0)
        {
            primes.push_back(i);
            for (int j = i * i; j <= 31630; j += 2 * i)
            {
                visited[(j - 3) / 2] = 1;
            }
        }
    }
}

long long numDiv(int n)
{
    long long ans = 1;
    int l = lower_bound(primes.begin(), primes.end(), n) - primes.begin();
    for (int i = 0; i < primes.size() && primes[i] <= n; i++)
    {
        long long num = 1;
        while (n % primes[i] == 0)
        {
            n /= primes[i];
            num++;
        }
        ans *= num;
    }
    if (n != 1)
        ans *= 2;
    return ans;
}

int main(int argc, char const *argv[])
{
    sieve();
    int T;
    cin >> T;
    while (T--)
    {
        int L, U;
        int maximum = 0;
        int ans = 0;
        cin >> L >> U;
        for (int i = L; i <= U; i++)
        {
            int x = numDiv(i);
            if (x > maximum)
            {
                maximum = x;
                ans = i;
            }
        }
        cout << "Between " << L << " and " << U << ", " << ans << " has a maximum of " << maximum << " divisors." << endl;
    }
}
