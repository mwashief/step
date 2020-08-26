/*
    Washief Hossain Mugdho
    26 August 2020
    UVa 11624
*/

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define fastio ios_base::sync_with_stdio(0)
#define untie cin.tie(0)
#define ms(a, b) memset(a, b, sizeof a)
using namespace std;
char maze[1004][1004];
int R, C;
int dr[] = {0, -1, 0, 1};
int dc[] = {1, 0, -1, 0};

class Node
{
public:
    int r, c, step;
    bool what;
    Node(int r, int c, char what)
    {
        step = 0;
        this->r = r;
        this->c = c;
        this->what = what == 'J' ? 0 : 1;
    }

    Node(int r, int c, Node &x)
    {
        this->step = x.step + 1;
        this->r = r;
        this->c = c;
        this->what = x.what;
    }

    char getChar()
    {
        return what == 0 ? 'J' : 'F';
    }

    char getCurrentCondition()
    {
        return maze[r][c];
    }
};

bool isValid(int r, int c)
{
    return r >= 0 && c >= 0 && r < R && c < C;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> R >> C;
        deque<Node> Q;
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
            {
                cin >> maze[i][j];
                if (maze[i][j] == 'F')
                    Q.push_back(Node(i, j, maze[i][j]));
                if (maze[i][j] == 'J')
                    Q.push_front(Node(i, j, maze[i][j]));
            }
        bool found = false;
        while (!Q.empty())
        {
            Node node = Q.front();

            Q.pop_front();
            if (node.getCurrentCondition() != node.getChar())
                continue;
            for (int i = 0; i < 4; i++)
            {
                int nr = node.r + dr[i];
                int nc = node.c + dc[i];
                if (!isValid(nr, nc))
                {
                    if (node.getChar() == 'J')
                    {
                        cout << node.step + 1 << endl;
                        Q = deque<Node>();
                        found = true;
                        break;
                    }
                    else
                        continue;
                }
                else if (maze[nr][nc] == '#' || maze[nr][nc] == 'F')
                    continue;

                else if (maze[nr][nc] == 'J')
                {
                    if (node.getChar() == 'J')
                        continue;
                    else
                    {
                        maze[nr][nc] = 'F';
                        Q.push_back(Node(nr, nc, node));
                    }
                }
                else
                {
                    Q.push_back(Node(nr, nc, node));
                    maze[nr][nc] = node.getChar();
                }
            }
        }
        if (!found)
            cout << "IMPOSSIBLE" << endl;
    }
}
