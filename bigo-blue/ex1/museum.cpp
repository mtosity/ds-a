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

string readString()
{
    string s;
    getline(cin, s);
    return s;
}

int main()
{
    string s = readString();
    int n = s.size();

    if (n == 0)
    {
        cout << 0;
        return 0;
    }

    int count = 0;
    int last = 0;

    for (int i = 0; i < n; i++)
    {
        int x1 = last, x2 = s[i] - 'a';
        last = x2;

        if (x1 > x2)
        {
            int temp = x1;
            x1 = x2;
            x2 = temp;
        }

        int re1 = x2 - x1, re2 = (26 - x2) + x1;
        int result = re1 < re2 ? re1 : re2;

        count += result;
    }

    cout << count;

    return 0;
}