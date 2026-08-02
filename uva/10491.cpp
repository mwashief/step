#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cows, cars, show;
    cout << fixed;
    cout << setprecision(5);
    while (cin >> cows >> cars >> show)
    {
        cout << (double)cars * (cows + cars - 1) / (cows + cars) / (cows + cars - show - 1) << endl;
    }
}
