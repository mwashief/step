#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, w;
    double l, dx, xStart, xFinish;
    while (cin >> n >> l >> w)
    {
        vector<pair<int, int>> sprinklers;
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            sprinklers.push_back(make_pair(x, y));
        }
        sort(sprinklers.begin(), sprinklers.end());
        vector<double> start;
        vector<double> finish;
        for (int i = 0; i < n; i++)
        {
            if ((double)sprinklers[i].second < (double)w / 2.0)
                continue;

            dx = sqrt((double)sprinklers[i].second * sprinklers[i].second - (1.0 * w / 2.0) * (1.0 * w / 2.0));
            xStart = max(0.0, (double)sprinklers[i].first - dx);
            xFinish = (double)sprinklers[i].first + dx;
            if (start.size() == 0)
            {
                start.push_back(xStart);
                finish.push_back(xFinish);
                continue;
            }

            if (xStart - finish[finish.size() - 1] > .000001 || finish[finish.size() - 1] - xFinish > -.000001 || (xFinish - xStart < .000001 && xFinish - xStart > -.000001))
                continue;

            while (start.size() > 0 && start[start.size() - 1] - xStart > -.000001)
            {
                start.pop_back();
                finish.pop_back();
            }
            if (finish.size() > 0)
                xStart = finish[finish.size() - 1];
            start.push_back(xStart);
            finish.push_back(xFinish);
        }

        if (start.size() == 0 || start[0] > 0.000001 || l - finish[finish.size() - 1] > .000001)
            cout << "-1" << endl;
        else
        {
            for (int i = 0; i < finish.size(); i++)
            {
                if (finish[i] >= l)
                {
                    cout << i + 1 << endl;
                    break;
                }
            }
        }
    }
}