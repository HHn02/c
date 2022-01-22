#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
#include <deque>
#include <set>
using namespace std;
const int Maxsize = 200;
char map_[Maxsize][Maxsize];
int fmap[Maxsize][Maxsize];
int dx[4]={-1, 0, 1, 0};
int dy[4]={0, 1, 0, -1};
int fx, fy, N, M;
int min_sec = 999;
void dfs(int x, int y, int sec)
{
    if (sec >= min_sec)
        return;
    if (x == fx && y == fy)
    {
        min_sec = sec;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < N && ny < M && map_[nx][ny] != '#' && fmap[nx][ny] == 0)
        {
            if (sec + 1 < min_sec || sec + 2 < min_sec)
            {
                fmap[nx][ny] = 1;
                if (map_[nx][ny] == 'x')
                    dfs(nx, ny, sec + 2);
                else
                    dfs(nx, ny, sec + 1);
                fmap[nx][ny] = 0;
            }
        }
    }
}
int main()
{
    cin >> N >> M;
    int x, y;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map_[i][j];
            if (map_[i][j] == 'r')
                x = i, y = j;
            if (map_[i][j] == 'a')
                fx = i, fy = j;
        }
    }
    dfs(x, y, 0);
    cout << min_sec << endl;
    return 0;
}