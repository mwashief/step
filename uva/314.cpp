/*
    Washief Hossain Mugdho
    27 August 2020
    UVa 314
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

int visited[53][53][4];
int n, m, s1, s2, e1, e2;
map<string, int> toNum = {{"east", 0}, {"north", 1}, {"west", 2}, {"south", 3}};
string s;
int dr[] = {0, -1, 0, 1};
int dc[] = {1, 0, -1, 0};

class Position
{
public:
    int r, c, dir, step;

    Position(int r, int c, int dir)
    {
        this->r = r;
        this->c = c;
        this->dir = dir % 4;
        this->step = 0;
    }

    Position(const Position &p)
    {
        this->r = p.r;
        this->c = p.c;
        this->dir = p.dir;
        this->step = p.step;
    }

    bool isBlock()
    {
        return r <= 0 || c <= 0 || r >= n || c >= m || visited[r][c][dir] == 1;
    }

    bool isEmpty()
    {
        return r > 0 && c > 0 && r < n && c < m && visited[r][c][dir] == 0;
    }

    Position moveLeft()
    {
        Position temp(*this);
        temp.dir = (temp.dir + 1) % 4;
        temp.step++;
        return temp;
    }

    Position moveRight()
    {
        Position temp(*this);
        temp.dir = (temp.dir + 3) % 4;
        temp.step++;
        return temp;
    }

    Position go(int x)
    {
        Position temp(*this);
        temp.r = temp.r + x * dr[dir];
        temp.c = temp.c + x * dc[dir];
        temp.step++;
        return temp;
    }

    vector<Position> generate()
    {
        vector<Position> res;
        if (this->moveLeft().isEmpty())
            res.pb(this->moveLeft());
        if (this->moveRight().isEmpty())
            res.pb(this->moveRight());

        for (int i = 1; i <= 3; i++)
            if (this->go(i).isBlock())
                break;
            else if (this->go(i).isEmpty())
                res.pb(this->go(i));
        return res;
    }
};

void bfs()
{
    bool found = false;
    queue<Position> Q;
    Q.push(Position(s1, s2, toNum[s]));
    visited[s1][s2][toNum[s]] = 2;
    while (!Q.empty())
    {
        Position x = Q.front();
        if (x.r == e1 && x.c == e2)
        {
            cout << x.step << endl;
            found = true;
            break;
        }
        Q.pop();
        vector<Position> temp = x.generate();
        for (int i = 0; i < temp.size(); i++)
        {
            Position p = temp[i];
            visited[p.r][p.c][p.dir] = 2;
            Q.push(p);
        }
    }
    if (!found)
        cout << "-1" << endl;
}

int main()
{
    while (cin >> n >> m && !(n == 0 && m == 0))
    {
        ms(visited, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int x;
                cin >> x;
                if (x)
                {
                    for (int k = 0; k < 4; k++)
                    {
                        visited[i][j][k] = 1;
                        visited[i + 1][j][k] = 1;
                        visited[i][j + 1][k] = 1;
                        visited[i + 1][j + 1][k] = 1;
                    }
                }
            }
        }
        cin >> s1 >> s2 >> e1 >> e2 >> s;
        if (Position(s1, s2, 0).isBlock() || Position(e1, e2, 0).isBlock())
            cout << "-1" << endl;
        else
            bfs();
    }
}
