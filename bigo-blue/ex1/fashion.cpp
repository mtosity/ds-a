#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, value;
    cin >> n;
    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        cin >> value;
        v.push_back(value);
    }

    if (n == 1 && v[0] == 1)
    {
        cout << "YES";
        return 0;
    }

    if (n == 1 && v[0] == 0)
    {
        cout << "NO";
        return 0;
    }

    int count = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == 0)
        {
            count += 1;
        }

        if (count > 1)
        {
            cout << "NO";
            return 0;
        }
    }

    if (count == 0)
    {
        cout << "NO";
        return 0;
    }

    cout << "YES";
    return 0;
}