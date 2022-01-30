#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <utility>
#include <deque>
using namespace std;
const int MAX = 1e3;
const int INTMAX = 32767;
int vexnum, edgenum;
int Graph[MAX][MAX];
int a[MAX];
int dis[MAX];
int T[MAX];
int cnt = 1;
queue<int> pq;
int find_min()
{
    int min = 999999;
    int index;
    for (int i = 1; i <= vexnum; i++)
    {
        if (dis[i] < min && a[i] == 0)
        {
            min = dis[i];
            index = i;
        }
    }
    return index; //返回哪个顶点
}
int main()
{
    cin >> vexnum >> edgenum;
    fill(Graph[0], Graph[0] + MAX * MAX, INTMAX);
    for (int i = 0; i < edgenum; i++)
    {
        int start, end, w;
        cin >> start >> end >> w;
        Graph[start][end] = w;
    }
    for (int arrow = 1; arrow <= vexnum; arrow++) //初始化dis和a数组
    {                                             //确定v1和其他点最短距离
        dis[arrow] = Graph[1][arrow];
    }
    dis[1] = 0;
    a[1] = 1;
    while (cnt < vexnum)
    {
        int index = find_min();
        a[index] = 1;
        cnt++;
        for (int arrow = 1; arrow <= vexnum; arrow++) //找出度
        {
            if (Graph[index][arrow] != INTMAX)
                pq.push(arrow);
        }
        while (!pq.empty()) //更新dis数组
        {
            int i = pq.front(); //头点
            pq.pop();
            if (dis[index] + Graph[index][i] < dis[i])
                dis[i] = dis[index] + Graph[index][i];
            int num=pq.size();
        }
    }
    for (int i = 1; i <= vexnum; i++)
    {
        cout << dis[i] << ' ' ;
    }
    cout << endl;
    return 0;
}