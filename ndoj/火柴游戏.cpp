#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
char map_[3][4];
int k = 0;
bool is_legal(char ch, int x, int y)
{
    if (ch == '1')
    {
        for (int i = x + 1; i < 3; i++)
        {
            if (map_[i][y] == '1')
                return false;
            if (map_[i][y] == '-')
                break;
        }
        for (int i = x - 1; i >= 0; i--)
        {
            if (map_[i][y] == '1')
                return false;
            if (map_[i][y] == '-')
                break;
        }
    }
    else
    {
        for (int i = y + 1; i < 4; i++)
        {
            if (map_[x][i] == '-')
                return false;
            if (map_[x][i] == '1')
                break;
        }
        for (int i = y - 1; i >= 0; i--)
        {
            if (map_[x][i] == '-')
                return false;
            if (map_[x][i] == '1')
                break;
        }
    }
    return true;
}
bool dfs(char ch, int x, int y)
{
    string s1, s2;
    if (ch == '-')
    {
        for (int i = 0; i < 4; i++)
        {
            if (map_[x][i] != '0')
                s1.push_back(map_[x][i]);
        }
        int n1 = s1.find("--");
        if (n1 != -1)
            return true;
    }
    else
    {
        for (int i = 0; i < 3; i++)
        {
            if (map_[i][y] != '0')
                s2.push_back(map_[i][y]);
        }
        int n2 = s2.find("11");
        if (n2 != -1)
            return true;
    }

    //if(!is_legal(ch,x,y))return true;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (map_[i][j] == '0')
            {
                map_[i][j] = '-';
                if (dfs('-', i, j) == false)
                {
                    map_[i][j] = '0';
                    return true;
                }
                map_[i][j] = '1';
                if (dfs('1', i, j) == false)
                {
                    map_[i][j] = '0';
                    return true;
                }
                map_[i][j] = '0';
            }
        }
    }
    return false;
}
bool func()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (map_[i][j] == '0')
            {
                map_[i][j] = '-';
                if (dfs('-', i, j) == false)
                {
                    map_[i][j] = '0';
                    return true;
                }
                map_[i][j] = '1';
                if (dfs('1', i, j) == false)
                {
                    map_[i][j] = '0';
                    return true;
                }
                map_[i][j] = '0';
            }
        }
    }
    return false;
}
int main()
{
    int i = 0, j = 0;
    string s;
    while (getline(cin, s))
    {
        for (j = 0; j < 4; j++)
            map_[i][j] = s[j];
        i++;
        if (i % 3 == 0 && i != 0)
        {
            if (func())
                cout << '1' << endl;
            else
                cout << '0' << endl;
            k = 0;
            i = 0;
        }
    }
    return 0;
}