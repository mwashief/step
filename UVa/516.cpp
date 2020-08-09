#include <bits/stdc++.h>
using namespace std;

int SPF[32770];

void genSPF()
{
    for (int i = 2; i < 32770; i += 2)
        SPF[i] = 2;
    for (int i = 1; i < 32770; i += 2)
        SPF[i] = i;
    for (int i = 3; i < 32770; i += 2)
    {
        if (SPF[i] == i)
            for (int j = i * i; j > i && j < 32770; j += 2 * i)
                SPF[j] = min(i, SPF[j]);
    }
}

int gen(int current, int base, int power)
{
    for (int i = 1; i <= power; i++)
        current *= base;
    return current;
}

int main()
{
    genSPF();
    string s;
    int base = 1, power = 0, num = 1;
    while (getline(cin, s))
    {
        num = 1;
        if (s == "0")
            return 0;
        istringstream ss(s);
        while (ss >> base >> power)
            num = gen(num, base, power);
        num--;
        map<int, int, greater<int>> factors;
        while (num != 1)
        {
            factors[SPF[num]]++;
            num /= SPF[num];
        }
        for (auto it = factors.begin(); it != factors.end(); it++)
        {
            if (it != factors.begin())
                cout << " ";
            cout << it->first << " " << it->second;
        }
        cout << endl;
    }
}
