#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int ranks[N];
int enemy[N][N];
vector<int> friendl(N);
void init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        friendl[i] = i;
        ranks[i] = 1;
    }
}
int find(int x)
{
    if (friendl[x] == x)
        return x;
    return friendl[x] = find(friendl[x]);
}

bool unions(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return false;
    if (ranks[x] > ranks[y])
        friendl[y] = x;
    else
    {
        if (ranks[x] == ranks[y])
            ranks[y]++;
        friendl[x] = y;
    }
    return true;
}

int main()
{
    int n, m, k;
    int m1, m2, m3;
    cin >> n >> m >> k;
    init(n);
    for (int i = 0; i < m; i++)
    {
        cin >> m1 >> m2 >> m3;
        if (m3 == 1)
        {
            unions(m1, m2);
        }
        else
        {
            enemy[m1][m2] = 1;
            enemy[m2][m1] = 1;
        }
    }
    for (int i = 0; i < k; i++)
    {
        cin >> m1 >> m2;
        if (find(m1) == find(m2) && enemy[m1][m2] == 0)
            cout << "No problem" << endl;
        if (find(m1) != find(m2) && enemy[m1][m2] == 0)
            cout << "OK" << endl;
        if (find(m1) == find(m2) && enemy[m1][m2] != 0)
            cout << "OK but..." << endl;
        if (find(m1) != find(m2) && enemy[m1][m2] != 0)
            cout << "No way" << endl;
    }
    return 0;
}