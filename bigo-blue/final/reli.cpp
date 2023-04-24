#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

int Set[50010];
int n;

void init(int N)
{
    for (int i = 1; i <= N; ++i)
        Set[i] = i;
}

int find(int x)
{
    if (x == Set[x])
        return x;
    return Set[x] = find(Set[x]);
}

void unionxy(int x, int y)
{
    x = find(x);
    y = find(y);

    if (x != y)
    {
        Set[x] = y;
        --n;
    }
}

int main()
{
    int N, M, test = 1;
    while (true)
    {
        cin >> N >> M;
        if (!N && !M)
        {
            break;
        }

        init(N);
        int x, y;
        n = N;

        while (M--)
        {
            scanf("%d%d", &x, &y);
            unionxy(x, y);
        }
        printf("Case %d: %d\n", test++, n);
    }
    return 0;
}
