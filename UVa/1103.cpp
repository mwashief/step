/*
    Washief Hossain Mugdho
    19 August 2020
    UVa 1103
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
int h, w;
vector<unordered_set<int>> connectedWhites;
bool graph[205][205];
bool visited[205][205];
int track[205][205];

char letters[] = {'W', 'A', 'K', 'J', 'S', 'D'};
int dr[] = {0, -1, 0, 1};
int dc[] = {1, 0, -1, 0};

inline bool isValid(int r, int c)
{
    return r >= 0 && c >= 0 && r < h && c < w;
}

void findBlack(int a, int b, int no)
{
    int r, c;
    stack<pair<int, int>> S;
    S.push(mp(a, b));
    while (S.size())
    {
        r = S.top().fr;
        c = S.top().sc;
        S.pop();
        visited[r][c] = 1;
        track[r][c] = no;
        for (int i = 0; i < 4; i++)
            if (graph[r + dr[i]][c + dc[i]] && isValid(r + dr[i], c + dc[i]) && !visited[r + dr[i]][c + dc[i]])
                S.push(mp(r + dr[i], c + dc[i]));
    }
}

void findWhite(int a, int b, int no)
{
    int r, c;
    stack<pair<int, int>> S;
    S.push(mp(a, b));
    while (S.size())
    {
        r = S.top().fr;
        c = S.top().sc;
        S.pop();
        visited[r][c] = 1;
        for (int i = 0; i < 4; i++)
            if (!isValid(r + dr[i], c + dc[i]))
                connectedWhites[0].insert(no);
            else if (graph[r + dr[i]][c + dc[i]])
                connectedWhites[track[r + dr[i]][c + dc[i]]].insert(no);
            else if (!graph[r + dr[i]][c + dc[i]] && !visited[r + dr[i]][c + dc[i]])
                S.push(mp(r + dr[i], c + dc[i]));
    }
}

int main()
{
    for (int tt = 1;; tt++)
    {
        cin >> h >> w;
        if (h == 0 && w == 0)
            break;
        connectedWhites.clear();
        ms(visited, 0);
        ms(track, 0);

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                char c;
                cin >> c;
                if (c >= 'a')
                    c = c - 'a' + 10;
                else
                    c = c - '0';
                for (int k = 0; k < 4; k++)
                    graph[i][4 * j + 3 - k] = (c >> k) & 1;
            }
        }

        w *= 4;
        int blacks = 1;
        connectedWhites.push_back(unordered_set<int>());
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                if (graph[i][j] && !visited[i][j])
                {
                    findBlack(i, j, blacks);
                    blacks++;
                    connectedWhites.push_back(unordered_set<int>());
                }
        int whites = 0;
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                if (!graph[i][j] && !visited[i][j])
                {
                    findWhite(i, j, whites);
                    whites++;
                }

        string s = "";
        for (int i = 1; i < connectedWhites.size(); i++)
        {
            for (auto it = connectedWhites[0].begin(); it != connectedWhites[0].end(); it++)
                connectedWhites[i].erase(*it);
            s.push_back(letters[connectedWhites[i].size()]);
        }
        sort(s.begin(), s.end());

        cout << "Case " << tt << ": " << s << endl;
    }
}
