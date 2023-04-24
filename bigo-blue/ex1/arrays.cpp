#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T>
vector<T> readArray(int n)
{
    int value;
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
    int na, nb, ka, kb;
    cin >> na >> nb >> ka >> kb;

    vector<int> a = readArray<int>(na);
    vector<int> b = readArray<int>(nb);

    if (a[ka - 1] < b[nb - kb])
    {
        cout << "YES";
        return 0;
    }

    cout << "NO";
    return 0;
}