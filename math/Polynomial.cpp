/*
*   Halim Sir
*   Page 193
*   Exercise 5.2.5
*/

#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

ull power(ull a, ull n)
{
    if (n == 1)
        return a;
    ull root = power(a, n / 2);
    if (n & 1)
    {
        return root * root * a;
    }
    return root * root;
}

int main()
{
    ull a, n;
    cin >> a >> n;
    ull result = power(a, n + 1);
    result = n * result - (result - 1) / (a - 1) + 1;
    cout << result / (a - 1);
}
