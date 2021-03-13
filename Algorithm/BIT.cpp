/*
    Washief Hossain Mugdho
    13 March 2021
    Algorithm BIT
*/

#ifndef DEBUG
#pragma GCC optimize("O2")
#endif

#include <bits/stdc++.h>
using namespace std;

class BIT
{
private:
    vector<int> ft;

public:
    int query(int x)
    {
        x++;
        int sum = 0;
        while (x > 0)
        {
            sum = sum + ft[x];
            x = x - (x & (-x));
        }
        return sum;
    }

    int query(int start, int end)
    {
        return query(end) - query(start - 1);
    }

    void update(int pos, int value)
    {
        pos++;
        while (pos <= ft.size())
        {
            ft[pos] += value;
            pos = pos + (pos & (-pos));
        }
    }

    BIT(vector<int> array)
    {
        int n = array.size();
        ft.assign(n + 1, 0);
        for (int i = 0; i < n; ++i)
            update(i, array[i]);
    }

    BIT(int n)
    {
        ft.assign(n + 1, 0);
    }
};

int main()
{
}
