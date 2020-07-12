#include <bits/stdc++.h>
using namespace std;
vector<int> primes;
int M[1000005] = {0, 1};
int mu[1000005] = {0, 1};

void sieve()
{
    bitset<510UL> visited;
    primes.push_back(2);
    for (int i = 3; i <= 1005; i += 2)
    {
        if (visited[(i - 3) / 2] == 0)
        {
            primes.push_back(i);
            for (int j = i * i; j > i && j <= 1005; j += 2 * i)
            {
                visited[(j - 3) / 2] = 1;
            }
        }
    }

    for (int n = 2; n <= 1000000; n++)
    {
        int temp = n;
        bool squareFree = true;
        int factors = 0;
        for (int i = 0; i < primes.size() && i <= temp; i++)
        {
            int c = 0;
            while (temp % primes[i] == 0)
            {
                c++;
                factors++;
                temp /= primes[i];
            }
            if (c > 1)
            {
                squareFree = false;
                break;
            }
        }
        if (temp != 1)
            factors++;
        if (squareFree)
        {
            if (factors & 1)
                mu[n] = -1;
            else
                mu[n] = 1;
        }
        else
            mu[n] = 0;
        M[n] = M[n - 1] + mu[n];
    }
}

int main(int argc, char const *argv[])
{
    sieve();
    int x;
    while (cin >> x && x)
    {
        cout << setw(8) << x << setw(8) << mu[x] << setw(8) << M[x] << endl;
    }
    return 0;
}
