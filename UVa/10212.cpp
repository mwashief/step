#include <bits/stdc++.h>
#define ull long long
using namespace std;

ull pow2(ull m)
{
    if (m == 0)
        return 1;
    ull result = pow2(m / 2);
    result *= result;
    if (m & 1)
        result *= 2;
    return result % 10;
}

ull pow5(ull m)
{
    if (m == 0)
        return 1;
    ull result = pow5(m / 2);
    result *= result;
    if (m & 1)
        result *= 5;
    return result % 10;
}

int main()
{
    ull m, n;
    while (cin >> n >> m)
    {
        ull ans = 1;
        ull twos = 0;
        ull fives = 0;
        for (ull i = n - m + 1; i <= n; i++)
        {
            ull temp = i;
            while (temp % 2 == 0)
            {
                twos++;
                temp /= 2;
            }
            while (temp % 5 == 0)
            {
                fives++;
                temp /= 5;
            }
            ans = (ans * temp) % 10;
        }
        if (twos > fives)
            ans = (ans * pow2(twos - fives)) % 10;
        else
            ans = (ans * pow5(fives - twos)) % 10;
        cout << ans << endl;
    }
}