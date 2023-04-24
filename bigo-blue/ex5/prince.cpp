#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <limits.h>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

char mm[21][21];
int a[21][21];
int h;
int w;
int n_count = 0;

void move(int i, int j)
{

    if (i + 1 < h and !a[i + 1][j] and mm[i + 1][j] == '.')
    {
        a[i + 1][j] = 1;
        n_count++;
        move(i + 1, j);
    }

    if (i - 1 >= 0 and !a[i - 1][j] and mm[i - 1][j] == '.')
    {
        a[i - 1][j] = 1;
        n_count++;
        move(i - 1, j);
    }

    if (j + 1 < w and !a[i][j + 1] and mm[i][j + 1] == '.')
    {
        a[i][j + 1] = 1;
        n_count++;
        move(i, j + 1);
    }

    if (j - 1 >= 0 and !a[i][j - 1] and mm[i][j - 1] == '.')
    {
        a[i][j - 1] = 1;
        n_count++;
        move(i, j - 1);
    }
}

int main()
{
    int n_cases;
    cin >> n_cases;

    for (int k = 0; k < n_cases; k++)
    {
        cin >> w >> h;
        n_count = 0;
        int x, y;

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> mm[i][j];
                a[i][j] = false;
                if (mm[i][j] == '@')
                {
                    x = j;
                    y = i;
                    n_count = 1;
                }
            }
        }

        a[y][x] = true;
        move(y, x);
        printf("Case %d: %d\n", k + 1, n_count);
    }

    return 0;
}