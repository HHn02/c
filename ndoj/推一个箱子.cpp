#include <iostream>
#include <string>
#include <queue>
#include <utility>
using namespace std;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int steps;
struct stepAndman_pos
{
    int step;
    int manx;
    int many;
    int box_x;
    int box_y;
};
queue<pair<int, int> > sq2;
queue<stepAndman_pos> sq1;
int fmap1[7][7],fmap2[7][7];
int map[7][7];
int fx, fy, x, y, xx, yy;
void clear_queue_and_fmap()
{
    queue<pair<int ,int> > empty;
    swap(empty,sq2);
    for(int i=0;i<7;i++)
    for(int j=0;j<7;j++)
    fmap2[i][j]=0;
}
int get_man_pos(int i)
{
    if(i==0)return 2;
    if(i==1)return 3;
    if(i==2)return 0;
    if(i==3)return 1;
    return -1;
}
int bfs_man(int x,int y,int lx,int ly,int box_x,int box_y)
{
    if(x==lx&&y==ly)
        return 0;
    clear_queue_and_fmap();
    fmap2[x][y]=1;
    fmap2[box_x][box_y]=99;
    sq2.push(make_pair(x,y));
    while (!sq2.empty())
    {
        int tx = sq2.front().first;
        int ty = sq2.front().second;
        sq2.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = tx + dx[i], ny = ty + dy[i];
            if (nx >= 0 && ny >= 0 && nx < 7 && ny < 7 && fmap2[nx][ny] == 0&&map[nx][ny]==0)
            {
                fmap2[nx][ny]=fmap2[tx][ty]+1;
                if(nx==lx&&ny==ly)
                    return fmap2[tx][ty];
                sq2.push(make_pair(nx,ny));
            }
        }
    }
    return -1;
}
int bfs_box()
{
    fmap1[xx][yy]=1;
    while (!sq1.empty())
    {
        int tx = sq1.front().box_x;
        int ty = sq1.front().box_y;
        int x=sq1.front().manx,y=sq1.front().many;
        int tstep=sq1.front().step;
        sq1.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = tx + dx[i], ny = ty + dy[i];
            if (nx >= 0 && ny >= 0 && nx < 7 && ny < 7 && fmap1[nx][ny] == 0&&map[nx][ny]==0)
            {
                int n=get_man_pos(i);
                steps=bfs_man(x,y,tx+dx[n],ty+dy[n],tx,ty);
                if(steps!=-1)
                {
                    fmap1[nx][ny]=fmap1[tx][ty]+1;
                    if(nx==fx&&ny==fy)
                    {
                        return tstep+fmap1[tx][ty];
                    }
                    stepAndman_pos s;
                    s.step=steps+tstep;
                    s.manx=tx;s.many=ty;
                    s.box_x=nx;s.box_y=ny;
                    sq1.push(s);
                }
            }
        }   
    }
    return 0;
}
int main()
{
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
        {
            int n;
            cin >> n;
            if(n==1)map[i][j]=n;
            if (n == 2)
            {
                xx = i;
                yy = j;
            }
            else if (n == 3)
            {
                fx = i;
                fy = j;
            }
            else if (n == 4)
            {
                x = i;
                y = j;
            }
        }
    stepAndman_pos s;
    s.manx=x;s.many=y;s.step=0;
    s.box_x=xx;s.box_y=yy;
    sq1.push(s);
    //int step = bfs_man(2,3,2,1);
    //cout << step <<endl;
    int ans=bfs_box();
    if(ans)
    cout << ans << endl;
    else
    cout << "-1" << endl;
    return 0;
}
