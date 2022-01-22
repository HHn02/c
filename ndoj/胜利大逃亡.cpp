#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
#include <deque>
#include <set>
#include <cstdio>
using namespace std;
const int Maxsize = 50;
int map_[Maxsize][Maxsize][Maxsize];
bool fmap[Maxsize][Maxsize][Maxsize];
int time_map[Maxsize][Maxsize][Maxsize];
int dz[6] = {0, 0, 0, 0, 1, -1};
int dx[6] = {-1, 0, 1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int T, fz, fx, fy, flag = 0;
int a, b, c;
struct pos
{
    int z;
    int x;
    int y;
};
queue<pos> sq;
void bfs()
{
    while (!flag && !sq.empty())
    {
        int tz, tx, ty;
        tz = sq.front().z;
        tx = sq.front().x;
        ty = sq.front().y;
        sq.pop();
        for (int i = 0; i < 6; i++)
        {
            int nz = tz + dz[i], nx = tx + dx[i], ny = ty + dy[i];
            if (nz >= 0 && nx >= 0 && ny >= 0 && nz < a && nx < b && ny < c && map_[nz][nx][ny] == 0 && fmap[nz][nx][ny])
            {
                time_map[nz][nx][ny] = time_map[tz][tx][ty] + 1;
                fmap[nz][nx][ny] = false;
                if (time_map[nz][nx][ny] > T)
                {
                    flag = 2;
                    break;
                }
                if (nz == fz && nx == fx && ny == fy && time_map[nz][nx][ny] <= T)
                {
                    flag = 1;
                    cout << time_map[nz][nx][ny]  << endl;
                    break;
                }
                pos p;
                p.z = nz;
                p.x = nx;
                p.y = ny;
                sq.push(p);
            }
        }
    }
}
int main()
{
    cin >> a >> b >> c >> T;
    fz = a - 1, fx = b - 1, fy = c - 1;
    for (int z = 0; z < a; z++)
    {
        for (int i = 0; i < b; i++)
        {
            for (int j = 0; j < c; j++)
            {
                scanf("%d", &map_[z][i][j]);
                fmap[z][i][j]=true;
            }
        }
    }
    fmap[0][0][0] = false;
    pos p;
    p.z = 0;
    p.x = 0;
    p.y = 0;
    sq.push(p);
    bfs();
    if (flag == 2||!flag)
        cout << "-1" << endl;
    return 0;
}