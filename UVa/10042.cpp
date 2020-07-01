#include <bits/stdc++.h>
#define ui unsigned int
#define MAX 500000
using namespace std;

vector<ui> primes;
vector<ui> primeDigitSum;
void findPrimes()
{
    ui spf[MAX];
    primes.push_back(2);
    for (ui i = 3; i < MAX; i += 2)
        spf[i] = i;

    for (ui i = 3; i < MAX; i += 2)
    {
        if (spf[i] == i)
        {
            for (ui j = i * i; j < MAX; j += 2 * i)
            {
                spf[j] = i;
            }
            primes.push_back(i);
        }
    }
}

ui digitSum(ui n)
{
    ui result = 0;
    while (n > 0)
    {
        result += n % 10;
        n /= 10;
    }
    return result;
}

ui findFactorsDigitSum(ui n)
{
    ui sum = 0;
    ui factors = 0;
    for (int i = 0; primes[i] * primes[i] <= n; i++)
    {
        while (n % primes[i] == 0)
        {
            sum += digitSum(primes[i]);
            n /= primes[i];
            factors++;
        }
    }
    if (n != 1)
    {
        sum += digitSum(n);
        factors++;
    }
    if (factors < 2)
        return 0;
    return sum;
}

int main()
{
    findPrimes();
    for (int i = 0; i < primes.size(); i++)
        primeDigitSum.push_back(digitSum(primes[i]));
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        ui x;
        cin >> x;
        x++;
        while (digitSum(x) != findFactorsDigitSum(x))
            x++;
        cout << x << endl;
    }
}
