#include <iostream>
using namespace std;
const int Maxsize = 100000;
struct Familys
{
    char sex;
    int fid;
    int mid;
    Familys()
    {
        fid = -1;
        mid = -1;
    }
};
Familys family[Maxsize];
int pre[Maxsize];
int ranks[Maxsize];
void init()
{
    for (int i = 0; i < Maxsize; i++)
    {
        pre[i] = i;
        ranks[i] = 1;
    }
}
int Find(int x)
{
    if (pre[x] == x)
        return x;
    return pre[x] = Find(pre[x]);
}
bool isSame(int x, int y)
{
    return Find(x) == Find(y);
}
void merge(int x, int y)
{
    if (y == -1)
        return;
    x = Find(x);
    y = Find(y);
    if (ranks[x] > ranks[y])
        pre[y] = x;
    else
    {
        if (ranks[x] == ranks[y])
            ranks[y]++;
        pre[x] = y;
    }
    return;
}
bool dfs(int a, int b, int age)
{
    if (!(a != -1 && b != -1))
        return true;
    if (age > 5)
        return true;
    if (a == b)
    {
        if (age > 5)
            return true;
        return false;
    }
    else
        return dfs(family[a].fid, family[b].fid, age + 1) && dfs(family[a].mid, family[b].mid, age + 1) && dfs(family[a].fid, family[b].mid, age + 1) && dfs(family[a].mid, family[b].fid, age + 1);
}
int main()
{
    int N, id, fid, mid;
    char ch;
    init();
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> id >> ch >> fid >> mid;
        family[id].sex = ch;
        family[id].fid = fid;
        family[id].mid = mid;
        merge(id, fid);
        merge(id, mid);
        if (fid != -1)
            family[fid].sex = 'M';
        if (mid != -1)
            family[mid].sex = 'F';
    }
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int id1, id2;
        cin >> id1 >> id2;
        if (family[id1].sex == family[id2].sex)
        {
            cout << "Never Mind";
        if (i != N - 1)
            cout << endl;
        }
        else
        {
            if (!isSame(id1, id2))
            {
                cout << "Yes";
                if (i != N - 1)
                    cout << endl;
            }
            else if (dfs(id1, id2, 1))
            {
                cout << "Yes";
                if (i != N - 1)
                    cout << endl;
            }
            else
            {
                cout << "No";
                if (i != N - 1)
                    cout << endl;
            }
        }
    }
    return 0;
}