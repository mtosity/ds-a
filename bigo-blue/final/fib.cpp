#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
    long long int n, test, i_test = 1;
    cin >> test;
    while (test--)
    {
        cin >> n;
        long long int sq = ceil(sqrt(n));
        long long int r = sq * sq - n;
        long long int x, y;
        if (r < sq)
        {
            y = r + 1;
            x = sq;
        }
        else
        {
            x = 2 * sq - r - 1;
            y = sq;
        }
        if (sq & 1)
            swap(x, y);
        printf("Case %lld: %lld %lld\n", i_test, x, y);
        i_test++;
    }
    return 0;
}
