#include <bits/stdc++.h>
using namespace std;
int c, s, arr[20];
double sum;
int main()
{
    int setNo = 1;
    while (cin >> c >> s)
    {
        sum = 0;
        double imbalance = 0.0;
        for (int i = 0; i < s; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }
        sum /= 1.0 * c;
        sort(arr, arr + s);
        int sums[c] = {0};
        vector<int> cents[c];
        for (int i = s - 1; i >= s - c && i >= 0; i--)
        {
            sums[c - s + i] += arr[i];
            cents[c - s + i].push_back(arr[i]);
        }
        for (int i = 0; i < s - c && i >= 0; i++)
        {
            sums[i] += arr[s - c - 1 - i];
            cents[i].push_back(arr[s - c - 1 - i]);
        }
        cout << "Set #" << setNo << endl;
        for (int i = 0; i < c; i++)
        {
            cout << " " << i << ":";
            for (auto it = cents[i].begin(); it != cents[i].end(); it++)
                cout << " " << *it;
            cout << endl;
            imbalance = imbalance + abs(sums[i] - sum);
        }
        cout << fixed << setprecision(5) << "IMBALANCE = " << imbalance << endl
             << endl;
        setNo++;
    }
}
