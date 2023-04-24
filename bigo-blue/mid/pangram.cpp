#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <limits.h>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>
#include <cctype>
#include <string>

using namespace std;

#define ll long long

int main()
{
    int n;
    string s;
    char leter = 'A';
    cin >> n;
    cin >> s;
    for (int k = 0; k < n; k++)
    {
        s[k] = toupper(s[k]);
    }

    if (n >= 26)
    {
        for (int i = 0; i < 26; i++)
        {
            if (s.find(leter) != -1)
            {
                leter++;
            }
            else
            {
                cout << "NO";
                return 0;
            }
        }
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}
