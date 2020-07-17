#include <bits/stdc++.h>
using namespace std;
int grid[4][4];

bool check(int player)
{
    for (int i = 0; i < 4; i++)
    {
        bool vertical = true, horizontal = true;
        for (int j = 0; j < 4; j++)
        {
            vertical &= grid[j][i] == player ? true : false;

            horizontal &= grid[i][j] == player ? true : false;
        }
        if (vertical || horizontal)
            return true;
    }

    bool forward = true, backward = true;
    for (int j = 0; j < 4; j++)
    {
        backward &= grid[j][j] == player ? true : false;

        forward &= grid[3 - j][j] == player ? true : false;
    }
    if (forward || backward)
        return true;
    return false;
}

bool isEnd()
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (grid[i][j] == -1)
                return false;
    return true;
}

bool dfs(int curPlayer)
{
    if (curPlayer == 0)
    {
        if (check(1))
            return true;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (grid[i][j] == -1)
                {
                    grid[i][j] = 0;
                    bool result = dfs(1);
                    grid[i][j] = -1;
                    if (!result)
                        return false;
                }
            }
        }
        return true;
    }
    if (isEnd())
        return false;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (grid[i][j] == -1)
            {
                grid[i][j] = 1;
                bool result = dfs(0);
                grid[i][j] = -1;
                if (result)
                    return true;
            }
        }
    }
    return false;
}

int main()
{
    string s;
    while (getline(cin, s))
    {
        if (s == "$")
            break;
        for (int i = 0; i < 4; i++)
        {
            getline(cin, s);
            for (int j = 0; j < 4; j++)
            {
                grid[i][j] = s[j] == '.' ? -1 : (s[j] == 'x' ? 1 : 0);
            }
        }
        int x = -1, y = -1;
        bool goOn = true;
        for (int i = 0; i < 4 && goOn; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (grid[i][j] == -1)
                {
                    grid[i][j] = 1;
                    bool result = dfs(0);
                    grid[i][j] = -1;
                    if (result)
                    {
                        x = i;
                        y = j;
                        goOn = false;
                        break;
                    }
                }
            }
        }
        if (goOn)
            cout << "#####" << endl;
        else
            cout << "(" << x << "," << y << ")" << endl;
    }
}