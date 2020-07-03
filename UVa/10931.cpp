#include <bits/stdc++.h>
using namespace std;

int bin(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n & 1)
    {
        int result = 1 + bin(n / 2);
        cout << "1";
        return result;
    }
    int result = bin(n / 2);
    cout << "0";
    return result;
}

int main()
{
    int n;
    while (1)
    {
        cin >> n;
        if (!n)
            return 0;
        cout << "The parity of ";
        int result = bin(n);
        cout << " is " << result << " (mod 2)." << endl;
    }
}