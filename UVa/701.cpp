#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

int main()
{
    ull n;
    while (cin >> n)
    {
        ull digits = 0;
        ull temp = n;
        while (n > 0)
        {
            digits++;
            n /= 10;
        }
        for (ull i = digits + 1;; i++)
        {
            double l = floor(log2(temp + 1) + i * log2(10));
            if (l > log2(temp) + i * log2(10))
            {
                cout << l << endl;
                break;
            }
        }
    }
}