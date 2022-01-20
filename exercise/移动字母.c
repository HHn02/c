#include "stdio.h"
#include "string.h"
char a[2][4];
char ch_1[7], ch_2[7];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int k = 0, Max_line = 0;
char vector[500][7];
int table[500];

void change(char *a, char *b)
{
    char t = *a;
    *a = *b;
    *b = t;
}
void add_ch2()
{
    int s = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            ch_2[s++] = a[i][j];
        }
    }
    ch_2[6] = 0;
}
int check_vector()
{
    for (int i = 0; i < Max_line; i++)
    {
        if (strcmp(vector[i], ch_2) == 0)
        {
            table[i]++;
            if (table[i] > 1)
                return 1;
        }
    }
    return 0;
}
void put_vector()
{
    for (int i = 0; i <= Max_line; i++)
    {
        if (strcmp(vector[i], ch_2) == 0)
            return;
    }
    strcpy(vector[Max_line++], ch_2);
}
void func(int row, int col, int ox, int oy)
{
    if (check_vector())
    {
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int nx = row + dx[i], ny = col + dy[i];
        if (nx >= 0 && ny >= 0 && nx < 2 && ny < 3 && (nx != ox || ny != oy))
        {
            change(&a[nx][ny], &a[row][col]);
            add_ch2();
            put_vector();
            func(nx, ny, row, col);
            change(&a[nx][ny], &a[row][col]);
        }
    }
}
void examine()
{
    for (int i = 0; i < Max_line; i++)
    {
        if (strcmp(vector[i], ch_1) == 0)
        {
            k = 1;
            break;
        }
    }
}
int main()
{
    int n = 0;
    int j = 0;
    strcpy(a[0], "ABC");
    strcpy(a[1], "DE*");
    func(1, 2, 1, 2);
    while ((n = getchar()) != EOF)
    {
        ch_1[j++] = n;
        if (j == 6)
        {
            ch_1[6] = 0;
            examine();
            printf("%d\n", k);
            k = 0;
            getchar();
            j=0;
        }
    }
    return 0;
}
