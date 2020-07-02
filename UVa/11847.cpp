#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while (1)
    {
        cin >> n;
        if (!n)
            break;
        cout << floor(log2(n)) << endl;
    }
}