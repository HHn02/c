#include <iostream>
#include <string>
#include <queue>
#include <utility>
#include <cstdio>
using namespace std;
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -1};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int a[8][8];
int fx, fy, flag = 0;
queue<pair<int, int> > sq;
bool judge(int x, int y)
{
    if (x == fx && y == fy)
        return true;
    return false;
}
void clear()
{
    while (!sq.empty())
        sq.pop();
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            a[i][j] = 0;
    flag = 0;
}
void bfs()
{
    while (!sq.empty() && flag == 0)
    {
        int tx, ty;
        tx = sq.front().first;
        ty = sq.front().second;
        sq.pop();
        for (int i = 0; i < 8; i++)
        {
            int nx = tx + dx[i];
            int ny = ty + dy[i];
            if (nx >= 0 && ny >= 0 && nx < 8 && ny < 8 && a[nx][ny] == 0)
            {
                a[nx][ny] = a[tx][ty] + 1;
                if (judge(nx, ny))
                {
                    flag = 1;
                    cout << a[nx][ny] - 1 << endl;
                    break;
                }
                sq.push(make_pair(nx, ny));
            }
        }
    }
}
int main()
{
    string s;
    while (cin >>s&&s!="i0i0")
    {
        int x, y;
        x = s[0] - 97;
        y = s[1] - 48 - 1;
        fx = s[2] - 97;
        fy = s[3] - 48 - 1;
        a[x][y] = 1;
        sq.push(make_pair(x, y));
        bfs();
        clear();
    }
    cout << '0' << endl;
    return 0;
}