#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T>
vector<T> readArray()
{
    int n, value;
    cin >> n;
    vector<T> v;

    for (int i = 0; i < n; i++)
    {
        cin >> value;
        v.push_back(value);
    }

    return v;
}

int main()
{
    vector<int> a = readArray<int>();
    int n = a.size();
    if (n == 0)
    {
        cout << 15;
        return 0;
    }

    if (n == 1)
    {
        if (a[0] >= 15)
        {
            cout << 15;
            return 0;
        }
        else
        {
            cout << a[0] + 15;
            return 0;
        }
    }

    int base = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] - base > 15)
        {
            cout << base + 15;
            return 0;
        }
        else
        {
            base = a[i];
        }
    }

    cout << (base + 15 > 90 ? 90 : base + 15);
    return 0;
}